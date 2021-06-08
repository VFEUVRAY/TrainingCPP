/*
** ETNA PROJECT, 30/05/2021 by feuvra_v
** dico_search
** File description:
**      search for number in ordered vector
*/

#include <vector>
#include <algorithm>
#include <iostream>

int check_last(int num, int target, int current)
{
    if (num == target)
        return (current);
    else
        return (-1);
}

int binary_search(std::vector<int> numbers, const int target)
{
    int lower_lim = 0;
    int upper_lim = numbers.size() - 1;
    int current = (lower_lim + upper_lim) / 2;

    while (numbers[current] != target) {
        if (lower_lim == (upper_lim - 1))
            return (check_last(numbers[current + 1], target, current + 1));
        if (target < numbers[current])
            upper_lim = current;
        else
            lower_lim = current;
        current = (lower_lim + upper_lim) / 2;
        std::cout<<"lower : "<<lower_lim<<" : upper : "<<upper_lim<<std::endl;
    }
    return (current);
}

int main()
{
    std::vector<int> test = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    std::cout<<binary_search(test, 11)<<std::endl;
    std::cout<<binary_search(test, 12)<<std::endl;
    std::cout<<binary_search(test, 13)<<std::endl;
    std::cout<<binary_search(test, 14)<<std::endl;
    std::cout<<binary_search(test, 15)<<std::endl;
    std::cout<<binary_search(test, 16)<<std::endl;
    std::cout<<binary_search(test, 17)<<std::endl;
    std::cout<<binary_search(test, 18)<<std::endl;
    std::cout<<binary_search(test, 19)<<std::endl;
    std::cout<<binary_search(test, 0)<<std::endl;
    return (0);
}