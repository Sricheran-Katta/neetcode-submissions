class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        for(int i = 0; i < points.size(); i++){
            vector<int> point = points[i];
            int dist = point[0] * point[0] + point[1] * point[1];
            pair<int, vector<int>> v = {dist, point};
            maxHeap.push(v);
            if (maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while(! maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
