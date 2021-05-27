/*
** ETNA PROJECT, 20/04/2021 by feuvra_v
** playset
** File description:
**      find if string contains duplicates
*/

#include <vector>
#include <iostream>

using namespace std;

bool playset(std::string s)
{
    std::vector<size_t> count(256, 0);
    size_t len = s.size();
    size_t i = 0;
    while (i < len) {
        if (count[s[i]])
            return (true);
        count[s[i]] = 1;
        i = i + 1;
    }
    return (false);
}

int main(int argc, char **argv)
{
    int i = 0;
    std::string s;
    if (argc > 1) {
        while (argv[1][i]) {
            s.push_back(argv[1][i]);
            i = i + 1;
        }
    }
    cout<<playset(s)<<endl;
}