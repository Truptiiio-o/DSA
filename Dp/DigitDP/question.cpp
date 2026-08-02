//Right now, your code calculates the count from $0$ to $R$. 
//If a problem asks for the count in the range $[L, R]$, you don't need to change the solve function.
//You use the mathematical principle of prefix sums:$$\text{Count in } [L, R] = solve(R) - solve(L - 1)
//(Note: Since $L$ can be a massive string like $10^{18}$, subtracting 1 from a string representation requires a small helper function, or you just check if $L$ itself satisfies the condition and subtract it if it doesn't).


#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dp[100][181][2];

int solve(string& num, int n, int x, bool tight) {
    // If the target sum drops below zero, this path is invalid
    if (x < 0) return 0;
    
    // Base Case: We have placed all digits. 
    // Did we exactly hit the target sum?
    if (n == 0) {
        if (x == 0) return 1;
        return 0;
    }
    
    // Return memoized result
    if (dp[n][x][tight] != -1) return dp[n][x][tight];
    
    int ans = 0;
    
    // Calculate the current index in the string (0-indexed)
    int current_idx = num.length() - n;
    
    // Set the upper bound for the digit we can place
    int ub = tight ? (num[current_idx] - '0') : 9;
    
    for (int i = 0; i <= ub; i++) {
        // The next state is tight ONLY IF the current state is tight 
        // AND we placed the maximum possible digit (i == ub)
        bool next_tight = tight && (i == ub);
        
        ans += solve(num, n - 1, x - i, next_tight);
    }
    
    return dp[n][x][tight] = ans;
}

int main() {
    // We want numbers between 0 and 1152 whose digits sum to 5
    string R = "1152";
    int target_sum = 5;
    
    memset(dp, -1, sizeof dp);
    
    // Initial call: n = R.size(), x = target_sum, tight = true
    cout << solve(R, R.size(), target_sum, true) << endl;
    
    return 0;
}
