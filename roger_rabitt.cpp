/*
** ETNA PROJECT, 17/05/2021 by feuvra_v
** roger_rabitt
** File description:
**      roger_rabit
*/

#include <vector>
#include <iostream>
#include <bitset>
#include <queue>

using namespace std;

std::string roger_rabbit(unsigned int n)
{
    std::string s{};
    size_t i = 1;

    s.push_back('1');
    while (i < n){
        if (s[s.size() - 1] == '1') {
            s.push_back('0');
        }
        else
            s[s.size() - 1] = '1';
        i = i + 1;
    }
    return (s);
}

std::vector<string> rr(unsigned int n)
{
    std::queue<string> q;
    std::string current;
    std::string buff;
    std::vector<string> res(n);

    if (n == 0)
        return (res);
    q.push("1");
    res.push_back(q.front());
    current = "1";
    buff = current;
    for (size_t i = 0 ; i < n ; i++){
        //current.push_back(current[current.size() - 1] == '1' ? '0' : '1');
        current.push_back(current[current.size() - 1] == '1' ? '0' : '1');
        //buff.push_back(((current[current.size() - 1] - 48) xor 1) + 48);
        buff = current + to_string((((current[current.size() - 1] - 48) xor 1)));
        cout<<"current : "<<current<<endl;
        //current[current.size() - 1] = ((current[current.size() - 1] - 48) xor 1) + 48;
        cout<<"buff : "<<buff<<endl;
    }
    cout<<"kekz"<<endl;
}

std::vector<string> roger(unsigned int n)
{
    std::vector<string> res;
    size_t i = 0;
    unsigned int loop_length = (n / 2) - 1;

    res.push_back("1");
    if (n < 2)
        return (res);
    while (i < loop_length) {
        res.push_back(res[i] + "0");
        res.push_back(res[i] + "1");
        i++;
    }
    res.push_back(res[i] + "0");
    if ((n % 2))
        res.push_back(res[i] + "1");
    return (res);
}

int main()
{
    std::string s = roger_rabbit(3);
    cout<<s<<endl;
    std::bitset<1> yo(4);
    std::string vec;
    vec = "yo";
    /*
    auto str = yo.to_string('b');
    vec.push_back(str);
    vec.push_back(&str[4]);
    */
    //cout<<yo<<endl;
    //cout<<vec<<endl;
    //vec = vec + "kekz";
    //cout<<vec<<endl;
    auto caca = roger(0);
    for (auto it = caca.begin() ; it != caca.end() ; it++)
        cout<<*it<<" , ";
    cout<<endl;
    /*
    cout<<&str[4]<<endl;
    for (auto it = vec.begin() ; it != vec.end() ; it++)
        cout<<*it<<endl;
    cout<<sizeof(yo)<<endl;
    */
    return (0);
}