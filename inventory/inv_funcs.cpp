/*
** ETNA PROJECT, 08/06/2021 by feuvra_v
** inv_funcs
** File description:
**      some more inventory functions
*/

#include "inventory.hpp"

bool Inventory::name_sort(std::string a, std::string b)
{
    size_t i = 0;

    while (a[i] && b[i]){
        if (a[i] < b[i])
            return (1);
        i++;
    }
    return (a[i] < b[i]);
}

int Inventory::name_cmp(std::string a, std::string b)
{
    size_t i = 0;

    while (a[i] && b[i]){
        if (a[i] != b[i])
            return (a[i] - b[i]);
        i++;
    }
    return (a[i] - b[i]);
}

BaseObject *Inventory::find(std::string name)
{
    for (auto it = _list->begin() ; it != _list->end() ; it++){
        if (!this->name_cmp(name, (*it)->name()))
            return (*it);
    }
    return (nullptr);
}

void Inventory::addTo(std::string name)
{
    BaseObject *obj = this->find(name);

    if (!obj)
        return ;
    if (obj->add(1))
        std::cout<<name<<" added to your inventory"<<std::endl<<std::endl;
    else
        std::cout<<"You can only hold "<<obj->max()<<" "<<name<<"(s) in your inventory"<<std::endl<<std::endl;
}

void Inventory::addTo(std::string name, int quantity)
{
    BaseObject *obj = this->find(name);

    if (!obj)
        return ;
    if (obj->add(quantity))
        std::cout<<quantity<<" "<<name<<" added to your inventory"<<std::endl<<std::endl;
    else
        std::cout<<"You can only hold "<<obj->max()<<" "<<name<<"(s) in your inventory"<<std::endl<<std::endl;
}