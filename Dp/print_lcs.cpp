string printLCS(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 1: Pehle sirf table bharo
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

  ///NOW basically traverse through the dp table to get the sequnce u want to print 
        // that is the longest common subsequence 
        string res="";
        int i=n,j=m;
        while(i>0 && j>0){
                if(text1[i]==text[j]){
                        ans+=text1[i];
                        j--;
                        i--;
                }else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--; // Upar bada hai toh upar jao
                } else {
                j--; // Left bada hai toh left jao
            }
                
        }
  reverse(res.begin(), res.end()); // Kyuki humne end se start kiya tha
        return res;



}
