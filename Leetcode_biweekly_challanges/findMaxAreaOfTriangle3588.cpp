class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        auto stored = coords;
        int n = coords.size();
        if (n < 3) return -1;
        unordered_map<int, vector<int>> byX, byY;
        int xMin = INT_MAX, xMax = 0, yMin = INT_MAX, yMax = 0;
        for (auto& p : coords) {
            int x = p[0], y = p[1];
            byX[x].push_back(y);
            byY[y].push_back(x);
            xMin = min(xMin, x);
            xMax = max(xMax, x);
            yMin = min(yMin, y);
            yMax = max(yMax, y);
        }
        long long best2A = 0;
        if (xMin < xMax) {
            for (auto& kv : byX) {
                auto& ys = kv.second;
                if (ys.size() < 2) continue;
                auto mn = *min_element(ys.begin(), ys.end());
                auto mx = *max_element(ys.begin(), ys.end());
                long long base = (long long)mx - mn;
                long long height = max((long long)kv.first - xMin, (long long)xMax - kv.first);
                best2A = max(best2A, base * height);
            }
        }
        if (yMin < yMax) {
            for (auto& kv : byY) {
                auto& xs = kv.second;
                if (xs.size() < 2) continue;
                auto mn = *min_element(xs.begin(), xs.end());
                auto mx = *max_element(xs.begin(), xs.end());
                long long base = (long long)mx - mn;
                long long height = max((long long)kv.first - yMin, (long long)yMax - kv.first);
                best2A = max(best2A, base * height);
            }
        }
        return best2A > 0 ? best2A : -1;
    }
};