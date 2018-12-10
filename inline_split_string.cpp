#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

inline vector<string> splitString( const string &s, const string &delimiter ){
    vector<string> ret;
    size_t start = 0;
    size_t end = 0;
    size_t len = 0;
    string token;
    do{ end = s.find(delimiter,start);
        len = end - start;
        token = s.substr(start, len);
        ret.emplace_back( token );
        start += len + delimiter.length();
        cout << token << endl;
    }while ( end != string::npos );
    return ret;
}

int main()
{
	string str;// = "adsf+qwer+poui+fdgh";

    string delimeter;

    cout << endl << "Enter line:" << endl;

	while(getline(cin, str))
	{
		cout << endl << "Enter delimeter:" << endl;
		getline(cin, delimeter);

		cout << endl << "Output:" << endl;

		vector<string> v = splitString (str, delimeter); //delimeter = "+"

		for (auto i : v)
			cout << i << endl;

		cout << endl << "Enter line" << endl;
	}

	return 0;
}

/*
 * Enter line:
adsf+qwer+poui+fdgh

Enter delimeter:
+

Output:
adsf
qwer
poui
fdgh
adsf
qwer
poui
fdgh
 */
