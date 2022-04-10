/*String matching algorithm 
 *It is a substitute for KMP string matching algorithm 
 *BOTH kmp and z algorithm have time complexity of O(m+n) (linear time)
 */
void zAlgo(string s){ 
    vector<int>z(s.size(),0);
/*each element of z array will store the length of the longest common prefix of    String to the longest suffix starting at index of the element*/
    int l=s.size(),left=0,right=0;
    for(int i=1;i<l;i++){
/* If length was previously computed for the suffix, use the precomputed length 
   and store it in z[i] ,then continue to next iteration*/
       if(z[i-left]<right-i+1) {
            z[i]=z[i-left];
            continue;
        }
/*if index is greater than right pointer to the precomputed length, then update the 
  right pointer to current index because left to right depicts the region of precomputed length , now i>right means right pointer is to be updated to calculate new length of longest common suffix to the prefix.*/
       if(i>right) right=i;
       left=i;   
/*apply naive approach to compute the length of common string pattern , traversing the  string and updating the right pointer*/
       while(right<l&&s[right]==s[right-left])right++;
       z[i]=right-left;  //right-left is the length of the matching string
       right--;   //decrement right pointer 
    }
 }