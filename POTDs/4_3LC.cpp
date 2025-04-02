class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        //Early termination for arr.size < 3
        if (n < 3) return 0;

        long long maxRes = 0;
        int maxVal = nums[0];
        int maxDiff = 0;

        for (int i = 1; i < n; i++) {
            //Use curr num as nums[k]
            maxRes = max(maxRes, (long long)maxDiff * nums[i]);
            //Use curr num as nums[j]
            maxDiff = max(maxDiff, maxVal - nums[i]);   
            //Use curr num as nums[i] for future calc
            maxVal = max(maxVal, nums[i]);
        }
        return maxRes;
    }
};

//App: Maintain maxVal (best nums[i]) and maxDiff (best nums[i] - nums[j])
//     Iterate once, update maxDiff and maxRes efficiently
//TC: O(N) -> Single pass through array
//SC: O(1) -> Only a few extra variables used    