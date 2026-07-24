vector<long long> getMinIncrements(vector<long long>& positions, vector<long long>& radii) {
        int n = positions.size();
  if (n <= 1) return vector<long long>(n, 0);
  vector<int> idx(n);
  iota(idx.begin(),idx.end(),0);

  sort(idx.begin(),idx.end(),[&](int a,int b){
    return positions[a]<positions[b];
  });
  const long long INF=1e18;
  vector<long long> left_gap(n, INF);
  vector<long long> right_gap(n, INF);
  long long max_right=-INF;
  for(int i=0;i<n;i++){
    int original=idx[i];
    if(i>0){
      left_gap[i]=positions[original]-max_right-radii[original];
    }
    max_right=max(max_right,positions[original]+radii[original]);
  }

  long long min_left=INF;
  for(int n-1;i>=0;i--){
    int original=idx[i];
    if(i>n-1){
      right_gap[i]=min_left-positions[original]-radii[original];
    }
    min_left=min(min_left,positions[original]-radii[original]);
  }


  vector<long long> result(n);
        for (int i = 0; i < n; i++) {
            int original_id = idx[i];
            
            long long min_gap = min(left_gap[i], right_gap[i]);
            long long increment = max(0LL, min_gap);
            
            // Because we know the original_id, we just drop the answer in the right spot!
            result[original_id] = increment;
        }
        
        return result;
  
}
