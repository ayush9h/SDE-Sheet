class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int r=grid.size(),c=grid[0].size();
        vector<vector<bool>> vis(r,vector(c,false));
        int dir_x[]={0,0,1,-1};
        int dir_y[]={1,-1,0,0};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0 || vis[i][j])
                    continue;
                queue<pair<int,int>> q;
                int island=0;
                q.push({i,j});
                vis[i][j]=true;
                while(!q.empty()){
                    auto front=q.front();
                    q.pop();
                    island++;
                    for(int d=0;d<4;d++){
                        int qr= front.first + dir_x[d];
                        int qc= front.second + dir_y[d];
                        if(qr<0 || qr>=r || qc<0 || qc>=c){
                            continue;
                        }
                        if(grid[qr][qc]==0) continue;
                        if(vis[qr][qc]) continue;
                        q.push({qr,qc});
                        vis[qr][qc]=true;
                    }
                }
                ans=max(ans,island);
            }
        }
        return ans;
    }
};
