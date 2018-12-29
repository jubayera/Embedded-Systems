/* 
Split numeric, alphabetic and special symbols from a String

Given a string str, divide the string into three parts one containing a numeric part, one containing alphabetic and one containing special characters.
Examples:

Input : geeks01for02geeks03!!!
Output :geeksforgeeks
        010203
        !!!
Here str = "Geeks01for02Geeks03!!!", we scan every character and 
append in res1, res2 and res3 string accordingly.

Input : **Docoding123456789everyday##
Output :Docodingeveryday
        123456789
        **##
Steps :

    Calculate the length of the string.
    Scan each every character(ch) of a string one by one
        if (ch is a digit) then append it in res1 string.
        else if (ch is alphabet) append in string res2.
        else append in string res3.
    Print the all the strings, we will have one string containing numeric part, other non numeric part and last one contain special characters.*/

// CPP program to split an alphanumeric 
// string using STL 
#include<bits/stdc++.h> 
using namespace std; 
  
void splitString(string str) 
{ 
    string alpha, num, special; 

    for (int i=0; i<str.length(); i++) 
    { 
        if (isdigit(str[i])) 
            num.push_back(str[i]); 
        else if((str[i] >= 'A' && str[i] <= 'Z') || 
                (str[i] >= 'a' && str[i] <= 'z')) 
            alpha.push_back(str[i]); 
        else
            special.push_back(str[i]); 
    } 
  
    cout << alpha << endl; 
    cout << num << endl; 
    cout << special << endl; 
} 
  
// Driver code 
int main() 
{ 
    string str = "geeks01$$for02geeks03!@!!"; 
    splitString(str); 
    return 0; 
} 
