/*
** ETNA PROJECT, 13/06/2021 by feuvra_v
** FragTrap
** File description:
**      ting
*/

#include "FragTrap.hpp"

using std::cout;
using std::endl;

std::string const FragTrap::_model = std::string("FR4G-TP");

std::string const FragTrap::_vaultMsg[] = {
    " fell in the general direction of <t>, who startled and took 1 point of damage",
    " pulled out that 9, 6 movement on the trigger <t> found lying no proof, no suspect, no crime",
    " managed to discover <t>'s darkest secret, the latter was found on a flight to Mexico 2 days later",
    " challenged <t> to a game of rock paper scisors, after 19 draws, <t> surrendered.",
    " sat on <t>'s face inflincting a whoping 69 points of damage."
};

int const FragTrap::_vaultSize = 5;

FragTrap::FragTrap()
{
    this->_name = std::string("Anonymous");
    cout<<"Constructed: "<<this->_name<<" via default constructor"<<endl;
}

FragTrap::FragTrap(std::string const& name)
{
    this->_name = std::string(name);
    cout<<"Constructed: "<<this->_name<<" via name parameter constructor"<<endl;
}

FragTrap::FragTrap(FragTrap& copy)
{
    this->_name = std::string(copy.getName());
    this->_hp = copy.getHp();
    this->_ep = copy.getEp();
    cout<<"Constructed: "<<this->_name<<" via copy constructor"<<endl;
}

FragTrap& FragTrap::operator=(FragTrap& copy)
{
    cout<<"Constructed: "<<this->_name<<" via = operator overload"<<endl;
    this->_name = std::string(copy.getName());
    this->_hp = copy.getHp();
    this->_ep = copy.getEp();
    return (*this);
}

/*
std::ostream& FragTrap::operator<<(std::ostream os)
{
    return (ClapTrap::operator<<(os));
}
*/

FragTrap::~FragTrap()
{
    cout<<"Destroyed: "<<this->_name<<endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const& target)
{
    if (this->_ep < 25){
        cout<<"FR4G-TP "<<this->_name<<" attempted a vault attack but doesn't have enough eps: "<<this->_ep<<endl;
        return ;
    }

    std::string msg = std::string(_vaultMsg[rand() % _vaultSize]);
    size_t i = 0;

    this->_ep -= 25;
    if (this->_ep < 0)
        this->_ep = 0;
    while (i < msg.length()){
        i = msg.find("<t>", i);
        if (i == SIZE_MAX)
            break;
        msg.replace(i, 3, target);
        i += target.length();
    }
    cout<<"FR4G-TP "<<this->_name<<" spent 25ep for a vault attack"<<endl;
    cout<<"FR4G-TP "<<this->_name<<msg<<endl<<"Current ep:"<<this->_ep<<endl;
}