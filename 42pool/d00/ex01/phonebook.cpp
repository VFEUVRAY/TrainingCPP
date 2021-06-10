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
    int const list_size = 8;
    int current_size = 0;
    Contact *list[list_size];

    while (1){
        std::cout<<"Input something bruh :";
        std::cin>>input;
        std::cout<<std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!my_strcmp(input, "QUIT"))
            return;
        else if (!my_strcmp(input, "ADD"))
            add_contact(list, current_size);
        else if (!my_strcmp(input, "SEARCH"))
            search_contact(list, current_size);
        else
            std::cout<<"Command: "<<input<<" not found."<<std::endl;
    }
}

int main()
{
    phonebook();
    return (0);
}