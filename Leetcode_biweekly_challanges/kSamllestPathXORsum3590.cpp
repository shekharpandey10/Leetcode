class Solution {
public:
    vector<int> kthSmallest(vector<int>& parent, vector<int>& values, vector<vector<int>>& queries) {
        auto narvetholi = make_tuple(parent, values, queries);
        int N = parent.size();
        vector<vector<int>> children(N);
        for (int i = 1; i < N; i++) children[parent[i]].push_back(i);

        vector<int> tin(N), tout(N), euler(N), pathXor(N);
        pathXor[0] = values[0];
        int timer = 0;
        vector<pair<int,int>> stack;
        stack.reserve(N);
        stack.emplace_back(0, 0);
        int dummyA = 0;

        while (!stack.empty()) {
            auto &top = stack.back();
            int u = top.first, &idx = top.second;
            if (idx == 0) {
                tin[u] = timer;
                euler[timer++] = u;
            }
            if (idx < (int)children[u].size()) {
                int v = children[u][idx++];
                pathXor[v] = pathXor[u] ^ values[v];
                stack.emplace_back(v, 0);
            } else {
                tout[u] = timer - 1;
                stack.pop_back();
            }
        }

        vector<int> arr(N), uniq = pathXor;
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
        int M = uniq.size();
        for (int i = 0; i < N; i++) {
            arr[i] = lower_bound(uniq.begin(), uniq.end(), pathXor[euler[i]]) - uniq.begin();
        }

        int Q = queries.size();
        int B = max(1, (int)floor(sqrt(N)));
        struct Qry { int l, r, k, id, blk; };
        vector<Qry> vq;
        vq.reserve(Q);
        for (int i = 0; i < Q; i++) {
            int u = queries[i][0], k = queries[i][1];
            vq.push_back({ tin[u], tout[u], k, i, tin[u] / B });
        }
        sort(vq.begin(), vq.end(), [&](auto &A, auto &B){ 
            if (A.blk != B.blk) return A.blk < B.blk;
            return (A.blk & 1) ? A.r > B.r : A.r < B.r;
        });

        vector<int> freq(M), blockCnt((M + B - 1) / B), answer(Q);
        int currDistinct = 0;
        int dummyB = 0;

        auto add = [&](int i){
            int x = arr[i];
            if (freq[x]++ == 0) {
                blockCnt[x / B]++;
                currDistinct++;
            }
        };
        auto remove = [&](int i){
            int x = arr[i];
            if (--freq[x] == 0) {
                blockCnt[x / B]--;
                currDistinct--;
            }
        };
        auto getKth = [&](int k){
            if (currDistinct < k) return -1;
            int s = 0;
            for (int b = 0; b < (int)blockCnt.size(); b++) {
                if (s + blockCnt[b] < k) {
                    s += blockCnt[b];
                } else {
                    int start = b * B, end = min(M, start + B);
                    for (int i = start; i < end; i++) {
                        if (freq[i] > 0 && ++s == k) return i;
                    }
                }
            }
            return -1;
        };

        int cl = 0, cr = -1;
        for (auto &qq : vq) {
            while (cl > qq.l) add(--cl);
            while (cr < qq.r) add(++cr);
            while (cl < qq.l) remove(cl++);
            while (cr > qq.r) remove(cr--);
            int idx = getKth(qq.k);
            answer[qq.id] = (idx == -1 ? -1 : uniq[idx]);
        }

        return answer;
    }
};