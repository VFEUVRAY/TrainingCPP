#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int>::iterator roll(std::vector<int>::iterator begin, std::vector<int>::iterator k, std::vector<int>::iterator end)
{
	if (k == end)
		return (begin);
	if (begin == k)
		return (k);
	std::vector<int>::iterator push = begin;
	std::vector<int>::iterator check = k;
	std::vector<int>::iterator next_k = begin;
	while (check != end) {
		if (push == next_k)
			next_k = check;
		std::iter_swap(push, check);
		push++;
		check++;
	}
	roll(push, next_k, end);
	return (begin);
}

std::vector<int> rollz(std::vector<int> n, size_t k)
{
	std::vector<int> res;
	k = k % n.size();
	roll(n.begin(), n.begin() + k, n.end());
	for (auto it = n.begin() ; it != n.end() ; it++)
		std::cout<<*it<<" ; ";
	std::cout<<std::endl;
	return (res);
}

std::vector<int> rolling(std::vector<int> numbers, int k)
{
	if (numbers.size() < 2)
		return (numbers);
	k = k % numbers.size();
	if (!k)
		return (numbers);
	auto first = numbers.begin(); 	//beginning iterator which will be used as main loop iterator
	auto swap = first + k; 		//will be offsetted index to make swaps
	auto end = numbers.end(); 	// just keeping for consistency's sake
	auto new_swap = first; 		//will be used to readjust swap offset after first pass through

	while (first != swap) {				//first = begin and first is incremented in second while loop so max N reps
		while (swap != end) {
			if (new_swap == first)		//set new_swap at swap if current iterator reaches 
				new_swap = swap;	//this ensures that no matter what new_swap > first and that swap > first when doing multiple pass through
			std::iter_swap(swap, first);	//swap iterator values
			first++;
			swap++;
		}
		swap = new_swap;			// MOST IMPORTANT PART : Set swap at new_swap so that we can keep on looping with first < swap and comple rotations on subsequent passes through
	}
	for (auto it = numbers.begin() ; it != numbers.end() ; it++)
		std::cout<<*it<<" ; ";
	std::cout<<std::endl;
	return (numbers);
}

std::vector<int> do_a_barrel_roll(std::vector<int> numbers, size_t k)
{
	k = k % (numbers.size() + (numbers.size() == 0));
	if (!k || numbers.size() < 2)
		return (numbers);
	size_t first_swap = 0;
	size_t second_swap = k;
	size_t end = numbers.size();
	size_t new_second_swap = 0;
	int temp;

	while (first_swap < end) {
		while (second_swap < end) {
			if (first_swap == new_second_swap)
				new_second_swap = second_swap;
			temp = numbers[first_swap];
			numbers[first_swap] = numbers[second_swap];
			numbers[second_swap] = temp;
			first_swap++;
			second_swap++;
		}
		second_swap = new_second_swap;
	}
	for (auto it = numbers.begin() ; it != numbers.end() ; it++)
		std::cout<<*it<<" ; ";
	std::cout<<std::endl;
	return (numbers);
}

std::vector<int> reverse_roll(std::vector<int> numbers, size_t k)
{
	std::reverse(numbers.begin(), numbers.begin() + k);
	std::reverse(numbers.begin() + k, numbers.begin() + numbers.size());
	std::reverse(numbers.begin(), numbers.begin() + numbers.size());
	/*
	for (auto it = numbers.begin() ; it != numbers.end() ; it++)
		std::cout<<*it<<" ; ";
	std::cout<<std::endl;
	*/
	return (numbers);
}

int main()
{
	std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> moul = {0, 1, 2, 3};
	std::vector<int>::iterator i = test.begin();
	std::cout<<"yo"<<std::endl;
	std::cout<<*i<<std::endl;
	rolling(test, 1);
	rolling(test, 2);
	rolling(test, 3);
	rolling(test, 4);
	rolling(test, 5);
	rolling(test, 6);
	rolling(test, 7);
	rolling(test, 8);
	rolling(test, 9);
	for (auto it = test.begin() ; it != test.end() ; it++)
		std::cout<<*it<<" ; ";
	std::cout<<std::endl;
	std::cout<<"indices"<<std::endl;
	do_a_barrel_roll(test, 2);
	//do_a_barrel_roll(moul, 2);
	moul = reverse_roll(moul, 4);
	for (auto it = moul.begin() ; it != moul.end() ; it++)
		std::cout<<*it<<" ; ";
	std::cout<<std::endl;
	return (0);
}