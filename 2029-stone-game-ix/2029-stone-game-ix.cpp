class Solution {
public:
    bool check(vector<int> cnt) {
        // Alice must start by taking a remainder-1 stone
        if (cnt[1] == 0) {
            return false;
        }

        cnt[1]--;

        int moves = 1 + min(cnt[1], cnt[2]) * 2;

        // If there are extra remainder-1 stones,
        // Alice can take one more.
        if (cnt[1] > cnt[2]) {
            cnt[1]--;
            moves++;
        }

        // Remainder-0 stones can be taken in between.
        moves += cnt[0];

        // Alice wins if:
        // 1. number of moves is odd
        // 2. some remainder-1/2 stone is still left
        return (moves % 2 == 1) && (cnt[1] != cnt[2]);
    }

    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // Try Alice taking remainder 1 first
        bool start1 = check(cnt);

        // Try Alice taking remainder 2 first
        swap(cnt[1], cnt[2]);
        bool start2 = check(cnt);

        return start1 || start2;
    }
};