/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** Zombie
** File description:
**      zombie cpp ting
*/

#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout<<"<"<<_name<<" ("<<_type<<")> Braiiiiiiiinnnnnsssssss..."<<std::endl;
}

Zombie::Zombie(const char *name, const char *type)
{
    _name = name;
    _type = type;
}