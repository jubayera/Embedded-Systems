/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
If the last word does not exist, return 0.
Note: A word is defined as a maximal substring consisting of non-space characters only.
Example:
Input: "Hello World"
Output: 5
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
		
        int count = 0; //count how many characters in the last word
        int n = s.size(); //sze of the provided string
        int i = 0; //to start iterating from the beginning of the string
        
        while(i < n) {
			if(s[i] != ' ') {
				count++;
				i++;
			}
			else {
				//current character is a space
				while(i < n && s[i] == ' ')
					i++;
				if(i == n) { //end of string is reached
					return count;
				}
				else {
					count = 0;
				}
			}
		}
		return count;
    }
};
