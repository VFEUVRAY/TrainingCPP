/*
** ETNA PROJECT, 14/06/2021 by feuvra_v
** cat
** File description:
**      dedaed
*/

#include <iostream>
#include <string>
#include <fstream>

void my_read()
{
    char c = 0;
    while (c != '\n'){
        std::cin.get(c);
        std::cout<<c;
    }
    if (!std::cin.eof())
        my_read();
}

int main()
{
    my_read();
    return (0);
}