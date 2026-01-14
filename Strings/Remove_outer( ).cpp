/*
Question:
Given a valid parentheses string `s`, remove the outermost parentheses of every primitive string in the primitive decomposition of `s`.

Approach:
- We can iterate through the characters of the string and keep track of the number of open parentheses encountered.
- Whenever we encounter an opening parenthesis, if the count of open parentheses is greater than 0, we append it to the result string.
- When we encounter a closing parenthesis, we decrement the count of open parentheses and append it to the result string only if the count is greater than 1.*/

string removeOuterParentheses(string s) {
        
        string ans="";
        int count=0;
        for(char c : s){
            if(c=='('){
                if(count>0) ans+=c;
                count++;
            }
            else{
                count--;
                if(count>0) ans+=c;
            }
        }
        return ans;}

//WITH STACK
string removeOuterParentheses(string s) {
    stack<char> st;
    string ans = "";

    for (char c : s) {
        if (c == '(') {
            if (!st.empty()) ans += c;  // not outermost '('
            st.push(c);
        } else { // ')'
            st.pop();
            if (!st.empty()) ans += c;  // not outermost ')'
        }
    }
    return ans;
}
