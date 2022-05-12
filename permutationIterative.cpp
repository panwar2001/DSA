/*Algorithm :

1) Find longest non-increasing suffix in the array.

2) If the whole array is non-increasing sequence of strings, next permutation isn't possible.

3) Otherwise, "key" is the string just before the suffix.

4) Find the rightmost string in suffix, which is lexicographically larger than key.

5) Swap key with this string.

6) Reverse the suffix.
*/
bool perm(vector<int>&nums){
        int i=nums.size()-1,j=nums.size()-1;
        while(i>0&&nums[i-1]>=nums[i])i--;
        if(i-1<0)return 0;
        while(j>i-1&&nums[j]<=nums[i-1])j--;
        swap(nums[--i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        return 1;
    }