/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** ZombieEvent
** File description:
**      zombie even header
*/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include "Zombie.hpp"
# include <string>
# include <random>
#endif

class ZombieEvent
{
    public:
        void setType(const char *type);
        Zombie *newZombie(std::string name);
        Zombie *randomChump();

        ZombieEvent(const char *type) : _type(my_strcpy(type)){};
        ~ZombieEvent(){delete [](_type);};

    private:
        ZombieEvent(){};
        static const char *_namePool[];
        static const int _namePoolSize;
        char *_type;
};