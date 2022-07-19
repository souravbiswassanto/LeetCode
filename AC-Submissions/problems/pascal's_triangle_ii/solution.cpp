class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        for(int i = 2; i <= rowIndex + 1; i++){
            vector<int> newv;
            for(int j = 0; j < i; j++){
                int a , b;
                if(j - 1 < 0) a = 0;
                else a = row[j - 1];
                if(j == i - 1)b = 0;
                else b = row[j];
                newv.push_back(a + b);
            }
            row = newv;
        }
        return row;
    }
};