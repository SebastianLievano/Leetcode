class Solution { 
public:
int DR[4]={1,0,-1,0};
int DC[4]={0,-1,0,1};

int numEnclaves(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
    }
    
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int row=r+DR[i];
            int col=c+DC[i];
            
            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && vis[row][col]==0){
                q.push({row,col});
                vis[row][col]=1;
            }
        }
    }
    
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0)
                count++;
        }
    }
    return count;
}
};