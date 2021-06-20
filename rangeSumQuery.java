class NumArray {
    class SegmentTreeNode{
        private SegmentTreeNode left;
        private SegmentTreeNode right;
        private int start;
        private int end;
        private int sum;

        public SegmentTreeNode(int start, int end){
            this.start = start;
            this.end = end;
            this.left = null;
            this.right = null;
            this.sum = 0;
        }
    }  

    private SegmentTreeNode root;

    public NumArray(int[] nums) {
        root = buildSegmentTree(nums, 0, nums.length - 1);
    }
    
    public void update(int index, int val) {
        updateTree(root, index, val);
    }
    
    public int sumRange(int left, int right) {
        return sumInRange(root, left, right);
    }
    
    public SegmentTreeNode buildSegmentTree(int[] nums, int start, int end){
        
        if(start > end)
            return null;
        
        SegmentTreeNode root = new SegmentTreeNode(start, end);
        
        if(root.start == root.end){
            root.sum = nums[start];
        }else{
            int mid = root.start + (root.end - root.start)/2;
            root.left = buildSegmentTree(nums, start, mid);
            root.right = buildSegmentTree(nums, mid + 1, end);
            root.sum = root.left.sum + root.right.sum;
        }
        
        return root;
    }
    
    public void updateTree(SegmentTreeNode root, int i, int val){
        
        if(root.start == i && root.end == i){
            root.sum = val;
            return;
        }
        
        int mid = root.start + (root.end - root.start)/2;
        
        if(i <= mid){
            updateTree(root.left, i, val);
        }else{
            updateTree(root.right, i, val);
        }
        
        root.sum = root.left.sum + root.right.sum;
        
    }
    
    public int sumInRange(SegmentTreeNode root, int left, int right){
        
        if(root.start == left && root.end == right){
            return root.sum;
        }
        
        int mid = root.start + (root.end - root.start)/2;
        
        if(left > mid){
            return sumInRange(root.right, left, right);
        }else if(right <= mid){
            return sumInRange(root.left, left, right);
        }else{
            return sumInRange(root.left, left, mid) + sumInRange(root.right, mid + 1, right);
        }
        
    }
}
