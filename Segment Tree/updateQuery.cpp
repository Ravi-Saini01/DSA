void updateQuery(int node, int start, int end, int idx, int val) {
    if (start == end) {
        // Leaf node will have a single element
        segmentTree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            // If idx is in the left child, recurse on the left child
            updateQuery(2 * node + 1, start, mid, idx, val);
        } else {
            // If idx is in the right child, recurse on the right child
            updateQuery(2 * node + 2, mid + 1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];
    }
}
//TC-->O(log n) where n is the number of elements in the input array. This is because we only need to visit the nodes along the path from the root to the leaf node corresponding to idx.