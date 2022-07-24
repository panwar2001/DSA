
class Solution {
    public:
 int majorityElement(vector<int>& nums) {
        int count = 0,candidate = null;
          for(int &num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

/* Boyer moore voting algorithm for n/3 elements of an array
https://leetcode.com/problems/majority-element-ii/discuss/543672/BoyerMoore-majority-vote-algorithm-EXPLAINED
*/