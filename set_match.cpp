/*
** ETNA PROJECT, 16/05/2021 by feuvra_v
** set_match
** File description:
**      set_match
*/

#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

bool set_et_match(std::vector<int> numbers, int n)
{
    std::unordered_map<int,bool> nummap(numbers.size());
    size_t i = 0;
    auto it = nummap.begin();
    int target;

    while (i < numbers.size()) {
        target = n - numbers[i];
        it = nummap.find(target);
        if (it != nummap.end())
            return (true);
        nummap.insert(std::pair<int,bool>(numbers[i], true));
        i++;
    }
    return (false);
}

int main()
{
    std::vector<int> test{1, 2, 3, 4, 5};
    cout<<set_et_match(test, 8)<<endl;
    return (1);
}