/* 
map find() function in C++ STL

The map::find() is a built-in function in C++ STL which returns an iterator or a constant iterator that refers to the
position where the key is present in the map. If the key is not present in the map container, 
it returns an iterator or a constant iterator which refers to map.end().

Syntax:

iterator map_name.find(key)
        or 
constant iterator map_name.find(key)

Parameters: The function accepts one mandatory parameter key which specifies the key to be searched in the map container.

Return Value: The function returns an iterator or a constant iterator which refers to the position where the key is 
present in the map. If the key is not present in the map container, it returns an iterator or a constant iterator
which refers to map.end().*/
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
  
    // initialize container 
    multimap<int, int> mp; 
  
    // insert elements in random order 
    mp.insert({ 2, 30 }); 
    mp.insert({ 1, 40 }); 
    mp.insert({ 3, 20 }); 
    mp.insert({ 4, 50 }); 
  
    cout << "The elements from position 3 in map are : \n"; 
    cout << "KEY\tELEMENT\n"; 
  
    // find() function finds the position at which 3 is 
    for (auto itr = mp.find(3); itr != mp.end(); itr++) 
        cout << itr->first 
             << '\t' << itr->second << '\n'; 
  
    return 0; 
} 
/* g++ --std=c++11 map_find.cpp -o map_find
The elements from position 3 in map are :
KEY     ELEMENT
3       20
4       50
*/
