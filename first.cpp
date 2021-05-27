#include <iostream>
#include <vector>

using namespace std;

class first {
    public: string yo() {
        return ("famille\n");
    }

    public: int input_num() {
        string num;
        cout<<"input: ";
        cin>>num;
        return (this->getnum(num, 0));
    }

    private: int getnum(string num, int res) {
        if (num[0] >= '0' && num[0] <= '9')
            return (this->getnum(&num[1], (res * 10) + (num[0] - 48)));
        return (res);
    }
};

int main(int argc, char **argv)
{
    string machin;
    first *test = nullptr;
    vector<int> yo(3);
    int res = test->input_num();
    int x = '0';
    cout << res << endl;
    return (0);
}