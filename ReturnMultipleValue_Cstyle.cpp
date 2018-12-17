/* How to return multiple values from a function in C or C++?

New programmers are usually in the search of ways to return multiple values from a function. Unfortunately, C and C++ do not allow this directly. But fortunately, with a little bit of clever programming, we can easily achieve this.

Below are the methods to return multiple values from a function in C:

    By using pointers.
    By using structures.
    By using Arrays.

Example: Consider an example where the task is to find the greater and smaller of two distinct numbers. We could write multiple functions. The main problem is the trouble of calling more than one functions since we need to return multiple values and of course having more number of lines of code to be typed.

    Returning multiple values Using pointers: Pass the argument with their address and make changes in their value using pointer. So that the values get changed into the original argument.*/


#include <stdio.h> 
  
// Modified program using pointers 
// add is the short name for address 
void compare(int a, int b, int* add_great, int* add_small) 
{ 
    if (a > b) { 
  
        // a is stored in the address pointed 
        // by the pointer variable *add_great 
        *add_great = a; 
        *add_small = b; 
    } 
    else { 
        *add_great = b; 
        *add_small = a; 
    } 
} 
  
/* Returning multiple values using structures : As the structure is a user-defined datatype. The idea is to define a structure with two integer variables and store the greater and smaller values into those variable, then use the values of that structure. */
struct greaterSmaller { 
    int greater, smaller; 
}; 
  
typedef struct greaterSmaller Struct; 
  
Struct findGreaterSmaller(int a, int b) 
{ 
    Struct s; 
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

/* Returning multiple values using an array (Works only when returned items are of same types): When an array is passed as an argument then its base address is passed to the function so whatever changes made to the copy of the array, it is changed in the original array.
Below is the program to return multiple values using array i.e. store greater value at arr[0] and smaller at arr[1].*/
// Store the greater element at 0th index 
void findGreaterSmaller_ret_using_array(int a, int b, int arr[]) 
{ 
  
    // Store the greater element at 
    // 0th index of the array 
    if (a > b) { 
        arr[0] = a; 
        arr[1] = b; 
    } 
    else { 
        arr[0] = b; 
        arr[1] = a; 
    } 
} 

// Driver code 
int main() 
{ 
    int great, small, x, y; 
  
    printf("Enter two numbers: \n"); 
    scanf("%d%d", &x, &y); 
  
    // The last two arguments are passed 
    // by giving addresses of memory locations 
    compare(x, y, &great, &small); 
    printf("\nThe greater number is %d and the"
           "smaller number is %d", 
           great, small); 

    Struct result;
    // The last two arguments are passed 
    // by giving addresses of memory locations 
    result = findGreaterSmaller(x, y); 
    printf("\nThe greater number is %d and the"
           "smaller number is %d", 
           result.greater, result.smaller); 
  
    int arr[2]; 
    findGreaterSmaller_ret_using_array(x, y, arr); 
  
    printf("\nThe greater number is %d and the"
           "smaller number is %d", 
           arr[0], arr[1]); 
    return 0; 
} 
