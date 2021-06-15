/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** main
** File description:
**      fixed tings
*/

#include "Fixed.hpp"

int main()
{
    Fixed a(5);
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout<<a.getRawBits()<<std::endl;
    std::cout<<b.getRawBits()<<std::endl;
    std::cout<<c.getRawBits()<<std::endl;
    std::cout<<"manual:  "<<(5<<8)<<std::endl;
    std::cout<<"manual:  "<<(1280>>8)<<std::endl;
    return 0;
}