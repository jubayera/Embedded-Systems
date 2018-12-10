// istringstream constructors.
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <vector>

using namespace std;

void number_line_parse(void)
{
	  std::string stringvalues = "125 320 512 750 333";
	  std::istringstream iss (stringvalues);

	  for (int n=0; n<5; n++)
	  {
	    int val;
	    iss >> val;
	    std::cout << val*2 << '\n';
	  }
}

void line_parse_into_variables(void)
{
	string fullName;

	cout << "Enter three parameters separated by spaces\n";
	getline(cin, fullName);

	istringstream iss(fullName);

	string firstName, middleName, lastName;
	iss >> firstName >> middleName >> lastName;

	cout << firstName << " " << middleName << " " << lastName << endl;
}

void line_parse_into_variables_with_split(void)
{
	string fullnameString;

	cout << "Enter three parameters separated by spaces\n";
	getline(cin, fullnameString);

	string temp = fullnameString;

	string firstName = temp.substr(0, temp.find(" "));

	temp = temp.substr(temp.find(" ")+1);

	string middleName = temp.substr(0, temp.find(" "));

	string lastName = temp.substr(temp.find(" ")+1);
}

void parsing_with_single_char_delimeter(void)
{
	string parsed="", input="text to be parsed";
	stringstream input_stringstream(input);

	cout << "\n";
	do
	{
	     if(parsed != "")
	    	 cout << parsed << " ";
	} while(getline(input_stringstream, parsed, ' '));

	cout << "\n";

	string s = "scott>=tiger";
	string delimiter = ">=";
	string token = s.substr(0, s.find(delimiter)); // token is "scott"
	cout << endl << token << endl;
}

void parsing_using_tokenizer(void)
{
/*
	The find(const string& str, size_t pos = 0) function returns the position of the first occurrence of str in the string, or npos if the string is not found.

	The substr(size_t pos = 0, size_t n = npos) function returns a substring of the object, starting at position pos and of length npos.

	If you have multiple delimiters, after you have extracted one token, you can remove it (delimiter included) to proceed with subsequent extractions (if you want to preserve the original string, just use  s = s.substr(pos + delimiter.length());):

	s.erase(0, s.find(delimiter) + delimiter.length());
	This way you can easily loop to get each token.
*/
	cout << "\n";

	string s = "teres>=tiger>=mushroom";
	string delimiter = ">=";

	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
	    token = s.substr(0, pos);
	    cout << token << std::endl;
	    s.erase(0, pos + delimiter.length());
	}
	cout << s << std::endl;
}

void parsing_without_erase(void)
{
	cout << "\n";
	string s = "bengal>=cricket";
	string delim = ">=";

	auto start = 0U;
	auto end = s.find(delim);
	while (end != string::npos)
	{
		cout << s.substr(start, end - start) << std::endl;
		start = end + delim.length();
		end = s.find(delim, start);
	}

	cout << s.substr(start, end);
}

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void parse_using_tokenizer(void)
{
	cout << "\n";
	string token, mystring("embedded>=systems");
	while(token != mystring){
	  token = mystring.substr(0,mystring.find_first_of(">="));
	  mystring = mystring.substr(mystring.find_first_of(">=") + 1);
	  printf("%s ",token.c_str());
}
}

int main()
{
	line_parse_into_variables();
	line_parse_into_variables_with_split();
	number_line_parse();
	parsing_with_single_char_delimeter();
	parsing_using_tokenizer();
	parsing_without_erase();
	parse_using_tokenizer();
	return 0;
}
