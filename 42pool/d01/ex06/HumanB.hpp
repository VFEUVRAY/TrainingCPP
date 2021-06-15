/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** HumanB
** File description:
**      HumanB, stores a pointer to weapon so we can check
**      whether said weapon was indeed assinged
*/

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include "Weapon.hpp"
#endif

class HumanB
{
    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon& weapon);
        ~HumanB();

        void setWeapon(Weapon& weapon);
        void attack();

    private:
        std::string _name;
        Weapon *_weapon;
};