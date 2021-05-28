#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int tux(std::vector<int> numbers)
{
	std::stack<size_t> pivot_stack;
    size_t i = 0;
    int res;

    if (numbers.size() < 2)
        return (numbers.size() - 1);
    int biggest_val = numbers[0];
    pivot_stack.push(0);
    while (i < numbers.size()) {
        while (!pivot_stack.empty() && numbers[pivot_stack.top()] > numbers[i])
            pivot_stack.pop();
        if (numbers[i] > biggest_val){
            pivot_stack.push(i);
            biggest_val = numbers[i];
        }
        i++;
    }
    if (pivot_stack.empty())
        return (-1);
    return (pivot_stack.top());
}

int main()
{
    std::stack<int> s;
    std::vector<int> test = {97, 98, 97, 99, 99, 99, 117, 108, 101, 118, 100};
    s.push(12);
    s.push(21);
    s.push(32);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    cout<<tux(test)<<endl;
    return (0);
}