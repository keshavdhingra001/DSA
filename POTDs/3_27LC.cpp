class Solution {
public:
    //find min index where dominant element is majority in both parts
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int dom = 0, count = 0, n = nums.size();
        //count freq of each num
        for (int num : nums) 
            freq[num]++;
        //find dominant element
        for (auto& [num, c] : freq) {
            if (c > n / 2) {
                dom = num;
                count = c;
                break;
            }
        }
        //check min index for valid split
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dom) leftCount++;
            int leftSize = i + 1;
            int rightSize = n - leftSize;
            int rightCount = count - leftCount;
            //if dominant in both halves, return index
            if (leftCount > leftSize / 2 && rightCount > rightSize / 2) {
                return i;
            }
        }
        return -1; //no valid index
    }
};
/* App - finds min index where dominant element is majority in both left & right parts.
*/
// TC - O(n) -> single pass for freq count, another pass for index check
// SC - O(n) -> unordered_map stores freq counts