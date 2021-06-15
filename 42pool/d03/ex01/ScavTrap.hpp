/*
** ETNA PROJECT, 13/06/2021 by feuvra_v
** ScavTrap
** File description:
**      frag
*/

#include <iostream>
#include <string>
#include <random>

struct vault_t;

class ScavTrap
{
    public:
        int _hp = 100;
        int _maxhp = 100;
        int _ep = 50;
        int _maxep = 50;
        int _lvl = 1;
        std::string _name;
        int _melee = 20;
        int _range = 15;
        int _armor = 3;

    public:
        void rangedAttack(std::string const& target);
        void meleeAttack(std::string const& target);
        void takeDamage(unsigned int const& amount);
        void beRepaired(unsigned int const& amount);
        void vaulthunter_dot_exe(std::string const& target);
        void challengeNewcomer();
        void status();
        int getHp();
        int getEp();
        std::string& getName();

    public:
        ScavTrap();
        ScavTrap(std::string const& name);
        ScavTrap(ScavTrap& copy);
        ScavTrap& operator=(ScavTrap& copy);
        ~ScavTrap();
    
    private:
        static std::string const _vaultMsg[];
        static int const _vaultSize;
        static std::string const _challengeMsg[];
        static int const _challengeSize;
};