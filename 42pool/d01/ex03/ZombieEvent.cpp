/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** ZombieEvent
** File description:
**      Zombie Even functions
*/

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "ZombieEvent.hpp"
#endif

#include <random>

const char *ZombieEvent::_namePool[] = {"Vaillant", "Thierry", "Alexis",
                                        "Wabieh", "Julie", "Christophe",
                                        "IDIW", "Brice", "Anthony",
                                        "Henesis", "Flavien", "Adil"};
const int ZombieEvent::_namePoolSize = 12;

void ZombieEvent::setType(const char *type)
{
    delete [](_type);
    _type = my_strcpy(type);
}

Zombie *ZombieEvent::newZombie(std::string name)
{
    char zname[name.size() + 1];
    Zombie *zomb;

    for (int i = 0 ; i < name.size() ; i++)
        zname[i] = name[i];
    zname[name.size()] = 0;
    zomb = new Zombie(zname, _type);
    zomb->announce();
    return (zomb);
}

Zombie *ZombieEvent::randomChump()
{
    Zombie *zomb;
    const char *randName = _namePool[std::rand() % _namePoolSize];
    char zname[my_strlen(randName) + 1];
    int i = 0;

    while (randName[i]){
        zname[i] = randName[i];
        i++;
    }
    zname[i] = 0;
    zomb = new Zombie(zname, _type);
    zomb->announce();
    return (zomb);
}