/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Weapon
** File description:
**      weapon header
*/

#include <iostream>
#include <string>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();

        void setType(std::string type);
        std::string getType();

    private:
        std::string _type;
};