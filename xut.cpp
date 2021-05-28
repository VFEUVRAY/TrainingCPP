#include <vector>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int numlen(int num)
{
	for (int len = 1 ; len < 11 ; len++) {
		num = num / 10;
		if (!num)
			return (len);
	}
	return (-1);
}

void display_piv(std::vector<int> numbers, int k)
{
	std::string nums;
	std::string piv;
	int len;

	for (int i = 0; i < numbers.size(); i++)
	{
		nums = nums + (std::to_string(numbers[i])) + " ; ";
		len = numlen(numbers[i]) + 3;
		for (int y = 0 ; y < len ; y++) {
			piv.push_back(32 + (62 * (i == k && y < (len - 3))));
		}
	}
	cout<<nums<<endl<<piv<<endl<<"pivot: "<<k<<endl;
}

int tux(std::vector<int> numbers)
{
	std::stack<int> pivot_stack;
	int i = 0;

	if (numbers.size() < 2)
		return (numbers.size() - 1);
	int biggest_val = numbers[0];
	pivot_stack.push(0);
	while (i < numbers.size())
	{
		while (!pivot_stack.empty() && numbers[pivot_stack.top()] > numbers[i])
			pivot_stack.pop();
		if (numbers[i] > biggest_val)
		{
			pivot_stack.push(i);
			biggest_val = numbers[i];
		}
		i++;
	}
	if (pivot_stack.empty())
		return (-1);
	display_piv(numbers, pivot_stack.top());
	return (pivot_stack.top());
}

int main()
{
	std::stack<int> s;
	std::vector<int> test = {97, 98, 97, 99, 99, 96, 117, 108, 101, 118, 108};
	s.push(12);
	s.push(21);
	s.push(32);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << tux(test) << endl;
	return (0);
}