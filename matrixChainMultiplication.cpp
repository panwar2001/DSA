https://leetcode.com/problems/burst-balloons/
class Solution {
public:
    int dp[302][302]={};
    int maxCoins(vector<int>& nums) {
        nums.push_back(0);
        for(int i=nums.size()-1;i>0;i--)nums[i]=nums[i-1];
        nums.push_back(1);
        nums[0]=1;
        return ans(nums,1,nums.size()-1);
    }
    int ans(vector<int>&nums,int i,int j){
        if(i>j)return 0;
        if(dp[i][j])return dp[i][j];
        for(int k=i;k<j;k++){
            dp[i][j]=max(dp[i][j],ans(nums,i,k)+ans(nums,k+1,j)+nums[i-1]*nums[k]*nums[j]);
        }
    return dp[i][j];
    }
};