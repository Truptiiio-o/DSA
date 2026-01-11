/*
QUESTION:
Given an integer array of size n, find all elements that appear more than ⌊ n/2 ⌋ times.

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

        for (int i=0;i<nums.size();i++) {
            if (count == 0) {
                candidate = nums[i];
                count=1;
            }
            else if(nums[i] == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};


// same majorty element question for n/3 times 
//APPROACH
/*1. Initialize two candidate variables, c1 and c2, and their corresponding vote counters, vote1 and vote2.
2. Iterate through the array:
   - If the current element matches c1, increment vote1.
   - Else if the current element matches c2, increment vote2.
   - Else if vote1 is 0, assign the current element to c1 and set vote1 to 1.
   - Else if vote2 is 0, assign the current element to c2 and set vote2 to 1.
   - Else, decrement both vote1 and vote2.
3. After finding the potential candidates, count the occurrences of each candidate using cnt1 and cnt2.
4. If cnt1 is greater than ⌊ n/3 ⌋, add c1 to the result vector.
5. If cnt2 is greater than ⌊ n/3 ⌋ and c2 is different from c1, add c2 to the result vector.
6. Return the result vector containing the elements that appear more than ⌊ n/3 ⌋ times.*/


vector<int> majorityele(vector<int> &nums){
    int c1=0;
    int c2=0;
    int vote1=0;
    int vote2=0;
    for(int i-0;i<nums.size();i++){
        if(nums[i]==c1) vote1++;
        else if(nums[i]==c2) vote2++;
        else if(vote1==0){
            vote1++;
            c1=nums[i];
        }
        else if(vote2==0){
            vote2++;
            c2=nums[i];
        }
        else{
            vote1--;
            vote2--;
        }
    }

    int cnt1=0 , cnt2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==c1) cnt1++;
        else if(nums[i]==c2) cnt2++;
    }

    vector<int> ans;
    int n=nums.size();
     if (cnt1 > n / 3) ans.push_back(c1);
        if (cnt2 > n / 3) ans.push_back(c2);

        return ans;
}
