#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int n = nums.size(); n > 1; n--)
            for (int i = 0; i < n - 1; i++)
                nums[i] = (nums[i] + nums[i+1]) % 10;
        return nums[0];
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.triangularSum(nums) << endl; // Output: 8
    return 0;
}