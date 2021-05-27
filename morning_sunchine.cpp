/*
** ETNA PROJECT, 24/04/2021 by feuvra_v
** morning_sunchine
** File description:
**      return vector with only elements strictly greater than their successors
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(std::vector<int> numbers)
{
    for (auto it = numbers.begin() ; it != numbers.end() ; it++)
        cout<<*it<<" ; ";
    cout<<endl;
}

std::vector<int> morning_sunchine(std::vector<int> numbers)
{
    size_t i = numbers.size() - 2;
    int biggest_value = numbers[numbers.size() - 1];
    while (i > 0) {
        if (numbers[i] <= biggest_value)
            numbers.erase(numbers.begin() + i);
        i = i - 1;
    }
    return (numbers);
}

/**
 * Attempt at making O(n) + O(1) memory.
 * Was trying to swap members around to drag biggest to the begginning then delete the rest in one chunk
 * Becomes a sorting algorithm => probably O(nlog(n)) at max but O(1) memory
 * Not Finished
 * */

std::vector<int> morning_swap(std::vector<int> numbers)
{
    size_t swap_pos = numbers.size() - 1;
    size_t i = swap_pos - 1;

    print_vector(numbers);
    while (i > 0) {
        if(numbers[i] <= numbers[i + 1]) {
            numbers[i] += numbers[swap_pos];
            numbers[swap_pos] = numbers[i] - numbers[swap_pos];
            numbers[i] -= numbers[swap_pos];
            swap_pos--;
        }
        print_vector(numbers);
        i--;
    }
    numbers.erase(numbers.begin() + swap_pos + 1, numbers.begin() + numbers.size());
    return (numbers);
}

/**
 * Progressively increase max_value elements have to be bigger than
 * Push those in the vector => Vector is good but in reverse O(n) Time + O(n) memory
 * Reverse the vector => puts it back in order, is quick, no additional memory O(n/2) = O(n) time + O(1) memory
 * return
 * O(2n) = O(n) time
 * O(n + constants from variables) = O(n) memory
 * */

std::vector<int> morning_badmem(std::vector<int> numbers)
{
    if (numbers.size() < 2)
        return (numbers);
    size_t i = numbers.size() - 2;
    std::vector<int> result;
    int biggest_value = numbers[i + 1];
    result.push_back(numbers[i+1]);

    while ((i + 1) > 0) {
        if (numbers[i] > biggest_value){
            result.push_back(numbers[i]);
            biggest_value = numbers[i];
        }
        i--;
    }
    i++;
    /*
    while (i < (result.size() / 2)) {
        result[i] += result[(result.size() - 1 - i)];
        result[(result.size() - 1 - i)] = result[i] - result[(result.size() - 1 - i)];
        result[i] -= result[(result.size() - 1 - i)];
        i++;
    }
    */
    std::reverse(result.begin(), result.end());
    return (result);
}

std::vector<int> morning_sort(std::vector<int> numbers)
{
    size_t delete_range = numbers.size() - 1;
    int biggest_value = numbers[delete_range - 1];

    for (auto it = numbers.begin() ; it != numbers.end() ; it++) {
        if (*it < *(it+1))
            delete_range = delete_range - 1;
        if (*it > biggest_value)
            biggest_value = *it;
    }
    cout<<"delete range "<<delete_range<<endl;
    std::sort(numbers.begin(), numbers.begin() + numbers.size(), greater<int>());
    return (numbers);
}

int main()
{
    size_t i = 0;
    std::vector<int> test{16, 3, 5, 2, 13, 4};
    test = morning_badmem(test);
    print_vector(test);
    return (0);
}