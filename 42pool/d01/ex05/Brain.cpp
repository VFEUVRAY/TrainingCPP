/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Brain
** File description:
**        
*/

#include "Brain.hpp"

Brain::Brain()
{
    //make sure to get this' address
    void const *brain_adress = static_cast<const void*>(this);
    std::stringstream ss;
    ss<<brain_adress;
    //ss>>_address;
    _address = ss.str(); //makes sure the copy the whole buffer
}

Brain::~Brain()
{}

std::string Brain::identify() const
{
    return (_address);
}