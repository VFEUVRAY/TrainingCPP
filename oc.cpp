/*
** ETNA PROJECT, 19/04/2021 by feuvra_v
** open_closed
** File description:
**      check if opening character has closing equivalent
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int add_opener(char c, std::vector<int> *count)
{
    (*count)[c] = (*count)[c] + 1;
    return (1);
}

int sub_ender(char c, std::vector<int> *count)
{
    char opener;

    switch (c) {
        case (')'): 
            opener = '(';
            break;
        case ('>'): 
            opener = '<';
            break;
        case (']'):
            opener = '[';
            break;
        case ('}'): 
            opener = '{';
            break;
    }
    (*count)[opener] = (*count)[opener] - 1;
    return ((*count)[opener]);
}

int dup_openend(char c, std::vector<int> *count)
{
    (*count)[c] = 1 * !(*count)[c];
    return (1);
}

std::vector<int (*)(char, std::vector<int> *)> make_char_array()
{
    std::vector<int (*)(char, std::vector<int> *)> char_array(256, nullptr);
    char_array['"'] = dup_openend;
    char_array['\''] = dup_openend;
    char_array['('] = add_opener;
    char_array[')'] = sub_ender;
    char_array['<'] = add_opener;
    char_array['>'] = sub_ender;
    char_array['['] = add_opener;
    char_array[']'] = sub_ender;
    char_array['{'] = add_opener;
    char_array['}'] = sub_ender;
    return (char_array);
}

bool open_closed(std::string s)
{
    std::vector<int (*)(char, std::vector<int> *)> char_array = make_char_array();
    std::vector<int> count(256, 0);
    size_t i = 0;
    int check_count;

    while (i < s.size()) {
        if (char_array[s[i]]) {
            check_count = char_array[s[i]](s[i], &count);
            if (check_count < 0)
                return (false);
        }
        i = i + 1;
    }
    if (count['"'] + count['\''] + count['('] + count['['] + count['<'] + count['{'])
        return (false);
    return(true);
}


int main() {
    cout<<open_closed("abcde(fg")<<endl;
    return (0);
}