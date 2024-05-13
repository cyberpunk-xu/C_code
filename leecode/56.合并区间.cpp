/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (49.92%)
 * Likes:    2323
 * Dislikes: 0
 * Total Accepted:    860.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> pii;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pii> vec;
        for(auto interval: intervals){
            vec.push_back(pii(interval[0],interval[1]));
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> ans = {};
        for(int i=0;i < vec.size();){
            int start = vec[i].first;
            int end = vec[i].second;
            i++;
            while(i < vec.size() && end >= vec[i].first) {
                end = max(end, vec[i].second);
                i++;
            }
            ans.push_back(vector<int>{start,end});
        }
        return ans;
    }
};
// @lc code=end

