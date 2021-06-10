/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** phonebook
** File description:
**      header for phonebook exercice
*/

#include <iostream>
#include <string>
#include <vector>

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
        std::string getlastName(){return _last_name;}
        std::string getNickname(){return _nickname;}
        std::string getLogin(){return _login;}
        std::string getAddress(){return _address;}
        std::string getEmail(){return _email;}
        std::string getPhone(){return _phone;}
        std::string getBirthday(){return _birthday;}
        std::string getMeal(){return _meal;}
        std::string getUndies(){return _undies;}
        std::string getDarkSecret(){return _dark_secret;}
        void setFirstName(std::string str){_info[0] = _first_name = str;}
        void setLastName(std::string str){_info[1] = _last_name = str;}
        
        std::string *getInfo(){return _info;};

    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _address;
        std::string _login;
        std::string _email;
        std::string _phone;
        std::string _birthday;
        std::string _meal;
        std::string _undies;
        std::string _dark_secret;
        std::string *_info;
};

int my_strcmp(std::string const& a, std::string const& b);
void add_contact(std::vector<Contact *>& list);
void phonebook();