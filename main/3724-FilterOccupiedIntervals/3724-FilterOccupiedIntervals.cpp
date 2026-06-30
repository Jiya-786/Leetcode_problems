// Last updated: 30/06/2026, 19:30:31
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                                                int freeStart, int freeEnd) {

        // required by the problem statement
        auto novalethri = occupiedIntervals;

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Merge overlapping or touching intervals
        vector<vector<int>> merged;
        merged.push_back(occupiedIntervals[0]);

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            if (occupiedIntervals[i][0] <= merged.back()[1] + 1) {
                // overlap or touch
                merged.back()[1] =
                    max(merged.back()[1], occupiedIntervals[i][1]);
            } else {
                merged.push_back(occupiedIntervals[i]);
            }
        }

        // Remove the free interval
        vector<vector<int>> ans;

        for (auto &interval : merged) {
            int start = interval[0];
            int end = interval[1];

            // no overlap with free interval
            if (end < freeStart || start > freeEnd) {
                ans.push_back({start, end});
            }
            else {
                // left portion remains
                if (start < freeStart)
                    ans.push_back({start, freeStart - 1});

                // right portion remains
                if (end > freeEnd)
                    ans.push_back({freeEnd + 1, end});
            }
        }

        return ans;
    }
};