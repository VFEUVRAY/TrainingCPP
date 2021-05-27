#include <iostream>

using namespace std;

long long findNth(long long n)
{
    if (n / 9)
        findNth(n / 9);
    cout<<n%9;
}

long long N(long long n, long long res)
{
    if (n / 9)
        res = N(n / 9, res);
    return ((res * 10) + (n % 9));
}

int main()
{
    //findNth(19);
    cout<<N(19, 0)<<endl;
    return (1);
}