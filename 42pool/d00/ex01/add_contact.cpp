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

int max_reached()
{
    int choice_ID = -1;
    while (choice_ID < 0 || choice_ID > 8) {
        std::cout<<"You have reached maximum capacity, please enter ID of contact you wish to repalce (entrer 0 to cancel):"<<std::endl;
        std::cin>>choice_ID;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return (choice_ID);
}

void add_contact(Contact **list, int& current_size)
{
    std::cout<<"You currently have "<<current_size<<" contacts in your list :"<<std::endl;
    if (current_size > 0){
        for (int i = 0 ; i != current_size ; i++){
            std::cout<<i+1<<'|'<<list[i]->getFirstName()<<std::endl;
        }
    }
    if (current_size < 8){
        list[current_size] = new_contact();
        current_size++;
    } else {
        int choice_ID = max_reached();
        if (!choice_ID)
            return;
        choice_ID--;
        delete (list[choice_ID]);
        list[choice_ID] = new_contact();
    }
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