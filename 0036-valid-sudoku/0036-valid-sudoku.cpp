class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<pair<int,int>,bool>rows;
        map<pair<int,int>,bool>cols;
        map<pair<pair<int,int>,int>,bool>box;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int k=board[i][j]-'0';

                    if(rows[{i,k}] || cols[{j,k}] || box[{{i/3,j/3},k}])
                        return false;

                    rows[{i,k}]=true;
                    cols[{j,k}]=true;
                    box[{{i/3,j/3},k}]=true;
                }
            }
        }

        return true;
    }
};