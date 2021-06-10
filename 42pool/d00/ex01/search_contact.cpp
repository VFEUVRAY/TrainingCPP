/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** search_contact
** File description:
**      search relevant functions
*/

#include "phonebook.hpp"

char *display_contact_info(std::string str)
{
    char *res = new char[11];
    int spaces = 0 + ((10 - str.size()) * (str.size() < 10));

    if (!spaces) {
        for (int i = 0 ; i < 9 ; i++)
            res[i] = str[i];
        res[9] = '.';
        res[10] = 0;
        return (res);
    } else {
        for (int i = 0 ; i < spaces ; i++)
            res[i] = ' ';
        for (int i = spaces ; i < str.size() + spaces ; i++)
            res[i] = str[i - spaces];
        res[10] = 0;
    }
    return (res);
}

void search_contact(Contact **list, int& current_size)
{
    int choice_id = -1;
    std::cout<<"You currently have "<<current_size<<" contact(s) in your list."<<std::endl;
    if (current_size == 0)
        return;
    std::cout<<"        ID|First Name| Last Name|  Nickname"<<std::endl;
    for (int i = 0 ; i < current_size ; i++) {
        std::cout<<"         "<<i+1<<"|"<<display_contact_info(list[i]->getFirstName())<<"|"<<
        display_contact_info(list[i]->getlastName())<<"|"<<display_contact_info(list[i]->getNickname())<<std::endl;
    }
    while (choice_id > current_size || choice_id < 0){
        std::cout<<"Which contact's informations do you wish to see (enter their ID below, 0 to cancel):"<<std::endl;
        std::cin>>choice_id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<std::endl;
    }
    if (!choice_id)
        return ;
    choice_id--;
    std::cout<<list[choice_id]->getFirstName()<<std::endl<<list[choice_id]->getlastName()<<std::endl<<
        list[choice_id]->getNickname()<<std::endl<<list[choice_id]->getLogin()<<std::endl<<
        list[choice_id]->getEmail()<<std::endl<<list[choice_id]->getPhone()<<std::endl<<
        list[choice_id]->getAddress()<<std::endl<<list[choice_id]->getBirthday()<<std::endl<<
        list[choice_id]->getMeal()<<std::endl<<list[choice_id]->getUndies()<<std::endl<<
        list[choice_id]->getDarkSecret()<<std::endl;

}