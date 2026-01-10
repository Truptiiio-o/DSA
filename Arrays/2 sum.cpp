/*
QUESITON:-
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

/* APPROACH 
    1. SORT
    2. I=0 J=N-1
    3. Check sum== target .. if yes return the original index values of each
    4. sum<target so we need to increase the value therefore i++
    5. else sum>target to decrease the value j--
    6. till i<j
    */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;

        for (int i = 0; i < nums.size(); i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        int i = 0, j = arr.size() - 1;

        while (i < j) {
            int sum = arr[i].first + arr[j].first;

            if (sum == target)
                return {arr[i].second, arr[j].second};
            else if (sum < target)
                i++;
            else
                j--;
        }
        return {};
    }
};
