/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** phonebook
** File description:
**      main file for phonebook project
*/

#include "phonebook.hpp"

void phonebook()
{
    std::string input = "dummy";
    std::vector<Contact *> contact_list(0);

    while (1){
        std::cout<<"Input something bruh :";
        std::cin>>input;
        std::cout<<std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!my_strcmp(input, "QUIT"))
            return;
        else if (!my_strcmp(input, "ADD"))
            add_contact(contact_list);
        else if (!my_strcmp(input, "SEARCH"))
            search_contact(contact_list);
        else
            std::cout<<"Command: "<<input<<" not found."<<std::endl;
    }
}

int main()
{
    phonebook();
    return (0);
}