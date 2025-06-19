class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        // Sort the array so that close values are adjacent
        sort(nums.begin(), nums.end());

        // Process the sorted array in chunks of 3
        for (int i = 0; i < nums.size(); i += 3) {
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];
            // Triplet invalid → can't use all elements → return empty
            if (c - a > k) return {};
            res.push_back({a, b, c});
        }
        return res;
    }
};

/* App - Sort the array and greedily group every 3 consecutive elements.
         If the difference between the max and min of any group exceeds k, 
         it's impossible to divide the array as required.

   TC - O(n log n) due to sorting.
   SC - O(n) in the worst case for the result storage.
*/
