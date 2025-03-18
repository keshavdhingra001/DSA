class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //using map for o(1) look up
        unordered_map<int, int> freq;
        //track freq of each int
        for (int num : nums) {
            freq[num] += 1;
        }
        //if all even can form pairs and return true else false
        return all_of(freq.begin(), freq.end(), [](const auto& t) { return t.second % 2 == 0;});
    }
};

//App- Using a hash map to count frequencies and checking if all counts are even using all_of
//TC- O(n) where n is the array size
//SC- O(n) for the frequency map storage    