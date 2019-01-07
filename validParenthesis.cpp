#include <bits/stdc++.h>

using namespace std;

bool areParanthesisBalanced(string expr)
{
	stack<char> s;
	char x;

	//Traversing the expression
	for(int i = 0; i < expr.length(); i++)
	{
		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
		{
			//Push the element in the stack
			s.push(expr[i]);
			continue;
		}

		//If current character is not opening bracket, then it must be closing. So stack cannot be empty at this point.
		if(s.empty())
			return false;

		switch(expr[i])
		{
			case ')':
				x = s.top();
				s.pop();
				if(x == '{' || x == '[')
					return false;
				break;

			case '}':
				x = s.top();
				s.pop();
				if(x == '(' || x == '[')
					return false;
				break;
			case ']':
				x = s.top();
				s.pop();
				if(x == '(' || x == '{')
					return false;
				break;
		}
	}

	//check empty stack
	return (s.empty());
}

vector<string> braces ( vector<string> values)
{
	vector<string> validities;
	
	for(vector<string>::iterator t = values.begin(); t != values.end(); ++t)
	{
		//cout << t->c_str() << endl;
		if(areParanthesisBalanced(t->c_str()) == true)
			validities.push_back("YES");
		else
			validities.push_back("NO");
	}

	return validities;
}

int main()
{
	int values_count;
	cin >> values_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<string> values(values_count);

	for(int i = 0; i < values_count; i++)
	{
		string values_item;
		getline(cin, values_item);
		values[i] = values_item;
	}

	vector<string> res = braces(values);

	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i];

		if(i != res.size() - 1)
			cout << "\n";
	}

	return 0;
}
