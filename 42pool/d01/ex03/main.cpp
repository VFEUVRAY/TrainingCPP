/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** main
** File description:
**      main for zombies
*/

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "ZombieEvent.hpp"
#endif



int main()
{
    //char *type = my_strcpy("walker");
    Zombie zomb("salut", "lelz");
    ZombieEvent event("walker");
    Zombie *zomb2 = event.randomChump();
    event.setType("marauder");
    Zombie *zomb3 = event.randomChump();
    zomb.announce();
    delete(zomb2);
    delete(zomb3);
    //delete [](type);
    return (1);
}