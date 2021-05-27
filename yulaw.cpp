/*
** ETNA PROJECT, 20/04/2021 by feuvra_v
** yulaw
** File description:
**      find and erase duplicates of characters in string
*/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


std::string yulaw2(std::string s)
{
    std::vector<bool> char_ispresent(256, 0);
    size_t i = 0;
    size_t len = s.size();

    while (i < len) {
        if (char_ispresent[s[i]]) {
            char_ispresent[s[i]] = 0;
            s.erase(s.begin() +  i);
            len = len - 1;
            i = i - 1;
        }
        else
            char_ispresent[s[i]] = 1;
        i = i + 1;
    }
    return (s);
}
std::string yulaw(std::string s)
{
    std::bitset<256> char_ispresent;
    std::string result = {};
    size_t i = 0;

    while (i < s.size()) {
        /*
        if (char_ispresent[s[i]]) {
            //char_ispresent[s[i]] = 0;
            //s.erase(s.begin() +  i);
            //len = len - 1;
            //i = i - 1;
        }
        */
        if (!char_ispresent[s[i]]) {
            char_ispresent[s[i]] = 1;
            result.push_back(s[i]);
        }
        i = i + 1;
    }
    return (result);
}

int main()
{
    std::string s = "";
    cout<<yulaw(s)<<endl;
    return (0);
}