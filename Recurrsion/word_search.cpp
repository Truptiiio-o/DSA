bool solve(vector<vector<char>>& board, string word,int i,int j,int index){
  if(index==word.length()) return true;

  if(i<0 || j<0 || i>=board.size() || j>= board[0].size() || board[i][j]=='#' || board[i][j]!=word[index]) return false;

  char temp=board[i][j];
  board[i][j]='#';
  bool found = solve(board,word,i-1,j,index+1) || solve(board,word,i+1,j,index+1) ||solve(board,word,i,j-1,index+1) || solve(board,word,i,j+1,index+1);

  board[i][j]=temp;
  return found;
}

bool exist(vector<vector<char>>& board, string word){
  int m=board.size();
  int n=board[0].size();
  for(int i=0;i<m;i++){{
    for(int j=0;i<n;j++){
      if(solve(board,word,i,j,0)) return true;
    }
  }
                       return false;
}


// TC=O(m*n*4*L) 
// APROACH
/*
1. use board , word , i , j for row and column index and then index for word index 
2. base condition is when we reach the end of the word 
3. also include boundary conditions 
4. store the vale at a particular board[i][j] in a temp then mark t as visited and search in all 4 directions around that point ... o
5. once this is done for back track place back the temp value in board[i][j] 

6. in the main function loop is running for the starting position there are m*n starting positions from each of which we should check whether the required word can be formed */
