class Solution {
public:
    // find min ops to make grid uni-value
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        int m = grid.size(), n = grid[0].size();
        //flatten grid
        for (const auto& row : grid)
            for (int num : row)
                values.push_back(num);
        // check if all values have same remainder mod x
        int base = values[0] % x;
        for (int num : values)
            if (num % x != base)
                return -1; //not possible
        // sort values to find optimal median
        sort(values.begin(), values.end());
        int median = values[values.size() / 2]; //median gives min cost
        // calc total ops
        int minOps = 0;
        for (int num : values)
            minOps += abs(num - median) / x; //convert to median
        return minOps;
    }
};
/* App - finds min ops to make all grid elements same by adding/subtracting x.
        Uses median as target for min cost conversion.
*/
// TC - O(m*n log(m*n)) -> sorting dominates
// SC - O(m*n) -> storing all grid values in a 1D array