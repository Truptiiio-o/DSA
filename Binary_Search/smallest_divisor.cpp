/*
Question:
You are given an array of integers nums and an integer threshold. We need to find the smallest divisor
such that the result of dividing each element of the array by the divisor and summing up the results
is less than or equal to the threshold.

Example:
Input: nums = [1,2,5,9], threshold = 6
Output: 5*/

bool possible(vector<int> &nums, int divi,int thresh){
  int sum=0;
  for(int i=0;i<nums.size();i++){
    sum+=(nums[i]+divi-1)/divi;
  }
  return sum<=thresh;
}

int smallest_divisor(vector<int> &nums,int threshold){
  int low=1;
  int high=*max_element(nums.begin(),nums.end());
  int ans=high;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(possible(nums,mid,threshold)){
      ans=mid;
      high=mid-1;
    }
    else low=mid+1;
  }
  return ans;
}
/*Tc 
the possible runs O(n) ... one pass over the array 
and the smallest divisor runs for O(logM) .. where M is the max in array
TOTAL TC = O(nLogM)
SC=O(1)*/
