class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),s=0,c=0;
      vector<vector<int>>edges;
      for(int i=0;i<n-1;i++)
          for(int j=i+1;j<n;j++) 
edges.push_back({abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]),i,j});
        sort(edges.begin(),edges.end());
        vector<int>p(n);
        for(int i=0;i<n;i++)p[i]=i;
        int a,b;
        for(vector<int> i:edges)
        {
            a=find(p,i[1]);
            b=find(p,i[2]);
            if(a!=b)
            {p[a]=min(a,b);
             p[b]=min(a,b);
             s+=i[0];
             c++;
             if(c==n-1)break;
            }
        }
        return s;
    }
    int find(vector<int>&p,int i)
    {
        if(i==p[i])return i;
        return find(p,p[i]);
    }
};