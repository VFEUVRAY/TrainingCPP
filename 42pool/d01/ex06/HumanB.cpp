/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** HumanB
** File description:
**      humanB
*/

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
_name(name), _weapon(NULL)
{}

HumanB::HumanB(std::string name, Weapon& weapon) :
_name(name), _weapon(&weapon)
{}

HumanB::~HumanB()
{}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}

void HumanB::attack()
{
    if (_weapon){
        std::cout<<_name<<" attacks with his "<<_weapon->getType()<<std::endl;
        return ;
    }
    std::cout<<_name<<" has no weapon to attack with"<<std::endl;
}