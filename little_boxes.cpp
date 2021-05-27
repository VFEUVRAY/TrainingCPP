/*
** ETNA PROJECT, 17/05/2021 by feuvra_v
** little_boxes
** File description:
**      little_boxes
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

std::string little_boxes(std::string s)
{
    std::sort(s.begin(), (s.begin() + s.size()));
    return (s);
}

void swap_char(char *a, char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

std::string lb(std::string s)
{
    size_t i = 0;
    size_t offset;
    unsigned char current_char = 0;
    char swap;

    while (current_char < 128) {
        offset = i;
        while (offset < s.size()) {
            if (s[offset] == current_char) {
                swap = s[i];
                s[i] = s[offset];
                s[offset] = swap;
                i++;
            }
            offset++;
        }
        current_char++;
    }
    return (s);
}

int main()
{
    std::string test = "_beeillosttx\n";
    test = lb(test);
    cout<<test<<endl;
    cout<<sizeof(size_t)<<endl;
    return (0);
}