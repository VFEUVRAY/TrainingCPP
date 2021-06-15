/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** main
** File description:
**      main for logger exo
*/

#include "Logger.hpp"

int main()
{
    Logger log("herve", "test.log");
    log.log("console", "this is a test\n message");
    log.log("file", "I am writing in a file");
    Logger an;
    an.log("console", "being sneaky");
    an.log("file", "this should not work");
    an.setLoggerFile("anonymousLogs");
    an.log("file", "now this should work");
    return (0);
}