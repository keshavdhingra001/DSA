class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> rotatedArr(n);
        for (int i = 0; i < n; i++) {
            //shift element idx by k
            //cycle if we exceed n
            rotatedArr[(i + k) % n] = nums[i];
        }
        nums = rotatedArr;
    }
};
// App - Using vector to str rotated elements and then copying it back to the original vector
// TC - O(n), where n is the size of the array (one pass to compute the new positions of the elements)
// SC - O(n), for the space used by the rotatedArr vector