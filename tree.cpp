/*
** ETNA PROJECT, 11/06/2021 by feuvra_v
** tree
** File description:
**      tree
*/

#include <iostream>
#include <iomanip>

void second_tree(const int tree_size)
{
    int i = 0;
    char *str = new char[tree_size + 1];
    while (i < tree_size){
        str[i] = '*';
        str[i+1] = 0;
        std::cout<<std::setfill(' ')<<std::setw(tree_size)<<std::right<<str<<std::endl;
        i++;
    }
    delete[](str);
}

int main()
{
    int tree_size = 0;
    const int max_size = 7;
    int i = 0;

    while (i < max_size) {
        std::cout<<'*';
        if (tree_size < i){
            ++tree_size;
            continue;
        }
        tree_size = 0;
        std::cout<<std::endl;
        i++;
    }
    second_tree(7);
    return (0);
}