/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** Zombie
** File description:
**      zombie class ting
*/

#include <iostream>

int my_strlen(const char *str);
char *my_strcpy(const char *str);

class Zombie
{
    public:
        Zombie(const char *name, const char *type);
        Zombie();
        ~Zombie();

        const char *getName(){return _name;}
        const char *getType(){return _type;}
        void setName(const char *name);
        void setType(const char *type);
        void announce();

    private:
        char *_name;
        char *_type;
};