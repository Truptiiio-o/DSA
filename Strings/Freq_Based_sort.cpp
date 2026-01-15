class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        // 1. Count frequency
        for(char c : s) {
            freq[c]++;
        }

        // 2. Put into a vector of pairs (char, frequency)
        vector<pair<char, int>> arr;
        for(auto &p : freq) {
            arr.push_back({p.first, p.second});
        }

        // 3. Sort by frequency in decreasing order
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // 4. Build result string
        string ans = "";
        for(auto &p : arr) {
            ans.append(p.second, p.first);  // repeat char p.first, p.second times
        }

        return ans;
    }
};
