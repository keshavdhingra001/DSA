class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // If the difference exceeds k, close current group and start a new one
            if (nums[i] - nums[start] > k) {
                count++;
                start = i;
            }
        }
        // Final group needs to be counted too
        return count + 1;
    }
};

/* App - Sort the array, then greedily build subsequences where max - min ≤ k.
         Each time the difference exceeds k, start a new subsequence.

   TC - O(n log n), due to sorting.
   SC - O(1), using constant space (excluding sort).
*/
