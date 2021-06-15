/*
** ETNA PROJECT, 13/06/2021 by feuvra_v
** ClapTrap
** File description:
**      claps claps
*/

#include "ClapTrap.hpp"
using std::cout;
using std::endl;

std::string const ClapTrap::_model = std::string("CL4P-TP");

ClapTrap::ClapTrap() :
_hp(100), _maxhp(100), _ep(100), _maxep(100),
_lvl(1), _melee(30), _range(20), _armor(5)
{
    this->_name = std::string("Anonymous");
    //this->_model = std::string("CL4P-TP");
    cout<<"Dug up a new "<<this->_model<<" : "<<this->_name<<" via default constructor"<<endl;
}

ClapTrap::ClapTrap(std::string const& name) :
_hp(100), _maxhp(100), _ep(100), _maxep(100),
_lvl(1), _melee(30), _range(20), _armor(5)
{
    this->_name = std::string(name);
    //this->_model = std::string("CL4P-TP");
    cout<<"Dug up a new "<<this->_model<<" : "<<this->_name<<" via name parameter constructor"<<endl;
}

ClapTrap::ClapTrap(ClapTrap& copy) :
_hp(100), _maxhp(100), _ep(100), _maxep(100),
_lvl(1), _melee(30), _range(20), _armor(5)
{
    this->_name = std::string(copy.getName());
    this->_hp = copy.getHp();
    this->_ep = copy.getEp();
    //this->_model = copy.getModel();
    cout<<"Dug up a new "<<this->_model<<" : "<<this->_name<<" via copy constructor"<<endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& copy)
{
    this->_name = std::string(copy.getName());
    this->_hp = copy.getHp();
    this->_ep = copy.getEp();
    //this->_model = copy.getModel();
    cout<<"Constructed: "<<this->_name<<" via = operator overload"<<endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    cout<<"Discarded: "<<this->_model<<" : "<<this->_name<<endl;
}

void ClapTrap::meleeAttack(std::string const& target)
{
    cout<<this->_model<<" "<<this->_name<<" attacks "<<target<<" at melee, causing "<<this->_melee<<" points of damage"<<endl;
}

void ClapTrap::rangedAttack(std::string const& target)
{
    cout<<this->_model<<" "<<this->_name<<" attacks "<<target<<" at range, causing "<<this->_range<<" points of damage"<<endl;
}

void ClapTrap::takeDamage(unsigned int const& amount)
{
    int damage = amount - this->_armor;
    damage = (damage > 0) * damage;
    this->_hp = this->_hp - damage;
    this->_hp = (this->_hp > 0) * this->_hp;
    cout<<this->_model<<" "<<this->_name<<" took "<<damage<<" points of damage ("
    <<amount<<" - "<<_armor<<") current hp: "<<this->_hp<<endl;
}

void ClapTrap::beRepaired(unsigned int const& amount)
{
    this->_hp = this->_hp + amount;
    this->_ep = this->_ep + amount;
    if (this->_ep > this->_maxep)
        this->_ep = this->_maxep;
    if (this->_hp > this->_maxhp)
        this->_hp = this->_maxhp;
    cout<<this->_model<<" "<<this->_name<<" repaired for "<<amount<<" points"<<endl
    <<"current: "<<this->_hp<<"hp "<<this->_ep<<" ep"<<endl;
}

std::ostream& operator<<(std::ostream& os, ClapTrap& obj)
{
    os<<'('<<obj._name<<':'<<obj._hp<<':'<<obj._ep<<')';
    return (os);
}

std::istream& ClapTrap::operator>>(std::istream& is)
{
    unsigned int hp;
    unsigned int ep;
    is>>hp;
    is>>ep;
    this->setEP(ep);
    this->setHP(hp);
    return(is);
}

std::string& ClapTrap::getName()
{
    return (this->_name);
}

void ClapTrap::status()
{
    cout<<this->_name<<": HP:"<<this->_hp<<" EP:"<<this->_ep<<endl;
}

int ClapTrap::getHp()
{
    return (this->_hp);
}

int ClapTrap::getEp()
{
    return (this->_ep);
}

std::string const& ClapTrap::getModel()
{
    return (_model);
}

void ClapTrap::setHP(unsigned int n)
{
    _hp = n;
}

void ClapTrap::setEP(unsigned int n)
{
    _ep = n;
}