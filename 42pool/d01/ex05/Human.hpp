/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Human
** File description:
**      human header
*/

#include "Brain.hpp"

class Human
{
    public:
        Human();
        ~Human();

        Brain getBrain();
        std::string identify() const;

    private:
        const Brain _brain;
};