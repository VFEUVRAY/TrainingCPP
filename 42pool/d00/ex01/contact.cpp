/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** catact
** File description:
**      contact class related functions
*/

#include "phonebook.hpp"

Contact::Contact(std::string first_name, std::string last_name,
                std::string nickname, std::string login,
                std::string address, std::string email,
                std::string phone, std::string birthday,
                std::string meal, std::string undies,
                std::string dark_secret)
{
    _info = new std::string[11];
    _info[0] = first_name;
    _info[1] = last_name;
    _info[2] = nickname;
    _info[3] = login;
    _info[4] = address;
    _info[5] = email;
    _info[6]  = phone;
    _info[7] = birthday;
    _info[8] = meal;
    _info[9] = undies;
    _info[10] = dark_secret;
}