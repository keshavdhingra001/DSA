class Solution {
public:
    typedef long long ll;

    long long repairCars(vector<int>& ranks, ll cars) {
        //using binary search approach  
        //to find the min repair time efficiently  
        ll lo = 1, hi = *max_element(ranks.begin(), ranks.end()) * (ll)(cars * cars);
        
        //keeps track of possible min repair time  
        ll minTime = 0;

        //lamda function canRepair   
        //efficiently chks if all cars can be repaired in time  
        auto canRepair = [&](ll mid) -> bool {
            ll repairedCars = 0;

            //Iterate through each rank for cnt of repair car by each rank  
            //if the sum >= all cars to be repaired return true else false  
            for (int rank : ranks) {
                // Exp finds out how many cars can each rank repair in time  
                repairedCars += (ll)sqrt(mid / rank);
                if (repairedCars >= cars) return true;
            }
            return false;
        };

        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (canRepair(mid)) {
                //keeps track of possible minTime  
                minTime = mid;
                hi = mid - 1; // if mid too big find smaller  
            } else {
                lo = mid + 1;// if mid too small find bigger  
            }
        }
        return minTime;
    }
};

/*  
App - Using binary search to efficiently find possible times and then minimizing it,  
       while keeping track of previously found min possible time.  
       canRepair - checks if all cars can be repaired in `mid` time.  
*/
//TC - O(n log m), where n is the size of ranks and m is the max possible repair time  
//SC - O(1) as we use constant extra space