/*
** ETNA PROJECT, 02/06/2021 by feuvra_v
** deux
** File description:
**      truc
*/

#include <fstream>
#include <iostream>

int main()
{
    std::fstream file("dummy.txt");
    std::streampos size;
    char *s;
    if (!file.is_open()) {
        std::cout<<"File not found"<<std::endl;
        return (84);
    }
    /*
    file.seekg(0, std::ios::end);
    size = file.tellg();
    file.seekg(0);
    s = new char[size];
    file.read(s, size);
    std::cout<<s;
    file.seekg(0, std::ios::end);
    file<<std::endl<<"appended"<<std::endl;
    file.close();
    */
    std::string str;
    std::getline(file, str);
    std::cout<<str;
    return (0);
}