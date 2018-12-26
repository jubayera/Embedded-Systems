An Array (Or a vector) is a data structure that can hold elements in a container. These elements can be of any class, whether native data types (such as int, bool, float, double, ...), or even classes (Student Class,  Person Class, ...). 

In C++, to declare and initialize an  empty vector, you have to first include the <vector> library. You do this by doing:

#include <vector> 


then you can do the following:



vector< DATA_TYPE > v; 

and replacing the DATA_TYPE with data type of the elements that you want the class to contain. For instance, to declare and initialize an empty vector that holds integer values, we can do:

vector<int> v; 

In addition, if we have a class called Student, then we can do something like this:

#include <iostream>
#include <vector>
using namespace std;
 
class Student{
public:
    Student(){
        cout << "Student Constructor";
    }    
};
int main() {
    vector<Student> v;
    return 0;
}
Here, we have an empty vector that will hold Student classes. 

It is worth noting that you can also use another type of constructor for the vector class, for example, the following initializes a vector that holds bool values, and initializes 100 elements in the vector as true (So now the vector has 100 elements which are all true):

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    vector<bool> v(100, true);
    return 0;
}
So far so good, we've been able to initialize empty vectors, now what? How do we add new elements? Well for that, we use the push_back function:

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    vector<bool> v;
    v.push_back(1);
    v.push_back(2);
    return 0;
}
Now, the vector has 2 elements, 1 and 2. We can also add classes similarly such as the following example:

#include <iostream>
#include <vector>
using namespace std;
 
class AnimalNumber{
private:
    int my_num;
public:
    AnimalNumber(int x){
        this->my_num = x;
    }
};
int main() {
    vector<AnimalNumber> v;
    AnimalNumber an1(5);
    AnimalNumber an2(10);
    v.push_back(an1);
    v.push_back(an2);
    return 0;
}
Okay, now how do we erase elements? Well suppose you want to erase an element in index i, then you can do something like this:

#include <iostream>
#include <vector>
using namespace std;
 
class AnimalNumber{
private:
    int my_num;
public:
    AnimalNumber(int x){
        this->my_num = x;
    }
};
int main() {
    vector<AnimalNumber> v;
    AnimalNumber an1(5);
    AnimalNumber an2(10);
    v.push_back(an1);
    v.push_back(an2);
    v.erase(v.begin()+1); //erases an2 since it is at index 1
    return 0;
}
If you want to delete a consecutive list of elements between index i and j, then you can do:

#include <iostream>
#include <vector>
using namespace std;
 
class AnimalNumber{
private:
    int my_num;
public:
    AnimalNumber(int x){
        this->my_num = x;
    }
};
int main() {
    vector<AnimalNumber> v(100, AnimalNumber(10));
    int i = 1; //delete from the first element
    int j = 50; //delete up to, but not including the 50th element
    v.erase(v.begin()+i, v.begin()+j); //deletes v[i], v[i+1], ...., v[j-1]
    return 0;
}
To know the size of a vector, we use the size() function:

#include <iostream>
#include <vector>
using namespace std;
 
class AnimalNumber{
private:
    int my_num;
public:
    AnimalNumber(int x){
        this->my_num = x;
    }
};
int main() {
    vector<AnimalNumber> v(100, AnimalNumber(10));
    int i = 1; //delete from the first element
    int j = 50; //delete up to, but not including the 50th element
    v.erase(v.begin()+i, v.begin()+j); //deletes v[i], v[i+1], ...., v[j-1]
    cout << v.size() << endl;
    return 0;
}
The above code would output 51 since there are 51 elements left in the vector after the deletion. 

