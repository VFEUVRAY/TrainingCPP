/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Human
** File description:
**      human for action finder ting
*/

#include <iostream>
#include <string>

struct action_t;

class Human
{
    private:
        void meleeAttack(std::string const& target);
        void rangedAttack(std::string const& target);
        void intimidatingShout(std::string const& target);

        static const action_t _actions[];
        static const int _actionNumber;

        std::string _name;

    public:
        void action(std::string const& action_name, std::string const& target);
        Human(std::string name);
        ~Human();
};