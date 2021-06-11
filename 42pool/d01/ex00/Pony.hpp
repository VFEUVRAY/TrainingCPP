/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** Pony
** File description:
**      pony class ting
*/

#include <iostream>
#include <ostream>
#include <fstream>
#include <random>

class Pony
{
    public:
        Pony();
        Pony(const char *name, const char *breed, const char *color, const int age, const int weight);
        virtual ~Pony();
    
        int birthday();
        void check();

    private:
        static int _pony_count;
        static const char *_namePool[];
        static const char *_breedPool[];
        static const char *_colorPool[];
        static const int _namePoolSize;
        static const int _breedPoolSize;
        static const int _colorPoolSize;
        int _weight;
        int _age;
        const char *_name;
        const char *_breed;
        const char *_color;

        void introduce();

};