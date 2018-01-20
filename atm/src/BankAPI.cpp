/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   20 Jan 2018
*/

#include <vector>
#include <sstream>

#include "BankAPI.hpp"


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

BankAPI::BankAPI(const Endpoint &endpoint, BaseConnection &&connection) :
        endpoint(endpoint), connection(connection) { }

Responce BankAPI::getCash(float amount) {
    auto response = makeQuery("get " + std::to_string(amount));
    if (!response.success) return response;

    return {true, ""};
}

Responce BankAPI::addCash(float amount) {
    auto response = makeQuery("add " + std::to_string(amount));
    if (!response.success) return response;

    return {true, ""};
}

Responce BankAPI::cash(float &amount) {
    auto response = makeQuery("cash");
    if (!response.success) return response;

    char *ptr = nullptr;
    auto result = strtod(response.message.c_str(), &ptr);
    if (ptr == nullptr) {
        return {false, "Connection error (cash request)"};
    }
    amount = static_cast<float>(result);

    return {true, ""};
}

Responce BankAPI::setClient(const CardInfo &info) {
    std::string id = info.card + " " + std::to_string(info.pin);

    auto response = makeQuery(id);
    if (!response.success) return response;

    clientid = id;

    return {true, ""};
}

Responce BankAPI::makeQuery(const std::string &inputquery) {
    std::string query = clientid + " " + inputquery;
    std::vector<char> buffer(1024);
    size_t size = buffer.size();

    if (!connection.create(endpoint)) {
        return {false, "Connection error while create"};
    }
    if (!connection.write(query.data(), query.size())) {
        return {false, "Connection error while write"};
    }
    else if (!connection.read(buffer.data(), size)) {
        return {false, "Connection error while read"};
    }
    if (!connection.close()) {
        return {false, "Connection error while close"};
    };

    std::string response{buffer.begin(), buffer.begin() + size};
    auto splited = split(response);
    if (!splited.empty()) {
        auto joined = join(splited, 1);
        if (splited[0] == "ERROR") return Responce{false, joined};
        if (splited[0] == "OK") return Responce{true, joined};
    }

    return {false, "Connection error"};
}
