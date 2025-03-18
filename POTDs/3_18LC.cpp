class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), maxCnt = 1;
        int l = 0, r = 0;
        //tracks bit(1) visited
        int tmp = 0;

        while (r < n) {
            //common bit(1) found, inc l
            while ((tmp & nums[r]) != 0) {
                //remove elmts from str
                tmp ^= nums[l];
                l++;
            }
            //`|=` ensures next element doesn't have a common bit(1)
            tmp |= nums[r];
            //update max
            maxCnt = max(maxCnt, r - l + 1);
            //otherwise, inc r
            r++;
        }
        return maxCnt;
    }
};
/* App - using sliding window and bit manipulation
         maxCnt track maximum size of nice subarray
         Expand window if no common bit(1)
         use OR(|) to ensure track bit(1)
         shrink window if common bit(1) found
         use XOR(^) to remove the effect of conflicting element starting from left
*/
// TC - O(n), as each element is added and removed at most once
// SC - O(1), using only a few integer variables