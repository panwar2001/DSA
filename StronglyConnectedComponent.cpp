// GRAPHS for strongly connected component.
//    https: // leetcode.com/problems/critical-connections-in-a-network/
// Two algorithms are used, tarjans algorithm or kosarajus algorithm , here kosarajus is comparatively 
// easier to understand.
class Solution {
    vector<vector<int>>cri;
    vector<bool>vis;
    vector<int>time;
    vector<int>low;
    int t=1;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vis=vector<bool>(n,0);
        time=vector<int>(n,-1);
        low=vector<int>(n,-1);
        vector<int>g[n];
        for(auto& i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(-1,0,g);
        }
        return cri;
    }
    void dfs(int parent ,int u,vector<int>*g){
        low[u]=time[u]=t++;
        vis[u]=1;
        for(auto& v: g[u]){
            if(v==parent)continue;
            if(vis[v]){
                low[u]=min(low[u],time[v]);
            }
            else {
                dfs(u,v,g);
                low[u]=min(low[u],low[v]);
                if(low[v]>time[u])cri.push_back({u,v});
            }
        }
    }
};