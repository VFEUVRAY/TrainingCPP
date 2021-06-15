/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** ex04
** File description:
**      strings and refs and stuff mdr
*/

#include <iostream>
#include <string>

int main()
{
    std::string base_string("HI THIS IS BRAIN");
    std::string &ref_string = base_string;
    std::string *point_string = &base_string;

    std::cout<<ref_string<<std::endl<<*point_string<<std::endl;
    return (0);
}