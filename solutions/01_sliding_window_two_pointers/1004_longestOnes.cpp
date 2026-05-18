/*
 * 1004. Max Consecutive Ones III
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   窗口内最多允许包含 k 个 0。
 *   当 cnt0 > k 时收缩左边界。
 *
 * §2.1 收关题：1493 的参数化版本（1493 的 k=1）。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, left = 0;
        int cnt[2] = {};

        for (int right = 0; right < nums.size(); right++) {
            cnt[nums[right]]++;

            while (cnt[0] > k) {          // 最多 k 个 0
                cnt[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
