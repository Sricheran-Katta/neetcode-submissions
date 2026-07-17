class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<int> maxHeap;
        vector<int> v(26, 0);
        for(char k : tasks){
            v[k - 'A']++;
        }
        for(int i = 0; i < 26; i++){
            int freq = v[i]; 
            if(freq > 0){
                maxHeap.push(freq);
            }  
        }
        queue<pair<int, int>> q;
        while(!maxHeap.empty() || !q.empty()){
            // fastforward if required
            if(maxHeap.empty() && !q.empty()){
                time = q.front().second;
            }
            if(!maxHeap.empty()){
                int freq = maxHeap.top();
                maxHeap.pop();
                freq--;
                if(freq > 0){
                    q.push({freq, time + n});
                }
            }
            if (!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
            time++;
        }
        return time;
    }
};
