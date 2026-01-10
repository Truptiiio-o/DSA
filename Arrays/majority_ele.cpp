/*
QUESTION:
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
            }

            if (x == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};
