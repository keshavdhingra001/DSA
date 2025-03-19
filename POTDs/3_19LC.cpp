class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size(),minOp = 0;
    
            //brute force approach / greedy approach
            //just find 0 and perform op and keep track
            for (int i = 0; i < n; i ++) {
                //if fnd 0 inc minOp
                if (nums[i] == 0) {
                    minOp++;
                    //chk if op within bound possible else return -1
                    //if out of bound we remain with 0 in nums
                    if (i + 2 >= n) return -1;
                    //XOR with 1 res a flip //1^1 = 0 //0^1 = 1
                    //fip nxt 2 elmt as we would move to the next idx
                    //to perform nxt op if needed
                    nums[i + 1] ^= 1;
                    nums[i + 2] ^= 1;
                }
            }
            return minOp;
        }
    };
/* App - using Greedy approach 
         on sighting `0` flip 2 consecutive nxt elmnts to min op
         while keeping track minOp
*/
// TC - O(n), as we traverse the arr once & perform constant-time op per elmnt
// SC - O(1), as we modify the input arr in place without extra space usage