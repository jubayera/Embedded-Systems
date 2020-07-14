//Reverse String.
/* Write a function that reverses a string. 
Do not allocate extra space for another array, you must do this by modifying the 
input array in-place with O(1) extra memory.*/

class Solution {
	public:
		void reverseString(vector<char>& A) {
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
		}
}
