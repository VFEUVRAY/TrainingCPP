/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** megaphone
** File description:
**      megaphone
*/

#include <iostream>

char *my_capitalize(char *str)
{
    size_t i = 0;
    while (str[i]){
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
        return (0);
    }
    for (size_t i = 1 ; i < argc ; i++) {
        argv[i] = my_capitalize(argv[i]);
        std::cout<<argv[i];
    }
    std::cout<<std::endl;
    return (0);
}