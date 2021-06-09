/*
** ETNA PROJECT, 09/06/2021 by feuvra_v
** sort
** File description:
**      sorting functions for inventory class
*/

#include "inventory.hpp"

bool Inventory::name_sort(std::string const& a, std::string const& b)
{
    size_t i = 0;

    while (a[i] && b[i]){
        if (a[i] < b[i])
            return (1);
        i++;
    }
    return (a[i] < b[i]);
}

struct Inventory::comp{
    bool operator() (BaseObject *a, BaseObject *b) 
    {
        bool name_diff;
        if (a->priority() == b->priority()){
            name_diff = Inventory::name_sort(a->name(), b->name());
            if (name_diff == 0)
                return (a->quantity() < b->quantity());
            return (name_diff);
        }
        return (a->priority() < b->priority());
    }
} Inventory_comp;

void Inventory::sort()
{
    std::sort(_list->begin(), _list->end(), Inventory_comp);
}