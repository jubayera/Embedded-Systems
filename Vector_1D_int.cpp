
// C++ program to demonstrate that when vectors 
// are passed to functions without &, a copy is 
// created. 
#include<bits/stdc++.h> 
using namespace std; 
   
// The vect here is a copy of vect in main() 
void func_by_value(vector<int> vect) 
{ 
   vect.push_back(30); 
} 

// The vect is passed by reference and changes 
// made here reflect in main() 
void func_reference(vector<int> &vect) 
{ 
   vect.push_back(30); 
} 

//If we do not want a function to modify a vector, we can pass it as a const reference.
// The vect is passed by constant reference 
// and cannot be changed by this function. 
void func_const_reference(const vector<int> &vect) 
{ 
    // vect.push_back(30);  // Uncommenting this line would 
                             // below error 
    // "prog.cpp: In function 'void func(const std::vector<int>&)': 
    // prog.cpp:9:18: error: passing 'const std::vector<int>'  
    // as 'this' argument discards qualifiers [-fpermissive]"    
    
    for (int i=0; i<vect.size(); i++) 
       cout << vect[i] << " "; 
} 
   
int main() 
{ 
    vector<int> vect; 
    vect.push_back(10); 
    vect.push_back(20); 
   
    func_by_value(vect); 
   
    // vect remains unchanged after function 
    // call 
    for (int i=0; i<vect.size(); i++) 
       cout << vect[i] << " ";  //10 20

    func_reference(vect);

    cout << endl;

    // vect gets changed after function 
    // call 
    for (int i=0; i<vect.size(); i++) 
       cout << vect[i] << " "; //10 20 30
   
    func_const_reference(vect);
    return 0; 
} 
