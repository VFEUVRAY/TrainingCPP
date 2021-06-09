/*
** ETNA PROJECT, 08/06/2021 by feuvra_v
** inventory_sort
** File description:
**      making some mock program to show some logic to a friend
*/

#include "inventory.hpp"
#include <functional>

/*
BaseObject::BaseObject(Inventory *i) : _inventory(i)
{
    _name = "dummy";
    _quantity = 1;
    _maxQuantity = 1;
    _priority = INT32_MAX;   
}
*/
Inventory::Inventory()
{   _totalSpace = 20;
    _space = 20;
    _list = new std::vector<BaseObject *> (0);
}

bool obj_strcmp(std::string a, std::string b)
{
    size_t i = 0;

    while (a[i] && b[i]) {
        if (a[i] < b[i])
            return (true);
        i++;
    }
    return (a[i] < b[i]);
}

int my_strcmp(std::string const& a, std::string const& b)
{
    size_t i(0);

    while (a[i] && b[i]){
        if (a[i] != b[i])
            return (a[i] - b[i]);
        i++;
    }
    return (a[i] - b[i]);
}

bool object_comp(const std::vector<BaseObject *>::iterator a, const std::vector<BaseObject *>::iterator b)
{
    if ((*a)->priority() == (*b)->priority()) {
        return (obj_strcmp((*a)->name(), (*b)->name()));
    }
    return ((*a)->priority() < (*b)->priority());
}

bool object_comp(BaseObject *a,BaseObject *b)
{
    if (a->priority() == b->priority()) {
        return (obj_strcmp(a->name(), b->name()));
    }
    return (a->priority() < b->priority());
}

struct mycomp{
    bool operator() (BaseObject *a, BaseObject *b)
    {
        if (a->priority() == b->priority()) {
            return (obj_strcmp(a->name(), b->name()));
        }
        return (a->priority() < b->priority());
    }
} my_comp;



int main()
{
    Inventory *new_inv = new Inventory();
    BaseObject *obj = new BaseObject(new_inv);
    BaseObject *apple = new BaseObject(new_inv, "Apple", 1, 20, 2);
    BaseObject *sword = new BaseObject(new_inv, "Sword", 1, 1, 1);
    new_inv->show();
    new_inv->add(obj);
    new_inv->show();
    new_inv->add(apple);
    new_inv->add(sword);
    new_inv->add(new BaseObject(new_inv, "Axe", 1, 1, 1));
    new_inv->add(new BaseObject(new_inv, "Axe", 1, 1, 1));
    new_inv->showDetails();
    auto obj_list = new_inv->getList();
    /*
    std::cout<<object_comp(obj_list[0], obj_list[2]);
    for (auto it = obj_list.begin() ; it != obj_list.end() ; it++)
        std::cout<<(*it)->name()<<std::endl;
    for (auto it = obj_list.begin() ; it != obj_list.end() ; it++)
        std::cout<<(*it)->name()<<std::endl;
    */
    new_inv->addTo("Apple");
    new_inv->addTo("Apple", 7);
    new_inv->addTo("Axe", 30);
    std::cout<<std::endl<<"Sorting by priority then name..."<<std::endl<<std::endl;
    
    std::sort(obj_list->begin(), obj_list->end(), my_comp);
    new_inv->showDetails();
    auto len = obj_list->size();
    std::string input("default");
    while (1){
        std::cout<<std::endl<<"please enter name of item wanted: ";
        std::getline(std::cin, input);
        std::cout<<std::endl;
        if (my_strcmp(input, "quit") == 0)
            break;
        if (my_strcmp(input, "show") == 0)
            new_inv->showDetails();
        else
            new_inv->addTo(input);
    }
    std::cout<<"Goodbye"<<std::endl;
    for (size_t i = 0 ; i<len ; i++)
        delete (*obj_list)[i];
    delete (new_inv->getList());
    delete (new_inv);
    return (0);
}