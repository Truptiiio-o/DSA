#include<iostream>
using namespace std;

int getnum(char c){
    return c - '0';
}

int atoi(string s){
    int n = s.length();
    int ans = 0;

    for(int i = 0; i < n; i++){
        // digit check
        if(s[i] < '0' || s[i] > '9')
            return -1;

        ans = ans * 10 + getnum(s[i]);
    }
    return ans;
}
// APPROACH 
// START FROM THE FIRST CHARACTER AND THEN MOVE FORWARD SLOWLY BY MULTIPLYING THE ANS BY 10 EACH TIME YOU ARE ABT TO ADD THE NEXT INTEGER 
//CHECK IS THEY BELONG TO 0 TO 9 ELSE RETURN -1 

