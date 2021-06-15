/*
** ETNA PROJECT, 13/06/2021 by feuvra_v
** ClapTrap
** File description:
**      clap clap
*/

#include <string>
#include <iostream>
#include <random>

class ClapTrap
{
    public:
        int _hp;
        int _maxhp;
        int _ep;
        int _maxep;
        int _lvl;
        std::string _name;
        int _melee;
        int _range;
        int _armor;

    public:
        void rangedAttack(std::string const& target);
        void meleeAttack(std::string const& target);
        void takeDamage(unsigned int const& amount);
        void beRepaired(unsigned int const& amount);
        void status();
        int getHp();
        int getEp();
        void setHP(unsigned int n);
        void setEP(unsigned int n);
        std::string& getName();
        std::string const& getModel();
        friend std::ostream& operator<<(std::ostream& os, ClapTrap& obj);
        std::istream& operator>>(std::istream& is);


    public:
        ClapTrap();
        ClapTrap(std::string const& name);
        ClapTrap(ClapTrap& copy);
        ClapTrap& operator=(ClapTrap& copy);
        virtual ~ClapTrap();
    
    private:
        static const std::string _model;
};