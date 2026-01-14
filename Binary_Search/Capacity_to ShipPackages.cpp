/*
Question:
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i].Each day,we load the ship with packages on the conveyor belt (in the order given by weights).
We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10*/

/* 888888888 AAPROACH 888888888888
1. the high is the sum of all the weights that is all weight in one day
2. the low is the max weight in the array (cuz obv we can split the package weight if 10kg package is there we can't divide it to 5 5)
3.now calculate mod and check if we can ship with that mid number of caapcity per day
4. to check so we ahve canShip function which will iterate through the array 
if initial load + the weught[i] <capacity per day then add that weight to the load 
else increase the day cound and again start e=with load amt with load equal to that araray element weigths[i]
5. at last check if useddays are lesss than the days given 

*/

bool canShip(vetor<int> &weights,int days,int cap){
  int Useddays=1;
  int load=0;
  for(int i=0;i<weights.size();i++){
    if(load+weights[i]<cap){
      load+=weight[i];
    }
    else{
      Useddays++;
      load=weights[i];
    }
  }
  return Useddays<=days;
}


int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    for (int w : weights) high += w;

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, days, mid)) {
            ans = mid;        // mid works, save it
            high = mid - 1;   // try smaller capacity
        } else {
            low = mid + 1;    // need bigger capacity
        }
    }
    return ans;
}



/*
Tc = O(nlog(S-M)) n for the traversal each time in CanShip , and S is the sum of all the leemnets of the array , M is teh max element
Sc=O(1)

*/
