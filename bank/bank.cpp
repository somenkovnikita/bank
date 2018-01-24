/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <iostream>
#include <Logger.hpp>
#include "Server.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2 && std::string(argv[1]) == "debug") {
        Logger::log().setFile("server.log");
        Endpoint endpoint;
        endpoint.ip = "127.0.0.1";
        endpoint.port = 31415;

        Server server(endpoint);
        if (!server.initialize()) {
            std::cout << "cannot initialize" << std::endl;
            return -1;
        }
        server.run();
    }
//    pid_t pid, sid;
//
//    /* Fork off the parent process */
//    pid = fork();
//    if (pid < 0) {
//        exit(EXIT_FAILURE);
//    }
//    /* If we got a good PID, then
//       we can exit the parent process. */
//    if (pid > 0) {
//        exit(EXIT_SUCCESS);
//    }
//
//    /* Change the file mode mask */
//    umask(0);
//
//    /* Open any logs here */
//
//    /* Create a new SID for the child process */
//    sid = setsid();
//    if (sid < 0) {
//        /* Log the failure */
//        exit(EXIT_FAILURE);
//    }
//
//    /* Change the current working directory */
//    if ((chdir("/")) < 0) {
//        /* Log the failure */
//        exit(EXIT_FAILURE);
//    }
//
//    /* Close out the standard file descriptors */
//    close(STDIN_FILENO);
//    close(STDOUT_FILENO);
//    close(STDERR_FILENO);
//
//    /* Daemon-specific initialization goes here */
//
//    /* The Big Loop */
//    while (1) {
//        /* Do some task here ... */
//
//        sleep(30); /* wait 30 seconds */
//    }
//    exit(EXIT_SUCCESS);
}
