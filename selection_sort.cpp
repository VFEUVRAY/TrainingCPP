/*
** ETNA PROJECT, 23/05/2021 by feuvra_v
** selection_sort
** File description:
**      selection sort for training
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(std::vector<int> n)
{
    for (int num : n)
        cout<<num<<" ; ";
    cout<<endl;
}

std::vector<int> selection_sort(std::vector<int> n)
{
    size_t i = 0;
    size_t swap_pos;

    if (n.size() == 0 || n.size() == 1)
        return (n);
    while (i < n.size() - 1) {
        swap_pos = i;
        for (size_t pos = i+1 ; pos < n.size() ; pos++) {
            if (n[pos] < n[swap_pos])
                swap_pos = pos;
        }
        if (swap_pos != i){
            n[i] += n[swap_pos];
            n[swap_pos] = n[i] - n[swap_pos];
            n[i] -= n[swap_pos];
        }
        i++;
    }
    return (n);
}

int main()
{
    std::vector<int> test = {2, 1};
    test = selection_sort(test);
    print_vector(test);
    return (0);
}