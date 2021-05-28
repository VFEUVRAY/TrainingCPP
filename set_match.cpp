/*
** ETNA PROJECT, 16/05/2021 by feuvra_v
** set_match
** File description:
**      set_match
*/

#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool set_et_match(std::vector<int> numbers, int n)
{
    std::unordered_map<int,bool> nummap(numbers.size());
    size_t i = 0;
    auto it = nummap.begin();
    int target;

    while (i < numbers.size()) {
        target = n - numbers[i];
        it = nummap.find(target);
        if (it != nummap.end())
            return (true);
        nummap.insert(std::pair<int,bool>(numbers[i], true));
        i++;
    }
    return (false);
}

bool set_et_set(std::vector<int> numbers, int n)
{
	std::unordered_set<int> numset;
    numset.reserve(numbers.size());
	int target;

    cout<<"buckets : "<<numset.bucket_count()<<endl;
	for (auto it = numbers.begin() ; it != numbers.end() ; it++) {
		target = n - *it;
		if (numset.find(target) != numset.end())
			return (true);
		numset.insert(*it);
	}
    cout<<"buckets : "<<numset.bucket_count()<<endl;
	return (false);
}

int main()
{
    std::vector<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout<<set_et_match(test, 8)<<endl;
    cout<<set_et_set(test, 50)<<endl;
    return (1);
}