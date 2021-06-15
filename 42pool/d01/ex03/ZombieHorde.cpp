/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** ZombieHorde
** File description:
**      horde
*/

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H
# include "ZombieHorde.hpp"
#endif

const char *ZombieHorde::_namePool[] = {"Vaillant", "Thierry", "Alexis",
                                        "Wabieh", "Julie", "Christophe",
                                        "IDIW", "Brice", "Anthony",
                                        "Henesis", "Flavien", "Adil",
                                        "Caroline", "Nadia", "Yohan",
                                        "Balthazar", "Moloko", "Laeticia"};
const int ZombieHorde::_namePoolSize = 18;

ZombieHorde::ZombieHorde(const int n) 
: _hordeSize(n), _horde(new Zombie[n])
{
    for (int i = 0 ; i < _hordeSize ; i++) {
        _horde[i].setName(_namePool[std::rand() % _namePoolSize]);
        _horde[i].setType("Horde");
    }
}

Zombie *ZombieHorde::getHorde()
{
    return (_horde);
}

void ZombieHorde::announce()
{
    for (int i = 0 ; i < _hordeSize ; i++)
        _horde[i].announce();
}

ZombieHorde::~ZombieHorde(){
    delete[] (_horde);
}