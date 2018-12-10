//P.S: Works only if the lengths of the strings after splitting are equal

//DO NOT USE THIS IF THE SUBSTRING ARE NOT EQUAL

#include<iostream>
#include<algorithm>
using namespace std;

int split_count(string str, char delimit)
{
	return count(str.begin(), str.end(), delimit);
}

void split(string str, char delimit, string res[])
{
	unsigned int a=0,i=0;

	while(a < str.size())
	{
		res[i] = str.substr(a, str.find(delimit));
		a += res[i].size()+1;
		i++;
	}
}

int main(){

	string a = "abc.xyz.mno.def";

	int x = split_count(a,'.')+1;

	string res[x];
	split(a,'.',res);

	for(int i=0; i<x; i++)
		cout << res[i] << endl;

	return 0;
}
/*
 * abc
xyz
mno
def
 *
 */
