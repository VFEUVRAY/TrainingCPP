/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** main
** File description:
**      main
*/

#include "Human.hpp"
#include <iostream>

int main()
{
    Human bob;
    std::cout<<bob.getBrain().identify()<<std::endl;
    std::cout<<bob.identify()<<std::endl;
    return (0);
}