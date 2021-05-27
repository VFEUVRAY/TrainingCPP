/*
** ETNA PROJECT, 21/04/2021 by feuvra_v
** do_a_barrel_roll
** File description:
**      do k rotations in passed vector
*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

std::vector<int> big_roll(std::vector<int> numbers, size_t k)
{
    size_t len = numbers.size();
    k = k % len;
    if (!k)
        return (numbers);
    size_t i = 0;
    std::vector<int> result(len);
    size_t move_value = len - k;
    while (i < len) {
        result[(i + move_value) % len] = numbers[i];
        i = i + 1;
    }
    return (result);
}

std::vector<int> small_roll(std::vector<int> numbers, size_t k)
{
    size_t len = numbers.size();
    k = k % len;
    if (!k)
        return (numbers);
    std::vector<int> temp(k);
    size_t i = 0;
    //size_t y = 0;
    while (i < k) {
        temp[i] = numbers[i];
        i = i + 1;
    }
    numbers.erase(numbers.begin(), numbers.begin() + k);
    i = 0;
    while (i < k) {
        //numbers.push_back(temp[y]);
        numbers.push_back(temp[i]);
        i = i + 1; 
        //y = y + 1;
    }
    //cout<<"size "<<numbers.capacity()<<endl;
    return (numbers);
}

std::vector<int> do_a_barrel_roll(std::vector<int> numbers, size_t k)
{
    if (k > (numbers.size() / 3))
        return (big_roll(numbers, k));
    else
        return (small_roll(numbers, k));
}