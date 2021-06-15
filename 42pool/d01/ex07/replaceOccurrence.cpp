/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** replaceOccurrence
** File description:
**      functions regarding replacing occurence of s1 by s2
*/

#include "replace.hpp"

std::string replaceWord(std::string &str, const std::string &s1, const std::string &s2)
{
    size_t i = str.find(s1);
    while (i != SIZE_MAX){
        str.replace(i, s1.length(), s2);
        i = str.find(s1, i + 1);
    }
    return (str);
}