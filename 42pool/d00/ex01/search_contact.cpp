/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** search_contact
** File description:
**      search relevant functions
*/

#include "phonebook.hpp"

void search_contact(std::vector<Contact *>& list)
{
    int choice_id = -1;
    std::cout<<"You currently have "<<list.size()<<" contacts in your list."<<std::endl;
    if (list.size() == 0)
        return;
    std::cout<<std::setw(50)<<"ID|First Name|Last Name|Nickname"<<std::endl;
    for (int i = 0 ; i < list.size() ; i++) {
        std::cout<<std::right<<i+1<<"|"<<list[i]->getFirstName()<<"|"<<
        list[i]->getlastName()<<"|"<<list[i]->getNickname()<<std::endl;
    }
    while (choice_id > list.size() || choice_id < 1){
        std::cout<<"Which contact's informations do you wish to see (enter their ID below):"<<std::endl;
        std::cin>>choice_id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<std::endl;
    }
    choice_id--;
    std::cout<<list[choice_id]->getFirstName()<<std::endl<<list[choice_id]->getlastName()<<std::endl<<
        list[choice_id]->getNickname()<<std::endl<<list[choice_id]->getLogin()<<std::endl<<
        list[choice_id]->getEmail()<<std::endl<<list[choice_id]->getPhone()<<std::endl<<
        list[choice_id]->getAddress()<<std::endl<<list[choice_id]->getBirthday()<<std::endl<<
        list[choice_id]->getMeal()<<std::endl<<list[choice_id]->getUndies()<<std::endl<<
        list[choice_id]->getDarkSecret()<<std::endl;

}