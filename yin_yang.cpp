/*
** ETNA PROJECT, 24/04/2021 by feuvra_v
** yin_yang
** File description:
**      find opening and closing tags in there corret opening order
*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

static bool yin_yang_error = false;

typedef struct stack_s {
    unsigned char data;
    struct stack_s *prev;
} stack_t;

static stack_t *push_stack(stack_t *stack, unsigned char data)
{
    //cout<<data<<endl;
    stack_t *temp = (stack_t *) malloc(sizeof(stack_t));
    if (!temp)
        return (nullptr);
    temp->data = data;
    temp->prev = stack;
    return (temp);
}

static stack_t *pop_stack(stack_t *stack)
{
    stack_t *temp = stack->prev;
    free(stack);
    return (temp);
}

static stack_t *check_paranthesis(stack_t *stack, unsigned char c) {
    if (!stack || stack->data != '(') {
        yin_yang_error = true;
        return (stack);
    }
    return (pop_stack(stack));
}

static stack_t *check_bracket(stack_t *stack, unsigned char c) {
    if (!stack || stack->data != '[') {
        yin_yang_error = true;
        return (stack);
    }
    return (pop_stack(stack));
}

static stack_t *check_curly(stack_t *stack, unsigned char c) {
    if (!stack || stack->data != '{') {
        yin_yang_error = true;
        return (stack);
    }
    return (pop_stack(stack));
}

static stack_t *check_gt(stack_t *stack, unsigned char c) {
    if (!stack || stack->data != '<') {
        yin_yang_error = true;
        return (stack);
    }
    return (pop_stack(stack));
}

static stack_t *check_quotes(stack_t *stack, unsigned char c) {
    if (!stack)
        return (push_stack(stack, c));
    if (stack->data == c)
        return (pop_stack(stack));
    return (push_stack(stack, c));
}

std::vector<stack_t *(*)(stack_t *, unsigned char)> make_function_vector()
{
    std::vector<stack_t *(*)(stack_t *, unsigned char)> func_vector(256, nullptr);
    func_vector['"'] = check_quotes;
    func_vector['\''] = check_quotes;
    func_vector['('] = push_stack;
    func_vector['['] = push_stack;
    func_vector['{'] = push_stack;
    func_vector['<'] = push_stack;
    func_vector[')'] = check_paranthesis;
    func_vector[']'] = check_bracket;
    func_vector['}'] = check_curly;
    func_vector['>'] = check_gt;
    return (func_vector);
}

void print_stack(stack_t *stack)
{
    while (stack) {
        cout<<stack->data<<" ; ";
        stack = stack->prev;
    }
}

bool yin_yang(std::string s)
{
    std::vector<stack_t *(*)(stack_t *, unsigned char)> func_vector = make_function_vector();
    stack_t *opener_stack = nullptr;

    for (auto it = s.begin() ; it != s.end() ; it++) {
        if (func_vector[*it])
            opener_stack = func_vector[*it](opener_stack, *it);
        if (yin_yang_error)
            return (false);
    }
    print_stack(opener_stack);
    if (opener_stack)
        return (false);
    return (true);
}

int main()
{
    std::string s = "[(')attention')";
    cout<<yin_yang(s)<<endl;
}