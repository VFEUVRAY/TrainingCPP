/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** main
** File description:
**      main for zombies
*/

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H
# include "ZombieHorde.hpp"
#endif

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *my_strcpy(const char *str)
{
    char *res = new char[my_strlen(str) + 1];
    int i = 0;
    while (str[i]) {
        res[i] = str[i];
        i++;
    }
    res[i] = 0;
    return (res);
}

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
    std::cout<<std::endl<<"Horde is coming"<<std::endl<<std::endl;
    //delete [](type);
    ZombieHorde horde(6);
    horde.announce();
    return (1);
}