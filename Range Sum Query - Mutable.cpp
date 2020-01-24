class NumArray {
public:
    // All functions work in a bottom up manner
    vector<int> tree, A;
    // O(N)
    void buildTree(int idx, int lo, int hi) {
        if(lo == hi) {
            tree[idx] = A[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(2 * idx + 1, lo, mid);
        buildTree(2 * idx + 2, mid + 1, hi);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2]; 
    }
    
    // O(log N)
    int queryTree(int i, int j, int idx, int lo, int hi) {
        // No intersection
        if(i > hi || j < lo)
            return 0;
        // Completely inside
        if(i == lo && j == hi) {
            return tree[idx];
        }
        int mid = lo + (hi - lo) / 2;
        if(i > mid)
            return queryTree(i, j, 2 * idx + 2, mid + 1, hi);
        else if(j <= mid)
            return queryTree(i, j, 2 * idx + 1, lo, mid);
        return queryTree(i, mid, 2 * idx + 1, lo, mid) + queryTree(mid + 1, j, 2 * idx + 2, mid + 1, hi);
    }
    
    // O(logN)
    void updateElement(int i, int val, int idx, int lo, int hi) {
        if(lo == hi) {
            tree[idx] = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if(i <= mid)
            updateElement(i, val, 2 * idx + 1, lo, mid);
        else if(i > mid)
            updateElement(i, val, 2 * idx + 2, mid + 1, hi);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4 * n);
        A = nums;
        if(n)
            buildTree(0, 0, n - 1);
    }
    
    void update(int i, int val) {
        int n = A.size();
        updateElement(i, val, 0, 0, n - 1);
    }
    
    int sumRange(int i, int j) {
        int n = A.size();
        return queryTree(i, j, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
