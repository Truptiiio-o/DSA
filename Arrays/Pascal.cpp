class Solution {
public:

    long long ncr(int n, int r) {
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1);
            res = res / i;
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i=0;i<=rowIndex;i++){
            ans.push_back(ncr(rowIndex,i));
        }
        return ans;
    }
};
