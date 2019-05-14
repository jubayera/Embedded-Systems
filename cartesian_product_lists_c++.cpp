#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<vector<int>>& v)
{
	cout << "{ ";
	for(const auto& p : v)
	{
		cout << "(";
		for(const auto& e : p)
		{
			cout << e << " ";
		}	
		cout << ") ";
	}
	cout << "}" << endl;
}

auto product(const vector<vector<int>>& lists)
{
	vector<vector<int>> result;

	if(find_if(begin(lists), end(lists), [](auto e) -> bool { return e.size() == 0; }) != end(lists))
	{
		return result;
	}

	for(auto& e : lists[0])
	{
		result.push_back({ e });
	}

	for(size_t i = 1; i < lists.size(); ++i) 
	{
		vector<vector<int>> temp;
		for(auto& e : result)
		{
			for(auto f : lists[i])
			{
				auto e_tmp = e;
				e_tmp.push_back(f);
				temp.push_back(e_tmp);
			}
		}
		result = temp;
	}
	
	return result;
}

int main()
{
	vector<vector<int>> prods[] = {
		{ { 1, 2 }, { 3, 4 } },
		{ { 3, 4 }, { 1, 2 } },
		{ { 1, 2 }, { } },
		{ { }, { 1, 2 } },
		{ { 1776, 1789 }, { 7, 12 }, { 4, 14, 23 }, { 0, 1 } },
		{ { 1, 2, 3 }, { 30 }, { 500, 100 } },
		{ { 1, 2, 3 }, { }, { 500, 100 } }
	};

	for(const auto& p : prods)
	{
		print(product(p));
	}

	cin.ignore();
	cin.get();

	return 0;
}

Output:
------
-std=c++14
{ (1 3 ) (1 4 ) (2 3 ) (2 4 ) }
{ (3 1 ) (3 2 ) (4 1 ) (4 2 ) }
{ }
{ }
{ (1776 7 4 0 ) (1776 7 4 1 ) (1776 7 14 0 ) (1776 7 14 1 ) (1776 7 23 0 ) (1776 7 23 1 ) (1776 12 4 0 ) (1776 12 4 1 ) (1776 12 14 0 ) (1776 12 14 1 ) (1776 12 23 0 ) (1776 12 23 1 ) (1789 7 4 0 ) (1789 7 4 1 ) (1789 7 14 0 ) (1789 7 14 1 ) (1789 7 23 0 ) (1789 7 23 1 ) (1789 12 4 0 ) (1789 12 4 1 ) (1789 12 14 0 ) (1789 12 14 1 ) (1789 12 23 0 ) (1789 12 23 1 ) }
{ (1 30 500 ) (1 30 100 ) (2 30 500 ) (2 30 100 ) (3 30 500 ) (3 30 100 ) }
{ }

