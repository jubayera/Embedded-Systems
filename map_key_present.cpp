/*
map count() function in C++ STL

The map::count() is a built-in function in C++ STL which returns 1 if the element with key K is present in the map container. It returns 0 if the element with key K is not present in the container.

Syntax:

map_name.count(key k)

Parameters: The function accepts a mandatory parameter k which specifies the key to be searched in the map container.

Return Value: The function returns the number of times the key K is present in the map container. It returns 1 if the key is present in the container as the map only contains a unique key. It returns 0 if the key is not present in the map container.*/

// C++ program to illustrate 
// the map::count() function 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
  
    // initialize container 
    map<int, int> mp; 
  
    // insert elements in random order 
    mp.insert({ 2, 30 }); 
    mp.insert({ 1, 40 }); 
    mp.insert({ 3, 60 }); 
    mp.insert({ 4, 20 }); 
    mp.insert({ 5, 50 }); 
  
    // checks if key 1 is present or not 
    if (mp.count(1)) 
        cout << "The key 1 is present\n"; 
    else
        cout << "The key 1 is not present\n"; 
  
    // checks if key 100 is present or not 
    if (mp.count(100)) 
        cout << "The key 100 is present\n"; 
    else
        cout << "The key 100 is not present\n"; 
  
    return 0; 
} 
/* g++ --std=c++11 map_key_present.cpp -o map_key_present
The key 1 is present
The key 100 is not present */
