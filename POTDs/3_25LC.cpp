class Solution {
public:
    //chck if possible to make at least 2 valid cuts
    bool canCut(vector<vector<int>> rects, int k) {
        //sort rect based on the k-th coordinate (either x or y)
        sort(rects.begin(), rects.end(), [k](const vector<int>& rect1, const vector<int>& rect2) {
            return rect1[k] < rect2[k]; 
        });
        
        //cnt valid cuts
        int cutCnt = 0;
        //tracks max endpoint
        int maxEndpt = rects[0][k + 2];

        //iterate through rects to chck for valid cuts
        for (int i = 1; i < rects.size(); i++) {
            int start = rects[i][k];    //str of crnt rect
            int end = rects[i][k + 2]; //end of crnt rect
            
            //if valid gap, inc cutCnt
            if (maxEndpt <= start) {
                cutCnt++;
            }
            
            //update maxEndpt
            maxEndpt = max(maxEndpt, end);
        }
        
        //at least 2 valid cuts should be present
        return cutCnt >= 2;
    }

    //chck if grid can be divided into sections
    bool checkValidCuts(int n, const vector<vector<int>>& rectangles) {
        return canCut(rectangles, 0) || canCut(rectangles, 1);
    }
};
/* App - chcks if grid can be divided into at least 2 valid sections 
        using vert or horz cuts based on coord sorting.
*/
// TC - O(n log n), where n is num of rects (sorting complexity)
// SC - O(n), due to copy of rects for sorting