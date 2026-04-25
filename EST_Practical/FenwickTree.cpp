#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n = 5, q = 5;

    FenwickTree ft(n);

    // Hardcoded queries
    vector<vector<int>> queries = {
        {1, 1, 5},   // update index 1 by +5
        {1, 2, 3},   // update index 2 by +3
        {2, 1, 2},   // query sum from 1 to 2
        {1, 5, 10},  // update index 5 by +10
        {2, 1, 5}    // query sum from 1 to 5
    };

    for (auto &q : queries) {
        if (q[0] == 1) {
            int i = q[1];
            int v = q[2];
            ft.update(i, v);
        } 
        else if (q[0] == 2) {
            int l = q[1];
            int r = q[2];
            cout << ft.rangeQuery(l, r) << endl;
        }
    }

    return 0;
}