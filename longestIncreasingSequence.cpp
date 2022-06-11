#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n;
        vector<int>l;
        for(int i:nums){
         n=lower_bound(l.begin(),l.end(),i)-l.begin();
            if(n==l.size())
                l.push_back(i);
            else l[n]=i;
        }
        return l.size();
    }
};