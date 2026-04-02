#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int cnt = 1;
        for (int i=0; i<points.size(); i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j=0; j<points.size(); j++) {
                if (i == j)
                    continue;
                int len = 2;
                int x2 = points[j][0], y2 = points[j][1];
                for (int k=0; k<points.size(); k++) {
                    if (k == i || k == j)
                        continue;
                    int x3 = points[k][0], y3 = points[k][1];
                    if ((y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2))
                        len++;
                }
                cnt = max(cnt, len);
            }
        }
        return cnt;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}};
    cout << sol.maxPoints(points) << endl; // Output: 3
    return 0;
}