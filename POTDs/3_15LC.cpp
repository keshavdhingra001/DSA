class Solution {
public:
    //chk if possible to rob at least k houses 
    //with max cap of mid
    bool canRob(vector<int>& nums, int mid, int k) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            // if stash amt ≤ mid,
            // we rob & skip nxt term(adj rule)
            if (nums[i] <= mid) {
                cnt++;
                i++;
            }
        }
        //return true if robbed at least k houses
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        //use Binary search approch
        //to find min possible max cap
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        //keep track of min cap
        int minCap = hi;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canRob(nums, mid, k)) {
                //if robbing possible, we update minCap
                minCap = mid;
                hi = mid - 1;
            } else {
                //inc lo if mid's too small
                lo = mid + 1;
            }
        }
        return minCap;
    }
};

/* App- Using binary search to efficiently find possible caps and then finding min in them, while keeping track of prev min possible
        canRob - checks if it's possible to rob at least k houses while following adjacency constraints
*/
// TC - O(n log m) where n is array size and m is max element in nums
// SC - O(1) as we use constant extra space