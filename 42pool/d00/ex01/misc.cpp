/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** misc
** File description:
**      some random useful funcitons
*/

#include "phonebook.hpp"

int my_strcmp(std::string const& a, std::string const& b)
{
    size_t i = 0;
    
    while (a[i] && b[i]) {
        if (a[i] != b[i])
            return (a[i] - b[i]);
        i++;
    }
    return (a[i] - b[i]);
}