Okay, just a few more things. We often need to sort vectors based on some ordering, and it would be tedious to have to write a sorting function every time we need it. Luckily, C++ supports the ability to sort a vector very easily and efficiently. If the vector has n elements, then the C++ sort function takes O(nlogn) time to sort it. For example, to sort a vector, all we have is to import the header <algorithm> and do:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main() {
    vector<int> v;
    for(int i=10; i>=0; --i){
        v.push_back(i);
    }
    cout << "Before Sorting: \n";
    for(int i=0; i<v.size() ; ++i){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "After Sorting: \n";
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
}
The output of the above program would be:



Before Sorting: 
10 9 8 7 6 5 4 3 2 1 0 
After Sorting: 
0 1 2 3 4 5 6 7 8 9 10
 
Notice that by default, the sorting function sorts in ascending order, and hence it compares the elements using the < operator. Now I hear you, how would you sort an element in another order, say descending order? Well in this case, we have to write something called a comparator class, which basically implements the "<" operator of however we see fit, for example:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
class comparator{
public:
    bool operator()(const int& lhs, const int& rhs){
        return lhs > rhs;
    }
};
int main() {
    vector<int> v;
    for(int i=0; i<=10; ++i){
        v.push_back(i);
    }
    cout << "Before Sorting: \n";
    for(int i=0; i<v.size() ; ++i){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "After Sorting: \n";
    
    sort(v.begin(), v.end(), comparator());
    
    for(int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
}
The above code outputs:



Before Sorting: 
0 1 2 3 4 5 6 7 8 9 10 
After Sorting: 
10 9 8 7 6 5 4 3 2 1 0 


You can implement the comparator class for any Class or data type, simply replace the int with your class name and implement your "<" operator as you see fit. Here is an example:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
class Student{
private:
    int StudentNumber;
public:
    Student(int n){
        this->StudentNumber = n;
    }
    int getStudentNumber() const{
        return this->StudentNumber;
    }
};
class comparator{
public:
    bool operator()(const Student& lhs, const Student& rhs){
        return lhs.getStudentNumber() < rhs.getStudentNumber();
    }
};
int main() {
    vector<Student> v;
    for(int i=10; i>=0; --i){
        v.push_back( Student(i) );
    }
    cout << "Before Sorting: \n";
    for(int i=0; i<v.size() ; ++i){
        cout << v[i].getStudentNumber() << " ";
    }
    cout << endl;
    cout << "After Sorting: \n";
    
    sort(v.begin(), v.end(), comparator());
    
    for(int i=0; i<v.size(); ++i){
        cout << v[i].getStudentNumber() << " ";
    }
}
Finally, although you can theoretically use:

vector<char> s; 

To represent a collection of characters (i.e. word), its often much more useful to use the data structure String by importing  <string> header. The String class acts very similarly to a vector (often problems that are solved on strings can be exactly solved on a vector of chars), here is an example of using most of the important features of the string class:

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
    string s, t, r;
    t = "hello";
    r = "world";
    s = t+r; //can concatenate strings with +
    cout << s << endl;
    s += "!"; //use the += or s = s + (str) are both valid
    cout << s << endl;
    sort(s.begin(), s.end()); //can sort string based on alphabetical order! (in ASCII)
    cout << s << endl;
}
A final very useful function to use is the function "binary_search" which is in the <algorithm> library. You can use it on a SORTED vector/string to find whether they have an element or a character respectively. It returns true if they do have the element, or false other wise. Here is an example:

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(9);
    v.push_back(8);
    sort(v.begin(), v.end()); //vector must be sorted before using the binary_search
    cout << binary_search(v.begin(), v.end(), 5) << endl; //false
    cout << binary_search(v.begin(), v.end(), 9) << endl; //true
    
    string s = "abcdefghijklmnopqrstyv";
    sort(s.begin(), s.end());
    cout << binary_search(s.begin(), s.end(), 'z') << endl; //false, z not found
    cout << binary_search(s.begin(), s.end(), 'a') << endl; //true, a found!
    
}
The function is very useful because it if the size of the vector is "n", then it finds the element in the sorted vector in O(logn) time!.

Questions
Search for a question:
Search for a question
4 questions in this lecture

SP
vector declaration
    vector<AnimalNumber> v(100,AnimalNumber(10));this defines that vector v has 100 elements but what is the meaning of AnimalNumber(10)?
IM
push_back on a vector
Code Snippet: #include <iostream> #include <vector> using namespace std;  int main() { vector<bool> v; v.push_back(1); v.push_back(2); return 0; } In your code snippet in the lesson about vectors, you use push_back which pushes 1 and 2 inside the vector of bool, how is it possible as bool takes only true or false right? kindly help me out with this.
MA
Why we use Animal number(10)
NN
How comparator works ?
in operator method, each element is compared with all other elements for comparison ? 
Question Details
