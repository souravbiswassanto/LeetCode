class Solution {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> shortestSeq;
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()) return shortestSeq;
        it = find(wordList.begin(), wordList.end(), beginWord);
        if (it == wordList.end()) wordList.push_back(beginWord);
         
        unordered_map<string, bool> isPresentinSeq;
        int smallestStep = INT_MAX; vector<string> sequence;
        unordered_map<string, int> level;
        unordered_map<string, vector<string>> ms;
        
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = 0; j < wordList.size(); ++j) {
                int cntr = 0;
                 for (int k = 0; k < beginWord.size(); ++k) {
                     if (wordList[i][k] != wordList[j][k]) cntr++;
                 }
                 if (cntr == 1) {
                     ms[wordList[i]].push_back(wordList[j]);
                 }
            }
        }
        
        queue<string> q; level[endWord] = 0;
        isPresentinSeq[endWord] = true; q.push(endWord);
        while(!q.empty()) {
            string Front = q.front(); 
            q.pop();
            for (auto v : ms[Front]) {
                //cout << v << endl;
                if (isPresentinSeq[v]) continue;
                isPresentinSeq[v] = true;
                level[v] = level[Front] + 1;
                q.push(v);
            }
        }
        //cout << level[beginWord] << endl;
        
        //cout << level[beginWord] << endl;
        if (level[beginWord] == 0) return shortestSeq;
        smallestStep = level[beginWord]; 
        isPresentinSeq.clear(); isPresentinSeq[beginWord] = true;
        function<void(string, int)> dfs = [&] (string cur, int step){
             if (cur == endWord) {
                 //cout << step << endl;
                 if (step == smallestStep) shortestSeq.push_back(sequence);
                 return;
             }
             if(level[cur] == 0) return;
             if (smallestStep - step != level[cur]) return;
             for (auto v: ms[cur]) {
                 if (isPresentinSeq[v]) continue;
                 isPresentinSeq[v] = true;
                 sequence.push_back(v);
                 dfs(v, step + 1);
                 sequence.pop_back();
                 isPresentinSeq[v] = false;
             }
        };
        sequence.push_back(beginWord);
        dfs(beginWord, 0);
        return shortestSeq;
    }
};