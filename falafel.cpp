/*
** ETNA PROJECT, 21/04/2021 by feuvra_v
** falafel
** File description:
**      deduct if passed string can be a palindrome once permutted
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <chrono>


using namespace std;
using namespace chrono;

typedef struct character_list_s {
    unsigned char c;
    struct character_list_s *prev;
} charlist_t;

bool even_palindrome(std::string s)
{
    std::vector<size_t> count(256, 0);
    charlist_t *chars = nullptr;
    charlist_t *temp;
    size_t i = 0;
    size_t len = s.size();
    while (i < len) {
        if (!count[s[i]]) {
            temp = (charlist_t *) malloc(sizeof(charlist_t));
            temp->c = s[i];
            temp->prev = chars;
            chars = temp;
        }
        count[s[i]]++;
        i = i + 1;
    }
    while (chars) {
        if (count[chars->c] % 2)
            return (false);
        chars = chars->prev;
    }
    return (true);
}

bool odd_palindrome(std::string s)
{
    std::vector<size_t> count(256, 0);
    charlist_t *chars = nullptr;
    charlist_t *temp;
    size_t i = 0;
    size_t len = s.size();
    bool odd_count = false;
    while (i < len) {
        if (!count[s[i]]) {
            temp = (charlist_t *) malloc(sizeof(charlist_t));
            temp->c = s[i];
            temp->prev = chars;
            chars = temp;
        }
        count[s[i]]++;
        i = i + 1;
    }
    while (chars) {
        if (count[chars->c] % 2) {
            if (odd_count)
                return (false);
            odd_count = true;
        }
        chars = chars->prev;
    }
    cout<<count.capacity()<<endl;
    return (true);
}

bool falafel(std::string s)
{
    if (s.size() % 2)
        return (odd_palindrome(s));
    else
        return (even_palindrome(s));
}

bool even_pal(std::string s)
{
    std::bitset<256> is_even;

    cout<<sizeof(is_even)<<endl;
    for (auto it = s.begin() ; it != s.end() ; it++)
        is_even[*it] = is_even[*it] xor 1;
    for (auto it = s.begin() ; it != s.end() ; it++){
        if (is_even[*it])
            return(false);
    }
    return (true);
}

bool odd_pal(std::string s)
{
    std::bitset<256> is_even;
    bool odd_count = false;
    char odd_char;

    for (auto it = s.begin() ; it != s.end() ; it++)
        is_even[*it] = is_even[*it] xor 1;
    for (auto it = s.begin() ; it != s.end() ; it++){
        cout<<sizeof(it)<<endl;
        if (is_even[*it]){
            if (odd_count && *it != odd_char)
                return(false);
            odd_count = true;
            odd_char = *it;
        }
    }
    return (true);
}

bool falafel2(std::string s)
{
    if (s.size() % 2)
        return (odd_pal(s));
    else
        return (even_pal(s));
}

int main()
{
    bool i = 1 ^ 1;
    i = i ^ 1;
    i = i ^ 1;
    std::string s = "test";
    cout<<falafel("kaaak")<<endl;
    auto start = high_resolution_clock::now();
    cout<<falafel2("kaaak")<<endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"duration "<<duration.count()<<endl;
    //cout<<i<<endl;
    for (auto it = s.begin() ; it != s.end() ; it++)
    //    cout<<*it<<endl;
    return 0;
}