/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   20 Jan 2018
*/

#include <string>
#include <vector>
#include <sstream>
#include <operations/BankCashWithdrawal.hpp>

#include "BankOperation.hpp"
#include "Logger.hpp"
#include "Worker.hpp"
#include "Client.hpp"


std::vector<std::string> split(const std::string &message) {
    std::stringstream stream;
    stream << message;

    std::string line;
    std::vector<std::string> result;
    while (std::getline(stream, line, ' ')) {
        result.push_back(std::move(line));
    }

    return result;
}

std::string join(const std::vector<std::string> &words, int form = -1, int to = -1) {
    std::string result;

    if (form == -1) form = 0;
    if (to == -1) to = static_cast<int>(words.size());

    for (auto i = form; i < to; i++) {
        result += " " + words[i];
    }

    return result;
}

Worker::Worker(BaseConnection &connection) : connection(connection) {
    id = std::to_string(rand());
}

void Worker::operator()() {
    auto query = readQuery();
    auto parsed = parse(query);
    auto operation = chooseOperation(parsed.second);
    if (operation == nullptr) return;
    auto result = operation->run();
    sendResponse(result);
}

std::unique_ptr<BankOperation> Worker::chooseOperation(const std::string &command) {
    auto splitCommand = split(command);
    if (splitCommand.empty()) {
        return nullptr;
    }
    if (splitCommand[0] == "get") {
        std::string last = join(splitCommand, 1);
        return std::make_unique<BankCashWithdrawal>(last);
    }

    return nullptr;
}

std::pair<Client, std::string> Worker::parse(const std::string &query) {
    std::stringstream sstream;
    sstream << query;

    std::string cardNumber;
    std::string command;
    short pin;
    sstream >> cardNumber >> pin >> command;

    return std::make_pair(Client(cardNumber, pin), std::move(command));
}

std::string Worker::readQuery() {
    std::vector<char> buffer(1024);
    size_t size = buffer.size();

    if (!connection.read(buffer.data(), size)) {
        Logger::log() << id + " read failed";
        return "";
    }
    auto query = std::string(buffer.begin(), buffer.begin() + size);
    Logger::log() << id + " got query " + query;

    return query;
}

bool Worker::sendResponse(const std::pair<bool, std::string> &result) {
    std::string response = result.first ? "OK" : "ERROR";
    response += " " + result.second;
    Logger::log() << id + " send response " + response;
    return connection.write(response.data(), response.size());
}
