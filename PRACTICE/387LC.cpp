class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> freq;
            for (char c : s) freq[c]++;
            for (int i = 0; i < s.size(); i++) {
                if (freq[s[i]] == 1) return i;
            }
            return -1;
        }
    };
    
// App - Using unordered_map to str char freq then scan for the first unq char
// TC - O(n), where n is the length of the string (one pass to count frequencies, one pass to find the first unique character)
// SC - O(1), since the map stores at most 26 lowercase letters, making it constant space usage just keep it here to copy