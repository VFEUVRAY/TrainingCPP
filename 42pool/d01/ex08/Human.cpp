/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Human
** File description:
**      human functions
*/

#include "Human.hpp"

struct action_t {
    std::string name;
    void (Human::*func)(std::string const&);
};

action_t const Human::_actions[] = {
    {"melee", &Human::meleeAttack},
    {"ranged", &Human::rangedAttack},
    {"shout", &Human::intimidatingShout}
};

int const Human::_actionNumber = 3;

Human::Human(std::string name) : _name(name){}

Human::~Human(){}

void Human::meleeAttack(std::string const& target)
{
    std::cout<<_name<<" goes full frontal close quater with "<<target<<std::endl;
}

void Human::rangedAttack(std::string const& target)
{
    std::cout<<_name<<" being a Legolas wannabe, my support to "<<target<<std::endl;
}

void Human::intimidatingShout(std::string const& target)
{
    std::cout<<_name<<": AAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<std::endl<<target<<": ?"<<std::endl;
}

void Human::action(std::string const& action_name, std::string const& target)
{
    int i = 0;
    while (i < _actionNumber){
        if (action_name == _actions[i].name) {
            (this->*_actions[i].func)(target);
            return ;
        }
        i++;
    }
    std::cout<<"action "<<action_name<<" not found\navailable: melee ranged shout\n";
}