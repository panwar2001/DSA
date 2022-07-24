// x = array of numbers
// n = length of the array
// k = search key
// returns "true" if the key is found, "false" otherwise

bool search(int x[], int n, int k) {
    int l = 0, r = n-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (x[m] == k) return true;
        if (x[m] < k) l = m+1; else r = m-1;
    }
    return false;
}

/*lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. */
/*upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.*/
/*upper bound logic*/
int upperbound(vector<int>&v,int x)
{
	if(x>v.back())return v.size();
	int l=0,r=v.size(),mid;
    while(l<r)
	{   mid=l+(r-l)/2;
		if(x>=v[mid])l=mid+1;
		else r=mid;
	}
  return l;	
}

/*lower bound logic*/
int lowerbound(vector<int>&v,int x)
{
	if(x>v.back())return v.size();
	int l=0,r=v.size(),mid;
    while(l<r)
	{   mid=l+(r-l)/2;
		if(x<=v[mid])r=mid;
		else l=mid+1
	}
  return l;	
}
//finding first and last position of an element in the array easy binary search method
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int>pos(2,-1);
        int l=0,r=nums.size()-1,mid;
		//first position of the element 
         while(l<=r){
             mid=l+(r-l)/2;
             if(nums[mid]==target){
                 pos[0]=mid;
                 r=mid-1;
             }
             else if(nums[mid]<target)l=mid+1;
             else r=mid-1;
         }
        //last position of the element 
        l=0,r=nums.size()-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){
                pos[1]=mid;
                l=mid+1;
            }
            else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        return pos;
    }
};