/*
** ETNA PROJECT, 29/05/2021 by feuvra_v
** cpu_schedule
** File description:
**      idk dude
*/

#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

bool isnum(char c)
{
    return ((c >= '0' && c <= '9'));
}

/**
 * will check if given string contains a military format hour 
 * return index of first number if string is formatted
 * return -1 if not
*/
static int ishour(std::string s)
{
    int res;
    if (s.empty() || s.size() < 5)
        return (-1);
    for (size_t i = 0 ; i < s.size() ; i++) {
        if (s[i] == ':') {
            if (i < 2 || i > (s.size() - 3))
                return (-1);
            res = (isnum(s[i-1]) && isnum(s[i-2]) && isnum(s[i+1]) && isnum(s[i+2])) * i;
            break;
        }
    }
    if (s[res - 2] > '2' || s[res + 1] > '6')
        return (-1);
    if (s[res - 2] == '2' && s[res - 1] > '4')
        return (-1);
    return (res - 2);
}

// following functions expects a string that has already been verified
int military_to_int(std::string s)
{
    int res = -1;
    if (!isnum(s[0]))
        return (res);
    res = (((s[0] - 48) * 10 + (s[1] - 48)) * 60) + ((s[3] - 48) * 10) + s[4] - 48;
    return (res);
}

std::vector<std::pair<int, int>> make_hour_vector(std::string s)
{
    std::string hour;
    std::vector<std::pair<int, int>> hour_vector;
    int i = 0;
    int relative_pos;
    int true_pos;
    int y = 0;
    bool pair_pos = false;
    std::vector<std::pair<int,int>>::iterator hour_iterator;

    while (i < s.size()) {
        relative_pos = ishour(&s[i]);
        //std::cout<<&s[i]<<std::endl;
        if (relative_pos == -1)
            break;
        if (!pair_pos){
            hour_vector.push_back(std::pair<int,int> (military_to_int(&s[i + relative_pos]), -1));
            hour_iterator = hour_vector.end() - 1;
        } else
            hour_iterator->second = military_to_int(&s[i + relative_pos]);
        pair_pos = pair_pos xor 1;
        if (y < 5)
            std::cout<<"bef : "<<i<<std::endl;
        i = i + 6 + relative_pos;
        if (y < 5)
            std::cout<<"af : "<<i<<std::endl;
        y++;
    }
    std::cout<<"==============="<<std::endl;
    for (auto it = hour_vector.begin() ; it != hour_vector.end() ; it++)
        std::cout<<it->first<<" : "<<it->second<<std::endl;
    return (hour_vector);
}

std::bitset<1440> make_schedule(std::vector<std::pair<int,int>> hour_vector)
{
    std::bitset<1440> res;
    int bitset_pos;
    for (auto it = hour_vector.begin() ; it != hour_vector.end() ; it++) {
        bitset_pos = it->first;
    std::cout<<"first : "<<it->first<<" : seond : "<<it->second<<std::endl;
        while (bitset_pos < it->second){
            res[bitset_pos] = 1;
            bitset_pos++;
        }
    }
    std::cout<<res.to_string()<<std::endl;
    return (res);
}

/*
std::bitset<1440> inset_process(std::bitset<1440> schedule, std::string hour)
{
    std::pair
}
*/
int main()
{
    std::string test;
    std::string str = "[01:21]";
    test.reserve(2);
    test.push_back('a');
    test.push_back('b');
    std::cout<<test<<std::endl;
    std::cout<<ishour(str)<<std::endl;
    std::cout<<military_to_int(&str[1])<<std::endl;
    std::vector<std::pair<int, int>> hour_vector;
    hour_vector = make_hour_vector("[[\"10:00\",\"11:00\"],[\"14:00\",\"16:00\"],[\"23:00\",\"23:30\"]]");
    make_schedule(hour_vector);
    return (0);
}