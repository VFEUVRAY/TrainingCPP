/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** add_contact
** File description:
**      ADD functions
*/

#include "phonebook.hpp"

Contact *new_contact()
{
    Contact *con = new Contact();
    std::string *new_info = new std::string[11];
    std::string input;
    std::cout<<std::endl<<"please enter your new contact's First Name : ";
    std::getline(std::cin, new_info[0]);
    std::cout<<std::endl<<"please enter your new contact's Last Name : ";
    std::getline(std::cin, new_info[1]);
    std::cout<<std::endl<<"please enter your new contact's Nickname : ";
    std::getline(std::cin, new_info[2]);
    std::cout<<std::endl<<"please enter your new contact's Login : ";
    std::getline(std::cin, new_info[3]);
    std::cout<<std::endl<<"please enter your new contact's Address : ";
    std::getline(std::cin, new_info[4]);
    std::cout<<std::endl<<"please enter your new contact's Email : ";
    std::getline(std::cin, new_info[5]);
    std::cout<<std::endl<<"please enter your new contact's Phone number : ";
    std::getline(std::cin, new_info[6]);
    std::cout<<std::endl<<"please enter your new contact's Birthday date : ";
    std::getline(std::cin, new_info[7]);
    std::cout<<std::endl<<"please enter your new contact's Favorite meal : ";
    std::getline(std::cin, new_info[8]);
    std::cout<<std::endl<<"please enter your new contact's underwear color : ";
    std::getline(std::cin, new_info[9]);
    std::cout<<std::endl<<"please enter your new contact's darkest secret... ";
    std::getline(std::cin, new_info[10]);
    con->setInfos(new_info);
    return (con);
}

void add_contact(std::vector<Contact *>& list)
{
    std::cout<<"You currently have "<<list.size()<<" contacts in your list :"<<std::endl;
    if (list.size() > 0){
        for (auto it = list.begin() ; it != list.end() ; it++){
            std::cout<<(*it)->getFirstName()<<std::endl;
        }
    }
    list.push_back(new_contact());
}

int test(std::vector<int>& truc)
{
    return (1);
}

int thing()
{
    std::vector<int> vec(0);
    test(vec);
    return (1);
}