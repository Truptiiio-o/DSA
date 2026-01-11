/*
QUESTION:-
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
*/

//TC - O(logn)
//SC - O(logn) for both iteravive and reccurive 

#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
int low = 0;
int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) 
            return mid;
        else if (nums[mid] < target) 
            low = mid + 1;
        else
        high = mid - 1;
    }

    return -1;
}




/// recursive code 
int search(low,high,vector<int> &nums,target){
  
int mid = low + (high - low) / 2; //this prevents the overflow case and is safe (like if we do low +high directly and they have very high values this will lead to overflow 

  if(low>high) return -1;
  
  if(nums[mid] == target) return mid;

  if(nums[mid] < target)
    return(mid+1,high,nums,target);
  else if(nums[mid]>target)
    return(low,mid-1,nums,target);
    
}
