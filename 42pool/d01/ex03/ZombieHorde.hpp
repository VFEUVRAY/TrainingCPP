/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** ZombieHorde
** File description:
**      horde
*/

#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H
# include "ZombieEvent.hpp"
#endif

class ZombieHorde
{
    public:
        ZombieHorde(const int n);
        ~ZombieHorde();
    
        Zombie *getHorde();
        void announce();
    private:
        Zombie *_horde;
        int _hordeSize;
        static const char *_namePool[];
        static const int _namePoolSize;
};