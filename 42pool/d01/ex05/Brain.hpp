/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** Brain
** File description:
**      brain header
*/

#include <iostream>
#include <string>
#include <sstream>

class Brain
{
    public:
        Brain();
        ~Brain();

        std::string identify() const;

    private:
        std::string _address;
};