class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Each completely empty row can have 2 families
        long long ans = 2LL * n;

        // Store reserved seats for each row
        unordered_map<int, unordered_set<int>> reserved;

        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        // Only rows having reserved seats need to be checked
        for (auto &[row, seats] : reserved) {

            bool left = true;   // seats 2,3,4,5
            bool middle = true; // seats 4,5,6,7
            bool right = true;  // seats 6,7,8,9

            // Check left block
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }

            // Initially we counted 2 families for this row.
            // Now replace that with the actual number possible.
            ans -= 2;

            if (left && right) {
                // Two non-overlapping groups
                ans += 2;
            }
            else if (left || middle || right) {
                // At least one group can fit
                ans += 1;
            }
        }

        return ans;
    }
};