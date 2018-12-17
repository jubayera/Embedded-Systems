/* C++ Only Methods

    Returning multiple values Using References: We use references in C++ to store returned values. */

// Modified program using References in C++ 
#include <stdio.h> 
  
void compare(int a, int b, int &add_great, int &add_small) 
{ 
    if (a > b) { 
        add_great = a; 
        add_small = b; 
    } 
    else { 
        add_great = b; 
        add_small = a; 
    } 
} 

/* Returning multiple values using Class and Object : The idea is similar to structures. We create a class with two integer variables and store the greater and smaller values into those variable, then use the values of that structure. */
class GreaterSmaller { 
    public: 
        int greater, smaller; 
}; 

GreaterSmaller findGreaterSmaller(int a, int b) 
{ 
    GreaterSmaller s; 
    if (a > b) { 
        s.greater = a; 
        s.smaller = b; 
    } 
    else { 
        s.greater = b; 
        s.smaller = a; 
    } 
  
    return s; 
} 

// Driver code 
int main() 
{ 
    int great, small, x, y; 
  
    printf("Enter two numbers: \n"); 
    scanf("%d%d", &x, &y); 
  
    // The last two arguments are passed 
    // by giving addresses of memory locations 
    compare(x, y, great, small); 
    printf("\nThe greater number is %d and the"
           "smaller number is %d", 
           great, small); 

    GreaterSmaller result; 
    // The last two arguments are passed 
    // by giving addresses of memory locations 
    result = findGreaterSmaller(x, y); 
    printf("\nThe greater number is %d and the"
           "smaller number is %d", 
           result.greater, result.smaller); 
  
    return 0; 
} 
