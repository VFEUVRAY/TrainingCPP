/*
** ETNA PROJECT, 13/06/2021 by feuvra_v
** main
** File description:
**      main
*/

#include "FragTrap.hpp"

int main()
{
    FragTrap karl("karl");
    karl.meleeAttack("francis");
    karl.takeDamage(34);
    karl.vaulthunter_dot_exe("sakes");
    karl.status();
    karl.vaulthunter_dot_exe("Bracca");
    karl.vaulthunter_dot_exe("Zombie");
    karl.status();
    FragTrap karl2("karl2");
    karl2.status();
    return (0);
}