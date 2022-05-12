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
