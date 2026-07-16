class KthLargest {
private:
    int k_limit;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        k_limit = k;
        for(int i = 0; i < nums.size(); i++){
            add(nums[i]);
        } 
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k_limit){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
