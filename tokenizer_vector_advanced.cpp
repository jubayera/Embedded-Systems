#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool endsWith(const string& s, const string& suffix)
{
    return s.size() >= suffix.size() &&
           s.substr(s.size() - suffix.size()) == suffix;
}

vector<string> split(const string& s, const string& delimiter, const bool& removeEmptyEntries = false)
{
    vector<string> tokens;

    for (size_t start = 0, end; start < s.length(); start = end + delimiter.length())
    {
         size_t position = s.find(delimiter, start);
         end = position != string::npos ? position : s.length();

         string token = s.substr(start, end - start);
         if (!removeEmptyEntries || !token.empty())
         {
             tokens.push_back(token);
         }
    }

    if (!removeEmptyEntries &&
        (s.empty() || endsWith(s, delimiter)))
    {
        tokens.push_back("");
    }

    return tokens;
}

int main()
{
    string str;// = "adsf+qwer+poui+fdgh";

    string delimeter;

    const bool do_remove_empty_entries = true;

    cout << endl << "Enter line:" << endl;

    while(getline(cin, str))
    {
    	cout << endl << "Enter delimeter:" << endl;
    	getline(cin, delimeter);

    	cout << endl << "Output:" << endl;

		vector<string> v = split (str, delimeter, do_remove_empty_entries); //delimeter = "+"

		for (auto i : v)
			cout << i << endl;

		cout << endl << "Enter line" << endl;
    }
	return 0;
}

/*
 * when false is selected for remove_empty_entries
 * split("a-b-c", "-"); // [3]("a","b","c")

split("a--c", "-"); // [3]("a","","c")

split("-b-", "-"); // [3]("","b","")

split("--c--", "-"); // [5]("","","c","","")

split("--c--", "-", true); // [1]("c")

split("a", "-"); // [1]("a")

split("", "-"); // [1]("")

split("", "-", true); // [0]()

when true is selected for remove_empty_entries:


Enter line:
adsf+qwer+poui+fdgh

Enter delimeter:
+

Output:
adsf
qwer
poui
fdgh

Enter line
a-b-c

Enter delimeter:
-

Output:
a
b
c

Enter line
a--c

Enter delimeter:
-

Output:
a
c

Enter line
-b-

Enter delimeter:
-

Output:
b

Enter line
--c--

Enter delimeter:
-

Output:
c

Enter line
--c--

Enter delimeter:
-

Output:
c

Enter line
a

Enter delimeter:
-

Output:
a

Enter line


Enter delimeter:
-

Output:

Enter line


Enter delimeter:
-

Output:

Enter line


 */

/*
 * int id;
	std::string n;
	double s;

cout << "Enter tax ID ";
cin >> id;
cout << "Enter name ";
std::getline (std::cin,n);
cout << "Enter salary ";
cin >> s;

cout << id << " " << n << " " << s << endl;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;

int main(){

int id;
string name;
double salary;

cout<<"Enter tax ID: ";
cin>>id;
cin.ignore();
cout<<"\nEnter name: ";
getline(cin,name);
cout<<"\nEnter salary: ";
cin>>salary;

cout<<"\n\n"<<id<<' '<<name<<' '<<salary<<endl;

return 0; //indicates success
}//end main
Edit & Run

 */
