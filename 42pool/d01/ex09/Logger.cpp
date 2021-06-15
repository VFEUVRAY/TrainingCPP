/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Logger
** File description:
**      functiuons for logger class
*/

#include "Logger.hpp"

struct loggerAction_t {
    std::string name;
    void (Logger::*func)(std::string const&);
};

loggerAction_t Logger::_actions[] = {
    {"file", &Logger::LogToFile},
    {"console", &Logger::LogToConsole}
};

int Logger::_actionNumber = 2;

std::string cleanString(std::string str)
{
    size_t i = 0;
    while (i < str.length()){
        if (str[i] == '\n'){
            str.erase(i, 1);
            i--;
        }
        i++;
    }
    return (str);
}

std::string Logger::makeLogEntry(std::string const& msg)
{
    std::time_t timer = std::time(NULL);
    std::string timeString(ctime(&timer));
    timeString.pop_back();
    return (std::string("date:[" + timeString + "]usr:[" + _userName + "]msg:[" + cleanString(msg) + "]\n"));
}

void Logger::LogToConsole(std::string const& msg)
{
    std::cout<<msg;
    //std::cout<<'['<<ctime(&timer)<<"]|usr:"<<_userName<<"|["<<msg<<std::endl;
}
void Logger::LogToFile(std::string const& msg)
{
    if (this->_file == nullptr){
        std::cout<<"Error: no logger filename in "<<_userName<<" logger\n";
        return ;
    }
    std::ofstream fileStream(*_file, std::ios::app);
    if (!fileStream){
        std::cout<<"Error while loading logger file";
        return ;
    }
    fileStream<<msg;
    fileStream.close();
}

void Logger::log(std::string const& dest, std::string const& message)
{
    int i = 0;
    while (i < _actionNumber) {
        if (dest == _actions[i].name){
            (this->*_actions[i].func)(this->makeLogEntry(message));
            return ;
        }
        i++;
    }
    std::cout<<"Error: "<<dest<<" not found"<<std::endl;
}

void Logger::setLoggerFile(std::string const& fileName)
{
    if (this->_file == nullptr)
        delete (_file);
    this->_file = new std::string(fileName);
}

Logger::Logger() : _userName("Anonymous"), _file(nullptr)
{}

Logger::Logger(std::string const& name) : _userName(name), _file(nullptr)
{}

Logger::Logger(std::string const& name, std::string const& fileName) :
_userName(name)
{
    this->_file = new std::string(fileName);
}

Logger::~Logger()
{
    if (this->_file != NULL)
        delete (this->_file);
}