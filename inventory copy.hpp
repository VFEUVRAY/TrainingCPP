#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class Inventory
{
    public:
        Inventory()
        {   _totalSpace = 20;
            _space = 20;
            _list = new std::vector<BaseObject> (0);
        }
        virtual ~Inventory(){}

    public:
        void show()
        {
            if ((_list->begin() + 1) == _list->end()){
                std::cout<<"Empty"<<std::endl;
                return ;
            }
            for (auto it = _list->begin() ; it != _list->end() ; it++)
                std::cout<<it->name()<<std::endl;
        }

        void showDetails()
        {
            if ((_list->begin() + 1) == _list->end()){
                std::cout<<"Empty"<<std::endl;
                return ;
            }
            std::cout<<"Name ; Quantity ; Max Quantity ; Priority"<<std::endl;
            for (auto it = _list->begin() ; it != _list->end() ; it++)
                std::cout<<it->name()<<" ; "<<it->quantity()<<" ; "<<it->max()<<" ; "<<it->priority()<<std::endl;
        }

    private:
        std::vector<BaseObject> *_list;
        int _totalSpace;
        int _space;
};

class BaseObject
{
    public:
        BaseObject(Inventory *i)
        {
            _inventory = i;
            _name = "dummy";
            _quantity = 1;
            _maxQuantity = 1;
            _priority = INT32_MAX;
        }
        BaseObject(Inventory *i, std::string name, int quantity, int max, int priority)
        {
            _inventory = i;
            _name = name;
            _quantity = quantity;
            _maxQuantity = max;
            _priority = priority;
        }
        virtual ~BaseObject(){};

    public:
        std::string name() {return _name;}
        int quantity() {return _quantity;}
        int max() {return _maxQuantity;}
        bool addOk(int x) {return ((x + _quantity) > _maxQuantity);}
        int priority() {return _priority;}
        Inventory *getInvId() {return _inventory;}

        bool add(int x) 
        {
            if (BaseObject::addOk(x))
                return 0;
            _quantity += x;
            return (1);
        }

    private:
        std::string _name;
        Inventory *_inventory;
        int _quantity;
        int _maxQuantity;
        int _priority;
};