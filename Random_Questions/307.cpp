// 307. Range Sum Query - Mutable

// Given an integer array nums, handle multiple queries of the following types:

// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

// Example 1:

// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]

// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// 0 <= index < nums.length
// -100 <= val <= 100
// 0 <= left <= right < nums.length
// At most 3 * 104 calls will be made to update and sumRange.

class NumArray {
public:
    vector<int> segmentTree;
    vector<int> arr;
    void buildTree(int i, int l, int r, vector<int>& segmentTree,
                   vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        } else {
            int mid = l + (r - l) / 2;
            buildTree(2 * i + 1, l, mid, segmentTree, nums);
            buildTree(2 * i + 2, mid + 1, r, segmentTree, nums);

            segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
        }
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr = nums;
        segmentTree.resize(4 * n);
        buildTree(0, 0, n - 1, segmentTree, nums);
    }

    void updateTree(int idx, int val, int i, int l, int r,
                    vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = val;
        } else {
            int mid = l + (r - l) / 2;

            if (idx <= mid) {
                // left side
                updateTree(idx, val, 2 * i + 1, l, mid, segmentTree);
            } else {
                updateTree(idx, val, 2 * i + 2, mid + 1, r, segmentTree);
            }
            segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
        }
    }

    void update(int index, int val) {
        updateTree(index, val, 0, 0, arr.size() - 1, segmentTree);
    }

    int query(int st, int end, int i, int l, int r, vector<int>& segmentTree) {
        if (l > end || r < st) {
            return 0;
        }

        if (l >= st && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;
        return query(st, end, 2 * i + 1, l, mid, segmentTree) +
               query(st, end, 2 * i + 2, mid + 1, r, segmentTree);
    }

    int sumRange(int left, int right) {
        return query(left, right, 0, 0, arr.size() - 1, segmentTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
//TC-->(n) for building the segment tree and O(log n) for each update and sumRange query, where n is the number of elements in the input array.
//SC-->O(n) for storing the segment tree and O(n) for storing the input array, resulting in O(n) overall space complexity.