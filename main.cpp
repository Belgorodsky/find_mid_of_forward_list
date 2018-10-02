#include <iostream>
#include <forward_list>

template<class It>
void recursive_find_mid_impl(It begin, It end, It &mid, size_t &expected, size_t counter = 0)
{
	if (begin != end)
	{
		++counter;
		recursive_find_mid_impl(std::next(begin), end, mid, expected, counter);
		if (expected == counter)
		{
			mid = begin;
			return;
		}
	}
	else
	{
		expected = (counter + 1) / 2;
		mid = end;
	}
}

template<class It>
void recursive_find_mid(It begin, It end, It &mid)
{
	size_t expected = std::numeric_limits<size_t>::max();
	recursive_find_mid_impl(begin, end, mid, expected);
}

int main()
{
	std::forward_list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	auto mid = lst.end();
	recursive_find_mid(lst.begin(), lst.end(), mid);

	if (mid != lst.end())
		std::cout << *mid << '\n';
	else
		std::cout << "nothing" << '\n';

	std::forward_list<int> lst2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto mid2 = lst2.end();
	recursive_find_mid(lst2.begin(), lst2.end(), mid2);

	if (mid2 != lst.end())
		std::cout << *mid2 << '\n';
	else
		std::cout << "nothing" << '\n';

	std::forward_list<int> lst3 = {1};
	auto mid3 = lst3.end();
	recursive_find_mid(lst3.begin(), lst3.end(), mid3);

	if (mid3 != lst.end())
		std::cout << *mid3 << '\n';
	else
		std::cout << "nothing" << '\n';

	std::forward_list<int> lst4 = {};
	auto mid4 = lst4.end();
	recursive_find_mid(lst4.begin(), lst4.end(), mid4);

	if (mid4 != lst.end())
		std::cout << *mid4 << '\n';
	else
		std::cout << "nothing" << '\n';
}


