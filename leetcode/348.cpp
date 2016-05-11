//348 https://leetcode.com/problems/design-tic-tac-toe/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> grid;
    int _n;
    TicTacToe(int n) {
        _n = n;
        grid = vector<vector<int>>(n, vector<int>(n, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        grid[row][col] = player;
        
        bool win = true;
        // check row
        for (int i = 0; i < _n; i++) {
            if (grid[i][col] != player) {
                win = false;
                break;
            }
        }
        if (win) return player;
        
        // check column
        win = true;
        for (int i = 0; i < _n; i++) {
            if (grid[row][i] != player) {
                win = false;
                break;
            }
        }
        if (win) return player;
        
        // check diagonal
        if (row == col || row + col == _n-1) {
            win = true;
            for (int i = 0; i < _n; i++) {
                if (grid[i][i] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return player;
            
            win = true;
            for (int i = 0; i < _n; i++) {
                if (grid[i][_n-1-i] != player) {
                    win = false;
                    break;
                }
            }
            if (!win) return 0;
            else return player;
        }
        else return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */