void buildTree(vector<int>& A, int idx, int lo, int hi) {
    if(lo == hi) {
        tree[idx] = A[lo];
        return;
    }
    int mid  = lo + (hi - lo) / 2;
    buildTree(A, 2 * idx + 1, lo, mid);
    buildTree(A, 2 * idx + 2, mid + 1, hi);
    // Some O(1) logic for doing union for range query
    // Like take min / max / add
    tree[idx] = uni(tree[2 * idx + 1], tree[2 * idx + 1]);
}
