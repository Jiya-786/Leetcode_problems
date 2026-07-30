class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                // Smallest value so far
                first = num;
            } else if (num <= second) {
                // Second smallest value (greater than some earlier first)
                second = num;
            } else {
                // Found a value greater than both first and second
                return true;
            }
        }

        return false;
    }
};