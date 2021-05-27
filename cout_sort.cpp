/*
** ETNA PROJECT, 22/05/2021 by feuvra_v
** cout_sort
** File description:
**      cout_sort
*/

#include <vector>
#include <iostream>

using namespace std;

void print_vector(std::vector<int> n)
{
    for (int num : n)
        cout<<num<<" ; ";
    cout<<endl;
}


std::vector<int> count_sort(std::vector<int> n)
{
    int smallest_value = n[0];
    int biggest_value = n[0];
    long long sum;
    std::vector<int> res(n.size());

    for (int num : n) {
        if (num > biggest_value)
            biggest_value = num;
        else if (num < smallest_value)
            smallest_value = num;
    }
    std::vector<int> index(biggest_value + 1, 0);
    for (int num : n)
        index[num]++;
    sum = index[0];
    for (int i = 1 ; i < index.size() ; i++) {
        sum += index[i];
        index[i] = sum;
    }
    print_vector(index);
    for (auto it = n.begin() ; it != n.end() ; it++){
        res[index[*it] - 1] = *it;
        index[*it]--;
    }
    return (res);
}

int main()
{
    std::vector<int> test = {2, 32, 2, 1, 45, 5, 12, 2};
    test = count_sort(test);
    print_vector(test);
    return (0);
}