/*QUESTION:
Given an integer array nums of unique elements, return all possible subsets (the power set).

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]*/

void powerset(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int start)
{
  if(start==nums.size()){
    ans.push_back(curr);
    return;
  } 
  curr.push_back(nums[start]);
  powerset(ans,curr,nums,start+1);
  curr.pop_back();
  powerset(ans,curr,nums,start+1);
}

vector<vector<int>> subsets(vector<int> nums){
  vector<vector<int>> ans;
  vector<int> curr;
  powerset(ans,curr,nums,0);
  return ans;
}


// APPRAOCH

/*
TC=O(2^n)
1.in this we used recurssion followed by back tracking 
2. i needed subsets , so to form subsets follow the tree method while having two choices either including a particular didgit or excuding it
3. in this waay i tree will be formed so the same thing was used here 
4. firstly i inserted the element into the curr and then calleed the function again for start +1
5. then i poped it out and simply called the function for start +1 
6. here the forst one was the step for inclusion while the second one was the step for exclusion where we just moved forward without adding anything

*/
