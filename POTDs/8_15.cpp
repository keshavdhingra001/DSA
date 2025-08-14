class Solution {
public:
    string largestGoodInteger(string num) {
        char best = 0; // store largest digit found
        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                best = max(best, num[i]); // update if this digit is larger
            }
        }
        if (best == 0) return "";
        return string(3, best); // repeat best digit 3 times
    }

/* App - Iterate through the string, checking every group of 3 consecutive characters.
         If all 3 are identical, track the largest digit found.
         At the end, return that digit repeated 3 times.

   TC - O(n), single pass through the string.
   SC - O(1), only storing a few variables.
*/
};
