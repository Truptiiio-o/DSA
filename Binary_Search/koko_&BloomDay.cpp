/*
QUESTION:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

EXAMPLES:
Input: piles = [3,6,7,11], h = 8
Output: 4*/

bool isPossible(vector<int> &piles,int h,int k){
  int hour=0;
  for(int i=0;i<piles.size();i++){
    hour+=(piles[i]+k-1)/k;
  }
  return hour<=h;
}

int minEatingspeed(vector<int> &piles,int h){
  int low=1;
  int high=*max_element(piles.begin(),piles.end());
  int ans=high;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(isPossible(piles,h,mid)){
      ans=mid;
      high=mid-1;
    }
    else low=mid+1;
  }
  return ans;
}


// Question practice 
//Bloom days to make m bouquets 
/*
Question:
You are given an integer array bloomDay, an integer m, and an integer k. You want to make m bouquets. 
To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, where the i-th flower will bloom on the bloomDay[i] day and can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden.
If it is impossible to make m bouquets, return -1.
Example:
Input:
bloomDay = [1,10,3,10,2]
m = 3
k = 1*/

bool possible(vector<int> &bloomDay,int m,int k,int day){
  int bouquets=0;
  int count=0;
  for(int i=0;i<bloomDay.size();i++){
    if(bloomDay[i]<=day){
      count++;    
      if(count==k){
        bouquets++;
        count=0;
    }}
    else count=0;
  }
  return bouquets>=m;
}

int minDay(vector<int> &bloomDay,int m ,int k){
  long long n=bloomDay.size();
  if(1LL*m*k>n) return -1; /// 1LL is 1 in long long form for thr type conversion for comparison 
  
  int low=*min_element(bloomDay.begin(),bloomDay.end());
  int high=*max_element(bloomDay.begin(),bloomDay.end());
  int ans=-1;

  while(low<=high){
    int mid=low+(high-low)/2;
    if(possible(bloomDay,m,k,mid)){
      ans=mid;
      high=mid-1;
    }
    else low=mid+1;
  }
  return ans;
  
}






