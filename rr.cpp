
#include <iostream>
#include <string>
#include <queue>

using namespace std;


vector<string> roger_rabbit(unsigned int n)
{
    vector<string> coucou;
	queue<string> binaire;
	binaire.push("1");

    if ( n != 0 ) {
        cout << '[';
    }

	int i = 1;
	while (i++ <= n)
	{

        if ( i <= n ) {
            binaire.push(binaire.front() + "0");
            binaire.push(binaire.front() + "1");
			coucou.push_back(binaire.front() + "0");
			coucou.push_back(binaire.front() + "1");
        }

        cout << '"';
		cout << binaire.front() << '"';

		if ( i <= n ) {
		    cout << ',';
            cout << ' ';
            binaire.pop();
		}

		if ( i == n + 1 ) {
		    cout << ']';
		}
	}

	cout << endl;
	for (auto it = coucou.begin() ; it != coucou.end() ; it++)
		cout<<*it<<endl;
    return coucou;
}

int main()
{
	unsigned int n = 6;
    roger_rabbit(n);

	return 0;
}