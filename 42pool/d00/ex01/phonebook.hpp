/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** phonebook
** File description:
**      header for phonebook exercice
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

class Contact
{
    public:
        Contact(){_info = new std::string[11];};
        Contact(std::string first_name, std::string last_name,
                std::string nickname, std::string login,
                std::string address, std::string email,
                std::string phone, std::string birthday,
                std::string meal, std::string undies,
                std::string dark_secret);
        virtual ~Contact(){};

    public:
        std::string getFirstName(){return _info[0];}
        std::string getlastName(){return _info[1];}
        std::string getNickname(){return _info[2];}
        std::string getLogin(){return _info[3];}
        std::string getAddress(){return _info[4];}
        std::string getEmail(){return _info[5];}
        std::string getPhone(){return _info[6];}
        std::string getBirthday(){return _info[7];}
        std::string getMeal(){return _info[8];}
        std::string getUndies(){return _info[9];}
        std::string getDarkSecret(){return _info[10];}
        void setInfos(std::string *info){_info = info;}
        void setFirstName(std::string str){_info[0] = str;}
        void setLastName(std::string str){_info[1] = str;}
        
        std::string *getInfo(){return _info;};

    private:
        std::string *_info;
};

int my_strcmp(std::string const& a, std::string const& b);
void add_contact(Contact **list, int& current_size);
void search_contact(Contact **list, int& current_size);
void phonebook();