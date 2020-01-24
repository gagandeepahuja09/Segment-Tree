int queryRange(int i, int j, int idx, int lo, int hi) {
    if(lo > j || hi < j)
        return 0;
    if(lazy[idx]) {
        tree[idx] += (hi - lo + 1) * lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
        lazy[2 * idx + 2] += lazy[idx];
        lazy[idx] = 0;
    }
    // Completely within range
    if(lo >= i && hi <= j)
        return tree[idx];
    
    // Partially in range
    // Only left
    if(i > mid)
        return queryRange(i, j, 2 * idx + 2, mid + 1, hi);
    else if(j <= mid)
        return queryRange(i, j, 2 * idx + 1, lo, mid);
    return queryRange(i, mid, 2 * idx + 1, lo, mid) + queryRange(mid + 1, j, 2 * idx + 2, mid + 1, hi);     
}
