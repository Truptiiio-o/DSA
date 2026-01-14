/*
QUESTION:
Given an array arr[] of size N, check if it is sorted in non-decreasing order or not.*/

//APPROACH
/* to check if an array is sorted we are divinding array into two parts 
1. low to mid 
2. mid +1 to high 
again they themselves will keep on dividing until there is only one element left that is the base case 
if left and right is sorted the last case is to check if mid+1>mid and then if this is also true return true*/

bool check(vector<int> &nums , int low , int high){
  if(low>=high) return true;
  int mid =low+(high-low)/2;

  if(!check(nums,low,mid) return false;
  if(!check(nums,mid+1,high) return false;

  return nums[mid+1]>=nums[mid];
    
}

bool isSorted(vector<int> &nums){
  check(nums,0,nums.size()-1);
}


// TC - 2T(n/2) + O(1) so by master theorem .... Tc=O(n)
// SC = O(logn) for the recurrsive stack
