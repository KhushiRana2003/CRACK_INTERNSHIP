class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps =0;
        nth_element(nums.begin(), nums.begin() + (n/2) ,nums.end()); // fixing median value.
        int median = nums[n/2];
        for(int i =0; i< n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};


There is a function with syntax nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
The function of this is that it rearranges the array in such a way such that the element at the nth position is the one which should be at that position if we sort the list from the first to last iterator. It uses the quick select method for this. For more details google it.

In this problem we don't need full array sorted we just need the median which is the n/2 th element in the sorted array. So this can be achived by nth_element(nums.begin(), nums.begin()+(n/2), nums.end()). After that continue as in first approach.

The advantage of this approach is that the time complexity becomes O(n) as nth_element is O(n) fuction unlike sort.

Time Complexity : O(n) for finding median + O(n) for loop = O(n), Space complexity : O(1)
