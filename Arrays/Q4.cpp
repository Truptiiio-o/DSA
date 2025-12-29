/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Example:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/


#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){
  vector<vector<int>> ans;
  int n=nums.size();
  sort(nums.begin(),nums.end());
  for (int i = 0; i < nums.size(); i++){
    if(i>0 && nums[i]==nums[i-1]){
      continue ;}
   int  j=i+1;
  int   k=n-1;
    if(nums[i]>0) break; ///because it is a sorted array then all numbers ahead of it are also >0 and can never make 0
    
    while(j<k){
      int sum=nums[i]+nums[j]+nums[k];
      if(sum<0){
        j++;
    }
      else if(sum>0){
        k--;
      }
      else{
        vector<int> temp={nums[i],nums[j],nums[k]};
        ans.push_back(temp);
        j++;
        k--;
        while(j<k && nums[j]==nums[j-1]) j++;
        while(j<k && nums[k]==nums[k+1]) k--;
      }
    
  }

  
}
  return ans;
}
