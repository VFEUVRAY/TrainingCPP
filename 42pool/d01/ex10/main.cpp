/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** main
** File description:
**      recreate basic cat function
*/

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    size_t i = 1;
    std::ifstream fileStream;
    std::string buff;
    std::string ting;
    //std::cin>>ting;
    //std::cout<<ting;
    if (argc > 1){
        for (; i < argc; i++) {
            fileStream.open(argv[i]);
            if (!fileStream.is_open()){
                std::cerr<<"cato9tails: "<<argv[i]<<": No such file or directory"<<std::endl;
                continue;
            }
            getline(fileStream, buff, '\0');
            std::cout<<buff;
            buff.clear();
            fileStream.close();
        }
        return (0);
    }
    //std::cin>>ting;
    while (!std::cin.eof()){
        getline(std::cin, ting, '\0');
        std::cout<<ting;
    }
    getline(std::cin, ting, '\0');
    std::cout<<ting;
    //while (i < argc)
    //    std::cerr<<argv[i++]<<std::endl;
}