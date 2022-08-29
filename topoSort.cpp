class KhanTopoSort{
    vector<vector<int>>graph;
    vector<int>indegree;
    int n;
  public:
    KhanTopoSort(int n,vector<vector<int>>& directedEdges){
        this->n=n;
        graph.resize(n);
        indegree.resize(n,0);
        for(auto &edge:directedEdges){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
    }
    vector<int> topoSort(){
        queue<int>que;
        vector<int> topoSortedArray;
        int u,nodes=0;
        for(int i=1;i<n;i++){
            if(indegree[i]==0)
                que.push(i);
        }
        while(!que.empty()){
          u=que.front();
          que.pop();
            nodes++;
            topoSortedArray.push_back(u);
          for(auto &v:graph[u]){
               if(--indegree[v]==0)
                   que.push(v);
          }
        }
        if(nodes!=(n-1))
            return {};
        return topoSortedArray;
    }
};
