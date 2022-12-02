class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> wordVec1(26, 0), wordVec2(26, 0);
        bool notClose = false;
        for (int i = 0; i < word1.size(); i++) {
            wordVec1[word1[i]- 97]++;
        }
        for (int i = 0; i < word1.size(); i++) {
            if(wordVec1[word2[i] - 97] == 0) {
                notClose = true;
            }
            wordVec2[word2[i] - 97]++;
        }
        
        if (notClose or (word1.size() != word2.size())) return false;
        sort(wordVec2.begin(), wordVec2.end());
        sort(wordVec1.begin(), wordVec1.end());
        return wordVec1 == wordVec2;
    }
};