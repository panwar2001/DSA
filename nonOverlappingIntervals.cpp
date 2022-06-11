class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0,l=intervals.size();
        sort(intervals.begin(),intervals.end(),[&](auto &a,auto& b)->bool{
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
        });
        for(int i=1,j=0;i<l;i++){
            if(intervals[i][0]>=intervals[j][1]){j=i;continue;}
            count++;
            if(intervals[i][1]<intervals[j][1])
                j=i;
        }
        return count;
    }
};