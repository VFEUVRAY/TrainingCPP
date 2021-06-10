#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream myfile("test.JSON", std::ifstream::binary);
    std::ofstream newfile("copyfox.JSON", std::ios::binary);
    std::string ting;
    if (!myfile)
        return (1);
    //newfile<<myfile.rdbuf();
    newfile<<"{\n\t\"Category\":{\n\t\t\"Item\":[1, 2, 3, 4]\n\t}\n}\n";
    /*
    myfile.seekp(0, std::ios::end);
    long init = myfile.tellp();
    if (init == 0){
        //return (1);
        myfile<<"some keks.txt"<<std::endl;
        long pos = myfile.tellp();
        myfile.seekp(pos - 4);
        myfile<<"pdf";
        myfile.seekp(0, std::ios_base::beg);
        myfile<<"more";
        myfile.seekp(0, std::ios_base::end);
        myfile<<"finality"<<std::endl;
        //std::streampos size = myfile.tellp();
        //char *yo = new char[size];
    }
    if (init > 0){
        myfile<<"this file is appended"<<std::endl;
        myfile.seekp(0, std::ios_base::beg);
        myfile<<"smol";
    }
    */

    return 0;
}