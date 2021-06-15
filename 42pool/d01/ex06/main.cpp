/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** main
** File description:
**      main for humans & weapons
*/

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    Weapon club2 = Weapon("crude spiked club");
    HumanB francis("Francis");
    francis.setWeapon(club2);
    francis.attack();
    club2.setType("some other type of club");
    francis.attack();
    return (1);
}