class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
    int arr[m+1][n+1];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(text1[i]!=text2[j])
                arr[i+1][j+1]=max(arr[i+1][j],arr[i][j+1]);
                else 
                arr[i+1][j+1]=arr[i][j]+1;
            }
        }
        return arr[m][n];
    }
    
};