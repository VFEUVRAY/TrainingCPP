#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class BaseObject;
class Inventory;
class Invetory_ctype;

//bool object_comp(BaseObject a, BaseObject b);
void save(Inventory *inv);
void save(Inventory *inv, std::string name);
bool load(Inventory *inv);

class BaseObject
{
    public:
        //BaseObject(){}
        BaseObject(Inventory *i) : _inventory(i)
        {
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

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory(){}

    public:
        void show()
        {
            if (_list->empty()){
                std::cout<<"Empty"<<std::endl;
                return ;
            }
            for (auto it = _list->begin() ; it != _list->end() ; it++)
                std::cout<<(*it)->name()<<std::endl;
        }

        void showDetails()
        {
            if ((_list->begin() + 1) == _list->end()){
                std::cout<<"Empty"<<std::endl;
                return ;
            }
            std::cout<<"Name ; Quantity ; Max Quantity ; Priority"<<std::endl;
            for (auto it = _list->begin() ; it != _list->end() ; it++)
                std::cout<<(*it)->name()<<" ; "<<(*it)->quantity()<<" ; "<<(*it)->max()<<" ; "<<(*it)->priority()<<std::endl;
            std::cout<<std::endl<<"Left space: "<<_space<<" out of: "<<_totalSpace<<std::endl;
        }

        void add(BaseObject *obj)
        {
            if (_space > 0){
                _list->push_back(obj);
                _space--;
            }
        }

        struct comp;

        void sort();

        std::vector<BaseObject *> *getList(){return _list;}

        int name_cmp(std::string const& a, std::string const& b);

        static bool name_sort(std::string const& a, std::string const& b);

        BaseObject *find(std::string const& name);

        bool addTo(std::string name);

        bool addTo(std::string name, int quantity);

    private:
        std::vector<BaseObject *> *_list;
        int _totalSpace;
        int _space;
};

