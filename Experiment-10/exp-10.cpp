#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int size;

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node] += 1;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node + 1, start, mid, idx);
        else
            update(2 * node + 2, mid + 1, end, idx);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;

        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;

        return query(2 * node + 1, start, mid, l, r) +
               query(2 * node + 2, mid + 1, end, l, r);
    }
};

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Coordinate Compression
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    unordered_map<int, int> rank;
    for (int i = 0; i < sorted.size(); i++) {
        rank[sorted[i]] = i;
    }

    // Step 2: Segment Tree
    SegmentTree st(sorted.size());

    vector<int> result(n);

    // Step 3: Traverse from right
    for (int i = n - 1; i >= 0; i--) {
        int r = rank[nums[i]];

        // Query: count of smaller elements
        if (r > 0)
            result[i] = st.query(0, 0, sorted.size() - 1, 0, r - 1);
        else
            result[i] = 0;

        // Update current element
        st.update(0, 0, sorted.size() - 1, r);
    }

    return result;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};

    vector<int> res = countSmaller(nums);

    for (int x : res)
        cout << x << " ";

    return 0;
}