class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(int i = 0; i < wordList.size(); i++){
            st.insert(wordList[i]);
        }
        if(st.find(endWord) == st.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while(!q.empty()){
            int levelsize = q.size();
            for(int i = 0; i < levelsize; i++){
                string curr = q.front();
                q.pop();
                for(int j = 0; j < curr.length(); j++){
                    char origin = curr[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        if (c == origin) continue;
                        curr[j] = c;
                        if (curr == endWord) return steps + 1;
                        if (st.find(curr) != st.end()){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[j] = origin;
                }
            }
            steps++;
        }
        return 0;
    }
};
