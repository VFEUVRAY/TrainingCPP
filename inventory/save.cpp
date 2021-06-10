/*
** ETNA PROJECT, 09/06/2021 by feuvra_v
** save
** File description:
**      attempt at inventory saving functions
*/

#include "inventory.hpp"
#include <ctype.h>

class Inventory_ctype
{
};

void save(Inventory *inv)
{
    std::ofstream saveStream("inventory.txt");
    std::vector<BaseObject *> *obj_list = inv->getList();
    for (auto it=obj_list->begin() ; it != obj_list->end() ; it++)
        saveStream<<(*it)->name()<<';'<<(*it)->quantity()<<';'<<(*it)->max()<<';'<<(*it)->priority()<<std::endl;
    saveStream.close();
}

void save(Inventory *inv, std::string name)
{
    std::ofstream saveStream(name);
    std::vector<BaseObject *> *obj_list = inv->getList();
    for (auto it=obj_list->begin() ; it != obj_list->end() ; it++)
        saveStream<<(*it)->name()<<';'<<(*it)->quantity()<<';'<<(*it)->max()<<';'<<(*it)->priority()<<std::endl;
    saveStream.close();
}

bool load(Inventory *inv)
{
    std::ifstream loadStream("inventory.txt");
    std::string buff;
    std::string set[4];
    long i = 0;
    long size;
    loadStream.seekg(0, std::ios::end);
    size = loadStream.tellg();
    loadStream.seekg(0, std::ios::beg);
    while (!loadStream.eof()) {
        for (int pos = 0 ; pos < 4 ; pos++){
            std::getline(loadStream, buff, ';');
            std::cout<<buff;
            set[pos] = buff;
            i += buff.size()+1;
        }
        //std::cout<<std::endl<<"set: "<<set[0]<<';'<<set[1]<<';'<<set[2]<<';'<<set[3]<<std::endl;
        //loadStream.get();
    }
    //loadStream.im
    return (1);
}