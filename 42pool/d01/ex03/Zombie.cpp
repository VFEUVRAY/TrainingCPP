/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** Zombie
** File description:
**      zombie cpp ting
*/

#include "Zombie.hpp"

Zombie::Zombie() 
: _name(NULL), _type(NULL)
{}

void Zombie::announce()
{
    if (_name && _type)
        std::cout<<"<"<<_name<<" ("<<_type<<")> Braiiiiiiiinnnnnsssssss..."<<std::endl;
}

void Zombie::setName(const char *name)
{
    _name = my_strcpy(name);
}

void Zombie::setType(const char *type)
{
    _type = my_strcpy(type);
}

Zombie::Zombie(const char *name, const char *type)
{
    _name = my_strcpy(name);
    _type = my_strcpy(type);
}

Zombie::~Zombie()
{
    delete[] (_name);
    delete[] (_type);
}