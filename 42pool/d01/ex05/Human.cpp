/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Human
** File description:
**      human
*/

#include "Human.hpp"

Human::Human()
{}

Human::~Human()
{}

Brain Human::getBrain()
{
    return (_brain);
}

std::string Human::identify() const
{
    return (this->_brain.identify());
}