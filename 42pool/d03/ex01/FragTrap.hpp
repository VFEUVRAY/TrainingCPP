/*
** ETNA PROJECT, 13/06/2021 by feuvra_v
** FragTrap
** File description:
**      frag
*/

#include <iostream>
#include <string>
#include <random>

struct vault_t;

class FragTrap
{
    public:
        int _hp = 100;
        int _maxhp = 100;
        int _ep = 100;
        int _maxep = 100;
        int _lvl = 1;
        std::string _name;
        int _melee = 30;
        int _range = 20;
        int _armor = 5;

    public:
        void rangedAttack(std::string const& target);
        void meleeAttack(std::string const& target);
        void takeDamage(unsigned int const& amount);
        void beRepaired(unsigned int const& amount);
        void vaulthunter_dot_exe(std::string const& target);
        void status();
        int getHp();
        int getEp();
        std::string& getName();
        FragTrap& operator=(FragTrap& copy);

    public:
        FragTrap();
        FragTrap(std::string const& name);
        FragTrap(FragTrap& copy);
        virtual ~FragTrap();
    
    private:
        static std::string const _vaultMsg[];
        static int const _vaultSize;
};