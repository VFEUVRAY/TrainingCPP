/*
** ETNA PROJECT, 19/04/2021 by feuvra_v
** daemon
** File description:
**      daemon
*/

#include <iostream>
#include <vector>

using namespace std;

bool daemon(std::vector<int> numbers, size_t k)
{
    int current_spot = k - 1;
    if (numbers.size() < 1 || k > numbers.size())
        return (false);
    while (current_spot >= 0) {
        if (numbers[current_spot] >= numbers[k])
            return (false);
        current_spot--;
    }
    current_spot = k + 1;
    while (current_spot < numbers.size()) {
        if (numbers[current_spot] < numbers[k])
            return (false);
        current_spot++;
    }
    return (true);
}

int main()
{
    vector<int> test = {100, 97, 101, 109, 111, 110};
    vector<int> test2 = {100, 97, 101, 109, 111, 110};
    vector<int> test3 = {100, 97, 101, 109, 111, 110};
    vector<int> test4 = {1, 3, 2};
    cout<<daemon(test, 1)<<endl;
    cout<<daemon(test2, 2)<<endl;
    cout<<daemon(test4, 2)<<endl;
    return (0);
}