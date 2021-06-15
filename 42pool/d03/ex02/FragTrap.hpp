/*
** ETNA PROJECT, 13/06/2021 by feuvra_v
** FragTrap
** File description:
**      frag
*/

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include "ClapTrap.hpp"
# include <iostream>
# include <string>
# include <random>
#endif


struct vault_t;

class FragTrap : public ClapTrap
{
    public:
        void vaulthunter_dot_exe(std::string const& target);

    public:
        FragTrap();
        FragTrap(std::string const& name);
        FragTrap(FragTrap& copy);
        ~FragTrap();
        FragTrap& operator=(FragTrap& copy);
        std::ostream& operator<<(std::ostream os);
    
    protected:
        static const std::string _model;
        static std::string const _vaultMsg[];
        static int const _vaultSize;
};