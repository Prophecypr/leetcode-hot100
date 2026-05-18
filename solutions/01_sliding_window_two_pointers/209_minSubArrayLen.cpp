/*
 * 209. Minimum Size Subarray Sum
 * 不定长滑动窗口 · 求最短/最小
 *
 * 思路：
 *   求满足 sum >= target 的最短连续子数组。
 *   与求最长模式的关键区别：
 *     最长模式：扩右 → 缩到合法 → 更新答案
 *     最短模式：扩右 → 条件满足时更新答案 + 缩小左边界
 *   模板顺序：while (条件满足) { 更新答案; 收缩左边界; }
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, sum = 0, left = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {              // 窗口满足条件
                ans = min(ans, right - left + 1); // 先更新最短
                sum -= nums[left];                // 再收缩左边界
                left++;
            }
        }

        return ans < INT_MAX ? ans : 0;          // 无合法窗口返回 0
    }
};
