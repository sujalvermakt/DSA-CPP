/*
Problem:
Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target.
You may assume that each input has exactly one solution, and you may not use the same element twice.

Approach:
Use a map to store previously seen numbers and their indices.
For each element, calculate the required complement (target - current element).
If the complement already exists in the map, return the stored index and the current index.
Otherwise, store the current element and its index in the map and continue.

Time Complexity:
O(n log n)
(map operations take O(log n) time)

Space Complexity:
O(n)
(for storing elements and their indices in the map)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        vector<int> v;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int k = target - a;

            if (mpp.find(k) != mpp.end()) {
                v.push_back(mpp[k]);
                v.push_back(i);
                return v;
            }

            mpp[nums[i]] = i;
        }

        return v;
    }
};
