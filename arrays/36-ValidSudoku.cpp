class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // lets use unordered set so search time is O(1) and insert is O(n)
        unordered_set<char> rows[9];
        unordered_set<char> columns[9];
        unordered_set<char> boxes[9];
        for (int i = 0; i<9; i++) {
            for (int j = 0; i<9; j++) {
                char value = board[i][j];
                // "." means empty here so we can continue our current check (don't return false early)
                if (value == '.') {
                    continue;
                }
                // check rows first, if we've seen the value in same row alr, return false!
                if (rows[i].find(value) != rows[i].end()) {
                    return false;
                }
                // insert in row now
                rows[i].insert(value);
                // check cols now, if we've seen it in same cols, return false..
                if (columns[j].find(value) != columns[j].end()) {
                    return false;
                }
                // insert in cols now
                columns[j].insert(value);
                // finally, check boxes now. 
                int index = (i/3) * 3 + j / 3;
                if(boxes[index].find(value) != boxes[index].end()) {
                    return false;
                }
                // now insert into boxes..
                boxes[index].insert(value);
            }
        }
        return true;
    }
};