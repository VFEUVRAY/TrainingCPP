/*
** ETNA PROJECT, 21/04/2021 by feuvra_v
** do_a_barrel_roll
** File description:
**      do k rotations in passed vector
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> rand_vector(int n) {
    vector<int> result;

    for (int i = 0 ; i < 9 ; i++) {
        result.push_back(rand() % 100 + 1);
    }
    return (result);
}

template<class Circle>
Circle rotation(Circle begin, Circle k_begin, Circle end)
{
	cout<<"new_beg"<<endl;
   if(begin == k_begin){ cout << "begin == k_begin" << endl; return end;}
   if(k_begin == end){ cout << "k_begin == end" << endl; return begin;}

   Circle read = k_begin;
   Circle write = begin;
   Circle next_read = begin;


       while(read != end) {
          if(write == next_read) next_read = read;
              cout << "avant :"<< "on echange write: " << *write << ", avec read : " << *read
              << "----------" << *next_read << "-" << *end << endl;

                iter_swap(write++, read++);
                  //cout << *push << endl;
                  //printf("B : %p\n", push);
              cout << "apres :"<< "write vaut : " << *write << ", read vaut : " << *read
              << "----------" << *next_read << "-" << *end << endl;
   }
    cout << "AVANT rotation :"<< "write vaut : " << *write << ", read vaut : " << *read
    << "----------" << *next_read << "-" << *end << endl;
   // rotate the remaining sequence into place
   rotation(write, next_read, end);

   return write;
}

std::vector<int> do_a_barrel_roll(std::vector<int> numbers, size_t k)
{
      rotation(numbers.begin(),numbers.begin()+k,numbers.end());
      return(numbers);
}

int main()
{
    vector<int> test{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> random = rand_vector(1);

    for (int num : test) {
        cout<<num<<" ; ";
    }
    cout<<endl;
    test = do_a_barrel_roll(test, 7);
    for (int num : test) {
        cout<<num<<" ; ";
    }
    cout<<endl;
    return(1);
}
