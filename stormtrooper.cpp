/*
** ETNA PROJECT, 20/04/2021 by feuvra_v
** stormtrooper
** File description:
**      find and erase duplicatas of numbers in passed vector
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

std::vector<int> stormtroopers(std::vector<int> numbers)
{
    size_t i = 0;
    size_t y;
    bool has_erased = 0;

    while (i < numbers.size()) {
        y = i + 1;
        while (y < numbers.size()) {
            if (numbers[i] == numbers[y]) {
                numbers.erase(numbers.begin() + y);
                has_erased = 1;
                y = y - 1;
            }
            y = y + 1;
        }
        if (has_erased)
            numbers.erase(numbers.begin() + i);
        else
            i = i + 1;
        has_erased = 0;
    }
    return (numbers);
}

std::vector<int> stormtroopers3(std::vector<int> numbers)
{
    std::unordered_map<int,size_t> numcount;
    std::vector<int> result = {};

    cout<<"size "<<sizeof(numcount)<<endl;
    cout<<"bucket count "<<numcount.bucket_count()<<endl;
    //cout<<"bucket count "<<numcount.size()<<endl;
    for (int num : numbers)
        numcount[num]++;
    for (int num : numbers) {
        if (numcount[num] == 1)
            result.push_back(num);
    }
    cout<<"bucket count "<<numcount.bucket_count()<<endl;
    return(result);
}

/*
std::vector<int> st(std::vector<int> numbers)
{

}
*/
int main()
{
    //std::vector<int> yo{1, 2, 2, 3, 4, 4, 5, 1, 2, 2, 3, 4, 4, 5, 1, 2, 2, 3, 4, 4, 5, 1, 2, 2, 3, 4, 4, 5, 1, 2, 2, 3, 4, 4, 5, 1, 2, 2, 3, 4, 4, 5, 1, 2, 2, 3, 4, 4, 5, 1, 2, 2, 3, 4, 4, 5};
    std::vector<int> test{1, 2, 2, 3, 4, 4, 5, 100290, 2819, 2819, 12, 12};
    auto start = high_resolution_clock::now();
    //yo = stormtroopers(yo);
    test = stormtroopers3(test);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    for (auto it = test.begin(); it != test.end(); it++) {
        cout<<*it<<endl;
    }
    cout<<"function duration is: "<<duration.count()<<" microseconds"<<endl;
    return 0;
}