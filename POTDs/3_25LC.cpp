class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; // No meetings, all days are free
        //Sort meetings by start day
        sort(meetings.begin(), meetings.end());
        int freeDays = 0;
        int prevEnd = 0; // Track the last merged meeting end time
        //Merge overlapping meetings & count free days
        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > prevEnd + 1) {
                // Count free days between non-overlapping meetings
                freeDays += (start - prevEnd - 1);
            }
            // Update the last merged meeting end
            prevEnd = max(prevEnd, end);
        }
        //Count free days after the last meeting
        freeDays += (days - prevEnd);
        return freeDays;
    }
};
/* App - Sort the meetings by start time
         Merge overlapping intervals
         Count free days before first meeting, between merged meetings, and after last meeting
*/

// TC - O(N log N), sorting takes O(N log N) and merging runs in O(N)
// SC - O(1), only a few integer variables are used