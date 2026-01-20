
       class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        // 1. Count frequency
        for(char c : s) {
            freq[c]++;
        }

        // 2. Max-heap: (frequency, character)
        priority_queue<pair<int,char>> pq;

        for(auto &p : freq) {
            pq.push({p.second, p.first}); // (frequency, character)
        }

        // 3. Build answer
        string ans;

        while(!pq.empty()) {
            auto top = pq.top(); 
            pq.pop();

            int count = top.first;
            char ch = top.second;

            while(count--) ans += ch;
        }

        return ans;   // <-- this was missing
    }
};

;
