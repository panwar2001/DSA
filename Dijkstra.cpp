/*
Dijkstra Algorithm
(1) Create an adjacency list such that adj[source] contains all destination nodes (dest) that the signal can travel to from the source node (source). For each destination node, there will be a pair (time, dest). Here, time denotes the time required for the signal to travel from source to dest.

(2) For all nodes, initialize signalReceivedAt as a large value to signify that, so far, no signal has been received.

(3) Initialize priority queue with the pair of starting node kk and its distance 00, store its distance in signalReceivedAt as 00. While the priority queue is not empty:

(4) Pop the top node currNode from the priority queue.

(5)Traverse all outgoing edges connected to currNode.
 
(6)Add the adjacent node neighborNode to the priority queue only if the current path takes less time than the value at signalReceivedAt[neighborNode]. Update the time at signalReceivedAt[neighborNode] to current path time.

(7) If any value in signalReceivedAt is still the large value we initialized the array with, then return -1 as that node is not reachable from k. 
*/
typedef pair<int,int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=0;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        vector<pii>g[n+1];
        for(auto& i:times) 
         g[i[0]].push_back({i[2],i[1]});
         
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,k});
        pii u;
        while(!pq.empty()){
            u=pq.top();
            pq.pop();
            for(auto& v:g[u.second]){
                if(dist[u.second]+v.first<dist[v.second]){
                    dist[v.second]=dist[u.second]+v.first;
                    pq.push({dist[v.second],v.second});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
