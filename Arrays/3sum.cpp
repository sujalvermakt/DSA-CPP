/*
Problem:
Given an integer array nums, return all the unique triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
The solution set must not contain duplicate triplets.

Approach:
Sort the array first. Iterate through the array and fix one element at a time.
For each fixed element, use the two-pointer technique to find two other elements
whose sum with the fixed element equals zero.
Skip duplicate values for the fixed element as well as for the left and right pointers
to avoid generating duplicate triplets.

Time Complexity:
O(n^2)
Sorting takes O(n log n), and the two-pointer traversal for each element takes O(n).

Space Complexity:
O(1)
Ignoring the space required for storing the output.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int l;
        int r;
        int sum = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            l = i + 1;
            r = n - 1;

            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }

                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
                else if (sum > 0) {
                    r--;
                }
                else if (sum < 0) {
                    l++;
                }
            }
        }

        return ans;
    }
};
