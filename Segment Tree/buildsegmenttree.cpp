void buildSegmentTree(int node, int start, int end) {
    if (start == end) {
        // Leaf node will have a single element
        segmentTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        // Recur for the left and right children
        buildSegmentTree(2 * node + 1, start, mid);
        buildSegmentTree(2 * node + 2, mid + 1, end);
        // Internal node will have the sum of both of its children
        segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];
    }
}
//TC-->O(n) where n is the number of elements in the input array. This is because we need to visit each node of the segment tree once to build it.
//SC-->O(n) where n is the number of elements in the input array. This