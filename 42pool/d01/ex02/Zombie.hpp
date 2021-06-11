/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** Zombie
** File description:
**      zombie class ting
*/

#include <iostream>

class Zombie
{
    public:
        Zombie(const char *name, const char *type);
        ~Zombie(){};

        const char *getName(){return _name;}
        const char *getType(){return _type;}
        void announce();

    private:
        Zombie(){};
        const char *_name;
        const char *_type;
};