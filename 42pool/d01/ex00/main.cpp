/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** main
** File description:
**      main
*/

#include "Pony.hpp"

Pony ponyOntheStack()
{
    Pony res;
    return (res);
}

Pony ponyOntheStack(const char *name, const char *breed, const char *color, const int age, const int weight)
{
    Pony res(name, breed, color, age, weight);
    return (res);
}

Pony *ponyOnTheHeap()
{
    Pony *res = new Pony();
    return (res);
}

Pony *ponyOnTheHeap(const char *name, const char *breed, const char *color, const int age, const int weight)
{
    Pony *res = new Pony(name, breed, color, age, weight);
    return (res);
}

int main()
{
    Pony *pon = new Pony();
    Pony *pon2 = new Pony();
    Pony *pon3 = new Pony("Francis", "jsp", "mauve", 12, 1200);
    Pony stackPon = ponyOntheStack();
    Pony *heapPon = ponyOnTheHeap("bernard", "hey", "vert", 29, 1440);
    pon->birthday();
    pon->check();
    pon2->check();
    delete (pon);
    delete (pon2);
    delete (pon3);
    delete (heapPon);
    return (1);
}