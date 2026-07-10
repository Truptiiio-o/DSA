class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        vector<pair<int, int>> jobs(n);
        int max_deadline = 0;
        
        for (int i = 0; i < n; i++) {
            // A job's effective deadline can't be more than n 
            // (we can at most do n jobs in n days)
            int effective_deadline = min(n, deadline[i]);
            jobs[i] = {profit[i], effective_deadline};
            max_deadline = max(max_deadline, effective_deadline);
        }
        
        // Sort in descending order of profit
        sort(jobs.rbegin(), jobs.rend());
        vector<int> parent(max_deadline + 1);
        for (int i = 0; i <= max_deadline; i++) {
            parent[i] = i;
        }
        
        int countJobs = 0;
        int totalProfit = 0;
        
        for (int i = 0; i < n; i++) {
            int availableSlot = find(jobs[i].second, parent);
            
            if (availableSlot > 0) {
                parent[availableSlot] = find(availableSlot - 1, parent);
                countJobs++;
                totalProfit += jobs[i].first;
            }
        }
        
        return {countJobs, totalProfit};
    }
};
