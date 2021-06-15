/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** HumanA
** File description:
**      humanA, has weapon reference because requires a weapon on construction
*/

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include "Weapon.hpp"
#endif

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void attack();

    private:
        std::string _name;
        Weapon& _weapon;
};