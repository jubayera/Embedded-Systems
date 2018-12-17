/* 
Queue in Standard Template Library (STL)

Queues are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement. Elements are inserted at the back (end) and are deleted from the front.

 

The functions supported by queue are :

    empty() – Returns whether the queue is empty.
    size() – Returns the size of the queue.
    queue::swap() in C++ STL: Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
    queue::emplace() in C++ STL: Insert a new element into the queue container, the new element is added to the end of the queue.
    queue::front() and queue::back() in C++ STL– front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
    push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.
*/
// Queue in Standard Template Library (STL) 
#include <iostream> 
#include <queue> 
  
using namespace std; 
  
void showq(queue <int> gq) 
{ 
    queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
  
int main() 
{ 
    queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(20); 
    gquiz.push(30); 
  
    cout << "The queue gquiz is : "; 
    showq(gquiz); 
  
    cout << "\ngquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.front() : " << gquiz.front(); 
    cout << "\ngquiz.back() : " << gquiz.back(); 
  
    cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
    showq(gquiz); 
  
    return 0; 
} 

/* The queue gquiz is :    10      20      30

gquiz.size() : 3
gquiz.front() : 10
gquiz.back() : 30
gquiz.pop() :   20      30  */
