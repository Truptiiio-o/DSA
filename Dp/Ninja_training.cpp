int help(int day ,vector<vetor<int>> &points, int prev,vector<vector<int>> &dp){
  if(day==0){
    int maxi=0;
    for(int i=0;i<3;i++){
      if(i!=prev){
      if(points[day][i]>maxi){
        maxi=points[day][i];
      }
    }
    }
    return maxi;
  }
  if(dp[day][prev]!=-1) return dp[day][prev];
  
  int maxi=0;
  for(int i=0;i<3;i++){    
    if(i!=prev){
      int points=points[day][i]+f(day-1,points,i,dp);
      if(points>maxi){
        maxi=points;
      }
    }
  }
  return dp[day][prev]= maxi;
 }

int ninjatraining(int n,vector<vector<int>> &points){
  
  vector<vector<int>> dp(n+1,-1);
  return (help(n-1,points,3,dp);
  //tabulation 
  dp[0,1]=max(points[0][2],points[0][0]);
  dp[0,2]=max(points[0][1],points[0][0]);
  dp[0,0]=max(points[0][2],points[0][1]);
  dp[0][3]=max(points[0][1],max(points[0][2],points[0][0]));
    for(int i=1;i<n;i++){
      for(int j=0,j<4;j++){
        dp[i][j]=0;
        int maxi=0;
        for(int task=0;task<3;task++){
          if(task!=j){
        points=dp[i-1][task]+points[i][task];
            if(points>maxi) maxi=points;
        }
    }
        dp[i][j]=maxi;
        
      }
    }
   return (dp[n-1][3]);

}
