class Solution {
public:
    //partition string into parts so each letter appears in at most one part
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.size();
        //store last occurrence for each char (only 26 lowercase letters)
        int last[26] = {0};
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        int partStart = 0, partEnd = 0;
        //iterate through string
        for (int i = 0; i < n; i++) {
            //update partEnd with last occurrence of current char
            partEnd = max(partEnd, last[s[i] - 'a']);
            //if reached the end of a partition, record its size
            if (i == partEnd) {
                ans.push_back(i - partStart + 1);
                partStart = i + 1;
            }
        }
        return ans;
    }
};
/* App - partitions string s into maximum parts such that each letter appears in at most one part
*/
//TC - O(n) -> one pass to build last-occurrence array, one pass for partitioning
//SC - O(1) -> constant space (array of size 26)