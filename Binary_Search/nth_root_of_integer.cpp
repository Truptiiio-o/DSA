/*
QUESTION:
You are given 2 numbers (n, m); the task is to find n√m (nth root of m).

Example:

Input: n = 2, m = 9
Output: 3
Explanation: 3^2 = 9

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not an integer.*/

long long power(long long base, int exp, long long limit) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
        if (result > limit) return result; // early stop to avoid overflow
    }
    return result;
}

int nthroot(int n, int m){
  int low=1;
  int high=m;
  while(low<=high){
    int mid = low + (high - low) / 2;
        long long val = power(mid, n, m);

        if (val == m) 
            return mid;
        else if (val < m) 
            low = mid + 1;
        else 
            high = mid - 1;
  }
  return -1;
}
