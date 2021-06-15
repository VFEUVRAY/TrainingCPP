/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** main
** File description:
**      main for sed is for looser (replace)
*/

#include "replace.hpp"

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *replaceFileName(const char *filename)
{
    const int extensionSize = 9;
    const char *replaceStr(".replace");
    const int filenameSize = my_strlen(filename);
    char *replaceName = new char[filenameSize + extensionSize];
    size_t i = 0;

    while (filename[i]){
        replaceName[i] = filename[i];
        i++;
    }
    while (replaceStr[i - filenameSize]){
        replaceName[i] = replaceStr[i - filenameSize];
        i++;
    }
    replaceName[i] = 0;
    return (replaceName);
}

void replace(const char *filename, const char *s1, const char *s2)
{
    //const char *replaceName = replaceFileName(filename);
    const std::string r(std::string(filename) + ".replace");
    std::ifstream fileStream(filename);
    std::ofstream replaceStream(r);
    std::string buff;
    const std::string str1(s1);
    const std::string str2(s2);

    if (!fileStream)
        return ;
    while (!fileStream.eof()){
        std::getline(fileStream, buff);
        buff = replaceWord(buff, str1, str2);
        if (!fileStream.eof())
            buff.push_back('\n');
        replaceStream<<buff;
    }
    //delete[] (replaceName);
}

int main(int argc, char **argv)
{
    if (argc < 4 || argv[1][0] == 0 || 
        argv[2][0] == 0 || argv[3][0] == 0){
        std::cout<<"not enough parameters for replace: replace [filename] [s1] [s2]"<<std::endl;
        return (84);
    }
    replace(argv[1], argv[2], argv[3]);
    return (0);
}