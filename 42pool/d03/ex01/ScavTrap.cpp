/*
** ETNA PROJECT, 13/06/2021 by feuvra_v
** ScavTrap
** File description:
**      ting
*/

#include "ScavTrap.hpp"

using std::cout;
using std::endl;

std::string const ScavTrap::_vaultMsg[] = {
    " fell in the general direction of <t>, who startled and took 1 point of damage",
    " pulled out that 9, 6 movement on the trigger <t> found lying no proof, no suspect, no crime",
    " managed to discover <t>'s darkest secret, the latter was found on a flight to Mexico 2 days later",
    " challenged <t> to a game of rock paper scisors, after 19 draws, <t> surrendered.",
    " sat on <t>'s face inflincting a whoping 69 points of damage."
};

int const ScavTrap::_vaultSize = 5;

std::string const ScavTrap::_challengeMsg[] = {
    "<n> says: \"Wanna see me do a flip?\" *flips* .... The issue was unfortunate",
    "<n> says: \"So I'm watching E3 2021 right and I challenge you to find something cool, I double dare you\"",
    "<n> challenges you to a cheeky connect 4 championship, do not disappoint them",
    "It is <n>'s birthday, sadly I'm the only one to know, you have to wish them without them knowing your learned it from me",
    "This is not a challenge, just end it already... MAKE IT STOP"
};

int const ScavTrap::_challengeSize = 5;

ScavTrap::ScavTrap()
{
    this->_name = std::string("Anonymous");
    cout<<"Dug up a new SC4V-TP: "<<this->_name<<" via default constructor"<<endl;
}

ScavTrap::ScavTrap(std::string const& name)
{
    this->_name = std::string(name);
    cout<<"Dug up a new SC4V-TP: "<<this->_name<<" via name parameter constructor"<<endl;
}

ScavTrap::ScavTrap(ScavTrap& copy)
{
    this->_name = std::string(copy.getName());
    this->_hp = copy.getHp();
    this->_ep = copy.getEp();
    cout<<"Dug up a new SC4V-TP: "<<this->_name<<" via copy constructor"<<endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& copy)
{
    this->_name = std::string(copy.getName());
    this->_hp = copy.getHp();
    this->_ep = copy.getEp();
    cout<<"Constructed: "<<this->_name<<" via = operator overload"<<endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    cout<<"Discarded SC4V-TP: "<<this->_name<<endl;
}

void ScavTrap::meleeAttack(std::string const& target)
{
    cout<<"SC4V-TP "<<this->_name<<" attacks "<<target<<" at melee, causing "<<this->_melee<<" points of damage"<<endl;
}

void ScavTrap::rangedAttack(std::string const& target)
{
    cout<<"SC4V-TP "<<this->_name<<" attacks "<<target<<" at range, causing "<<this->_range<<" points of damage"<<endl;
}

void ScavTrap::takeDamage(unsigned int const& amount)
{
    int damage = amount - this->_armor;
    damage = (damage > 0) * damage;
    this->_hp = this->_hp - damage;
    this->_hp = (this->_hp > 0) * this->_hp;
    cout<<"SC4V-TP "<<this->_name<<" took "<<damage<<" points of damage ("
    <<amount<<" - "<<_armor<<") current hp: "<<this->_hp<<endl;
}

void ScavTrap::beRepaired(unsigned int const& amount)
{
    this->_hp = this->_hp + amount;
    this->_ep = this->_ep + amount;
    if (this->_ep > this->_maxep)
        this->_ep = this->_maxep;
    if (this->_hp > this->_maxhp)
        this->_hp = this->_maxhp;
    cout<<"SC4V-TP "<<this->_name<<" repaired for "<<amount<<" points"<<endl
    <<"current: "<<this->_hp<<"hp "<<this->_ep<<" ep"<<endl;
}

std::string& ScavTrap::getName()
{
    return (this->_name);
}

void ScavTrap::vaulthunter_dot_exe(std::string const& target)
{
    if (this->_ep < 25){
        cout<<"SC4V-TP "<<this->_name<<" attempted a vault attack but doesn't have enough eps: "<<this->_ep<<endl;
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
    cout<<"SC4V-TP "<<this->_name<<" spent 25ep for a vault attack"<<endl;
    cout<<"SC4V-TP "<<this->_name<<msg<<endl<<"Current ep:"<<this->_ep<<endl;
}

void ScavTrap::challengeNewcomer()
{
    std::string msg = std::string(_challengeMsg[rand() % _challengeSize]);
    for (size_t i = 0 ; i < msg.length() ; i++){
        i = msg.find("<n>", i);
        if (i == SIZE_MAX)
            break;
        msg.replace(i, 3, this->_name);
    }
    cout<<msg<<endl;
}

void ScavTrap::status()
{
    cout<<this->_name<<": HP:"<<this->_hp<<" EP:"<<this->_ep<<endl;
}

int ScavTrap::getHp()
{
    return (this->_hp);
}

int ScavTrap::getEp()
{
    return (this->_ep);
}