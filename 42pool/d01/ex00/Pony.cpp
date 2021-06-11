/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** Pony
** File description:
**      pony
*/

#include "Pony.hpp"

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *my_strcpy(const char *str)
{
    char *res = new char[my_strlen(str) + 1];
    int i = 0;
    for (; str[i] ; i++)
        res[i] = str[i];
    res[i] = 0;
    return (res);
}

const char *Pony::_namePool[] = {"Charlie", "Socks", "Bean",
                                "John", "Dona", "Fatima", "Jane",
                                "Aboubakr", "Flint", "Cascade",
                                "Spirit", "Magnoliar", "Chocolate", NULL};
const int Pony::_namePoolSize = 13;

const char *Pony::_breedPool[] = {"Appaloosa", "Bashkir Curly",
                                "Clydesdales", "Dales", "Exmoor",
                                "Gotland", "Highland", "Irish Hobby", NULL};
const int Pony::_breedPoolSize = 9;

const char *Pony::_colorPool[] = {"Black", "White", "Cream",
                                    "Brown", "Carmin", "Dotted", NULL};
const int Pony::_colorPoolSize = 6;

int Pony::_pony_count = 0;

void Pony::introduce()
{
    if (_age == 1){
        std::cout<<"A new pony was just born at the Ranch!\n===Introducing==\n"
        <<_name<<" a splendid "<<_breed<<" specimen already boasting "<<_weight<<" pounds of pure cuteness"<<std::endl
        <<_name<<" brings our total population to "<<_pony_count<<std::endl;
        return ;
    }
    std::cout<<"A new pony just arrived at the Ranch!\n===Introducing==\n"
        <<_name<<" a splendid "<<_age<<" years old "<<_breed<<" specimen boasting "<<_weight<<" pounds of pure cuteness"<<std::endl
        <<_name<<" brings our total population to "<<_pony_count<<std::endl;
}

void Pony::check()
{
    std::cout<<_name<<'|'<<_age<<"yo|"<<_weight<<"lbs|"<<_breed<<'|'<<_color<<std::endl;
}

int Pony::birthday()
{
    _age++;
    
    if (_age < 6){
        _weight += 150 + (std::rand() % ((1200 - (_weight * (_weight < 1200)))/5));
        std::cout<<"it is "<<_name<<"'s "<<_age<<"th birthday! Bigman is growing: "<<_weight<<" pounds"<<std::endl;
        return (_age);
    }
    std::cout<<"it is "<<_name<<"'s "<<_age<<"th birthday! Bossman is getting old"<<std::endl;
    return (_age);
}

Pony::Pony()
{
    _weight = (std::rand() % 20) + 190;
    _age = 1;
    _name = _namePool[(std::rand() % _namePoolSize)];
    _breed = _breedPool[(std::rand() % _breedPoolSize)];
    _color = _colorPool[(std::rand() % _colorPoolSize)];
    _pony_count++;
    this->introduce();
}

Pony::Pony(const char *name, const char *breed, const char *color, const int age, const int weight)
{
    _name = name;
    _breed = breed;
    _color = color;
    _age = age;
    _weight = weight;
    _pony_count++;
    this->introduce();
}

Pony::~Pony()
{
    std::cout<<"It is time for "<<_name<<" to leave us, safe travels bigman lil horse :'("<<std::endl;
    _pony_count--;
}
