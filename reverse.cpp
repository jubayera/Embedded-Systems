//Reverse String.
/* Write a function that reverses a string. 
Do not allocate extra space for another array, you must do this by modifying the 
input array in-place with O(1) extra memory.*/

class Solution {
	public:
		void reverseString(vector<char>& A) {
			/*
			stack<char> st;
			for(int i = 0; i < A.size(); i++) {
				//pushing every char inside stack
				st.push(A[i]);
			}
			
			//pop every character
			for(int i = 0; i < A.size(); i++) {
				A[i] = st.top();
				st.pop();
			}
			//using stack
			*/
			
			/*
			int s = 0;
			int e = A.size() - 1;
			
			while(s <= e) {
				swap(A[s], A[e]);
				s++;
				e--;
			}
			//using start, end pointer
			*/
			
			//using built-in reverse function
			reverse(A.begin(), A.end());
			
		}
}
