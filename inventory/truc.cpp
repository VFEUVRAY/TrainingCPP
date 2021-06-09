#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream myfile("dummy.txt");
    if (!myfile)
        return (1);
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
    myfile.ignore();
    myfile.close();
    int const height = 10;
    int yes[5];
    bool no = true;
    yes[2] = no;
    std::cout<<yes[2]<<std::endl;
    std::cout<<height<<std::endl;
    std::string age;
    //std::cin.ignore();
    std::cin.ignore(256, ';');
    std::cin>>age;
    std::cout<<age;
    return 0;
}