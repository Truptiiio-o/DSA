/*
Question:
Given a VPS represented as a string s, return the nesting depth of s.

Approach:
1. Initialize `opened` as 0 and `ans` as 0 to keep track of the number of opened parentheses and the maximum nesting depth respectively.
2. Iterate through each character `c` in the string `s`.
    a. If `c` is an opening parenthesis '(', increment `opened` by 1 and update `ans` if it is greater than the current value of `ans`.
    b. If `c` is a closing parenthesis ')', decrement `opened` by 1.
3. Return `ans` as the maximum nesting depth.*/

class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
                if(open>ans) ans++;
            }
            else if(s[i]==')') open--;
            else continue ;
        }
        return ans;
    }
};
// Tc=O(n)
