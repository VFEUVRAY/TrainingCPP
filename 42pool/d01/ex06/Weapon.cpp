/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Weapon
** File description:
**      weapon functions
*/

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include "Weapon.hpp"
#endif

Weapon::Weapon(std::string type) : _type(type)
{}

Weapon::~Weapon()
{}

void Weapon::setType(std::string type)
{
    _type = type;
}

std::string Weapon::getType()
{
    return (_type);
}