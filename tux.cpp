/*
** ETNA PROJECT, 22/04/2021 by feuvra_v
** tux
** File description:
**      deduce pivot of passed int vector
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct pivot_stack_s {
    int value;
    struct pivot_stack_s *prev;
} pivot_stack_t;

int tux(std::vector<int> numbers)
{
    size_t i = 1;
    int temp = 0;
    int res = -1;
    int biggest_val = numbers[0];
    size_t len;

    if (numbers.size() < 2)
        return (numbers.size() - 1);
    len = numbers.size() - 1;
    if (numbers[0] <= numbers[1])
        res = 0;
    while (i < len) {
        if (numbers[i] > numbers[i - 1])
            biggest_val = numbers[i];
        cout<<"temp: "<<numbers[temp]<<endl;
        if (numbers[i] > numbers[temp] && numbers[i] <= numbers[i + 1] && numbers[i] >= biggest_val) {
            temp = i;
            res = i;
        } else if (numbers[temp] > numbers[i])
            res = -1;
        i = i + 1;
    }
    if (numbers[i] > numbers[i - 1] && numbers[i] > numbers[temp] && numbers[i] >= biggest_val)
        res = i;
    if (numbers[temp] > numbers[i])
        res = -1;
    return (res);
}

pivot_stack_t *push_stack(pivot_stack_t *stack, int value)
{
    cout<<"pushed"<<endl;
    pivot_stack_t *temp = (pivot_stack_t *) malloc(sizeof(pivot_stack_t));
    if (!temp)
        return (nullptr);
    temp->value = value;
    temp->prev = stack;
    return (temp);
}

pivot_stack_t *pop_stack(pivot_stack_t *stack)
{
    cout<<"popped"<<endl;
    pivot_stack_t *temp = stack->prev;
    free(stack);
    return (temp);
}

int check_and_return_last(pivot_stack_t *stack, std::vector<int> numbers, int biggest_val)
{
    while (stack && numbers[stack->value] > numbers[numbers.size() - 1])
        stack = pop_stack(stack);
    if (numbers[numbers.size() - 1] > biggest_val)
        return (numbers.size() - 1);
    if (!stack)
        return (-1);
    return (stack->value);
}

int tux_stack(std::vector<int> numbers)
{
    size_t i = 1;
    int res = -1;
    int biggest_val = numbers[0];
    pivot_stack_t *stack = nullptr;

    if (numbers.size() < 2)
        return (numbers.size() - 1);
    if (numbers[0] <= numbers[1])
        stack = push_stack(stack, 0);
    while (i < numbers.size() - 1) {
        while (stack && numbers[stack->value] > numbers[i])
            stack = pop_stack(stack);
        if (numbers[i] > biggest_val && numbers[i] <= numbers[i + 1])
            stack = push_stack(stack, i);
        if (numbers[i] > biggest_val)
            biggest_val = numbers[i];
        i = i + 1;
    }
   return (check_and_return_last(stack, numbers, biggest_val));
}

int main()
{
    std::vector<int> test{1, 1, 1};
    int res = tux_stack(test);
    cout<<res<<endl;
    cout<<sizeof(test[0])<<endl;
    return 0;
}