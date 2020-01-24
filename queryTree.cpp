int queryTree(vector<int>& A, int idx, int i, int j, int lo, int hi) {
    // Query for A[i...j]

    // Segment completely outside range
    if(i > hi || j < lo)
        return 0;

    // Segment completely in range
    if(i >= lo && j <= hi)
        return tree[idx];    
    
    int mid = lo + (hi - lo) / 2;

    // In left only
    if(j <= mid)
        return queryTree(A, 2 * idx + 1, i, j, lo, mid);


    // In right only
    else if(i > mid)
        return queryTree(A, 2 * idx + 2, i, j, mid + 1, hi);    

    // Partially in left and right
    return union(queryTree(A, 2 * idx + 1, i, j, lo, mid), queryTree(A, 2 * idx + 2, i, j, mid + 1, hi));
}
