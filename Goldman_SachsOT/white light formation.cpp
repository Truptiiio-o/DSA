vector<vector<int>> merge(vector<vector<int>>& strips){
  if(strips.empty()) return {};
  sort(strips.begin(),strips.end());
  vector<vector<int>> flat;
  for(auto &it:strips){
    if(flat.empty() || flat.back()[1]<it[0]){
      flat.push(it);
    }else{
      flat.back()[1]=max(flat.back()[1],it[1]);
    }
  }
  return flat;
}

int countwhitepoints(int k,vector<vector<int>>& lights){
  unordered_map<int,vector<vector<int>>> colors;
  for(auto& it:lights){
    int col=it[0];
    int left=it[1];
    int right=it[2];
    colors[col].push_back({left,right});
  }

  map<int,int> times;
  for(auto& [color,strips] : colors){
    vector<vector<int>> cleaned=merge(strips);
    for(auto& it:cleaned){
      time[it[0]]+=1;
      time[it[1]+1]-=1;
    }
  }

  int whites=0;
  int active =0;
  int prevpos=-1;
  for(auto& [pos,count]: time){
    if(active==k && prevpos!=-1){
      whites+=(pos-prevpos);
    }
    active+=count;
    prevpos=pos;
  }

  return whites; 
}
