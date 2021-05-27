#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool reverse_cmp(int i, int j)
{
    return (i > j);
}

std::string LargestEven(std::string s)
{
    auto rev = [](int i, int j) {
        return (i > j);
    };
    std::sort(s.begin(), s.begin() + s.size(), ([](int i, int j) {return (i < j);}));
    size_t i = s.size() - 1;
    cout<<s<<endl;
    if ((s[s.size() - 1] % 2) == 0)
        return (s);
    while ((i + 1) > 0 && ((s[i] - 48) % 2) != 0)
        i--;
    if (i == SIZE_MAX || i == (s.size() - 1))
        return (s);
    while (i < s.size() - 1) {
        s[i] += s[i + 1];
        s[i + 1] = s[i] - s[i + 1];
        s[i] -= s[i + 1];
        i++;
    }
    cout<<i<<endl;
    return (s);
}

int main()
{
    cout<<LargestEven("3365")<<endl;
    return(1);
}