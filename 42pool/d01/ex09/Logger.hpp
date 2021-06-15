/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Logger
** File description:
**      logger header
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

struct loggerAction_t;

class Logger
{
    private:
        void LogToConsole(std::string const& msg);
        void LogToFile(std::string const& msg);

        std::string makeLogEntry(std::string const& msg);

        std::string *_file;
        std::string _userName;
        static loggerAction_t _actions[];
        static int _actionNumber;
        
    public:
        Logger();
        Logger(std::string const& name);
        Logger(std::string const& name, std::string const& fileName);

        void log(std::string const& dest, std::string const& message);
        void setLoggerFile(std::string const& fileName);

        ~Logger();
};