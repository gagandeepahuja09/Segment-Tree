void updateRange(int idx, int val, int i, int j, int lo, int hi) {
    if(lazy[idx]) {
        tree[idx] += (hi - lo + 1) * lazy[idx];
        if(lo != hi) {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    // Completely out of range
    if(lo > hi || lo > j || hi < i)
        return;
    // Completely within range, update and do not recurse for 
    // descendants, just mark them as lazy    
    if(lo >= i && hi <= j) {
        tree[idx] += (hi - lo + 1) * val;
        if(lo != hi) {
            tree[2 * idx + 1] += val;
            tree[2 * idx + 2] += val;
        }
        return;
    }
    // Partially in range, so merge updates
    int mid = lo + (hi - lo) / 2;
    updateRange(2 * idx + 1, val, i, j, lo, mid);
    updateRange(2 * idx + 2, val, i, j, mid + 1, hi);
    tree[idx] = tree[2 * idx + 1]  + tree[2 * idx + 2];   
}
