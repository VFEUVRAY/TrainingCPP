/*
** ETNA PROJECT, 02/06/2021 by feuvra_v
** test
** File description:
**      
*/

#include <fstream>
#include <ostream>
#include <iostream>

int main ()
{
    std::fstream file;
    file.open("dummy.txt", std::ios::app);
    if (file.is_open())
        std::cout<<"file found"<<std::endl;
    else{
        std::cout<<"not found"<<std::endl;
        return (84);
    }
    /*
    file.seekp(0, std::ios::end);
    file<<"test"<<std::endl;
    file.seekp(0);
    std::string yo;
    std::string deux;
    file>>yo;
    file>>deux;
    file.read()
    std::cout<<yo<<" : "<<deux<<std::endl;
    */
    char *s;
    file<<"end";
    file.seekg(0, std::ios::end);
    auto end = file.tellg();
    file.seekg(0);
    s = (char *) malloc(sizeof(char) * (end));
    file.read(s, end);
    std::cout<<s<<std::endl;
    file.close();
}