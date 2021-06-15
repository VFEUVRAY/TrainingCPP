/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** HumanA
** File description:
**      human A functions
*/

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
_name(name), _weapon(weapon)
{}

HumanA::~HumanA()
{}

void HumanA::attack()
{
    std::cout<<_name<<" attacks with his "<<_weapon.getType()<<std::endl;
}