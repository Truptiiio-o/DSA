/*
QUESTION:
Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].
Floor of X is the largest element which is smaller than or equal to X. 
Floor of X doesn’t exist if X is smaller than the smallest element of Arr[].
Ceil of X is the smallest element which is greater than or equal to X.
Ceil of X doesn’t exist if X is greater than the greatest element of Arr[].
Input:
N = 8, X = 7
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 6 8
Explanation:
Floor of 7 is 6 and ceil of 7 is 8.*/

/* APPROACH 
  1. sort
  2.do for floor think of logic when it will be low=mid+1 and when hih=mid-1 bny takin g an example
  3. similarly take some eaxmple and think abt ceil case
  */

//TC = o(nlogn) + O(2*logn)
//sc = O(logN) beacuse sort uses reccurssion internally 

vector<int> bounds(vector<int> nums,int N , int X){
  sort(nums.begin(),nums.end());
  vector<int> ans;
  
  if(X>=nums[0]){
    int low=0;
  int high=N-1;
    while(low<=high){
      int mid=low + (high-low)/2;
      if(nums[mid]<=X) low=mid+1;
      else high=mid-1;
    }
    ans.push_back(nums[high]);
  }
  else ans.push_back(-1);

  if(X<=nums[N-1]){
    int low=0;
  int high=N-1;
    while(low<=high){
      int mid=low + (high-low)/2;
      if(nums[mid]>=X) high=mid-1;
      else low=mid+1;
    }
    ans.push_back(nums[low]);
    
  }
  else ans.push_back(-1);


  return ans
}
