/*
** ETNA PROJECT, 18/05/2021 by feuvra_v
** barrel_roll
** File description:
**      barrel_roll
*/

#include <iostream>
#include <vector>

using namespace std;

std::vector<int> do_a_barrel_roll(std::vector<int> numbers, size_t k)
{
    if (!numbers.size())
        return (numbers);
    k = k % numbers.size();
    if (!k)
        return (numbers);
    size_t tortue = 0;
    size_t lievre = k;
    size_t count = numbers.size() - k;
    size_t truc = 0;
    char temp;

    while (lievre < numbers.size() &&  truc < count) {
        temp = numbers[tortue];
        numbers[tortue] = numbers[lievre];
        numbers[lievre] = temp;
        tortue++;
        if (lievre != (numbers.size() - 1))
            lievre++;
        else
            truc++;
    }
    if (!(numbers.size() % 2)) {
        while (tortue < (numbers.size() - 1)) {
            temp = numbers[tortue + 1];
            numbers[tortue + 1] = numbers[tortue];
            numbers[tortue] = temp;
            tortue++;
        }
    }
    return(numbers);
}

std::vector<int> rand_vector(int n) {
    //int lim = rand() % 500 + 1;
    vector<int> result{};

    for (int i = 0 ; i < 20 ; i++) {
        result.push_back(rand() % 100 + 1);
    }
    return (result);
}

void print_vector(std::vector<int> n)
{
    for (int num : n)
        cout<<num<<" : ";
    cout<<endl;
}

std::vector<int> roll(std::vector<int> numbers, size_t k)
{
    if (!numbers.size() || !(k % numbers.size()))
        return (numbers);
    k = k % numbers.size();
    size_t new_pos = (k + (numbers.size() - k)) % numbers.size();
    int temp = numbers[new_pos];
    int to_apply = numbers[k];

    for (int i = 0 ; i < numbers.size() ; i++) {
        cout<<"current pos: "<<new_pos<<endl;
        numbers[new_pos] = to_apply;
        new_pos = (new_pos + (numbers.size() - k)) % numbers.size();
        to_apply = temp;
        temp = numbers[new_pos];
        print_vector(numbers);
    }
    return (numbers);
}

int main()
{
    std::vector<int> test{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> random = rand_vector(1);

    for (int num : test) {
        cout<<num<<" ; ";
    }
    cout<<endl;
    test = roll(test, 3);
    for (int num : test) {
        cout<<num<<" ; ";
    }
    cout<<endl;
    return(1);
}