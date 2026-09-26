// 488. Zuma Game

// You are playing a variation of the game Zuma.

// In this variation of Zuma, there is a single row of colored balls on a board, where each ball can be colored red 'R', yellow 'Y', blue 'B', green 'G', or white 'W'. You also have several colored balls in your hand.

// Your goal is to clear all of the balls from the board. On each turn:

// Pick any ball from your hand and insert it in between two balls in the row or on either end of the row.
// If there is a group of three or more consecutive balls of the same color, remove the group of balls from the board.
// If this removal causes more groups of three or more of the same color to form, then continue removing each group until there are none left.
// If there are no more balls on the board, then you win the game.
// Repeat this process until you either win or do not have any more balls in your hand.
// Given a string board, representing the row of balls on the board, and a string hand, representing the balls in your hand, return the minimum number of balls you have to insert to clear all the balls from the board. If you cannot clear all the balls from the board using the balls in your hand, return -1.

// Example 1:

// Input: board = "WRRBBW", hand = "RB"
// Output: -1
// Explanation: It is impossible to clear all the balls. The best you can do is:
// - Insert 'R' so the board becomes WRRRBBW. WRRRBBW -> WBBW.
// - Insert 'B' so the board becomes WBBBW. WBBBW -> WW.
// There are still balls remaining on the board, and you are out of balls to insert.
// Example 2:

// Input: board = "WWRRBBWW", hand = "WRBRW"
// Output: 2
// Explanation: To make the board empty:
// - Insert 'R' so the board becomes WWRRRBBWW. WWRRRBBWW -> WWBBWW.
// - Insert 'B' so the board becomes WWBBBWW. WWBBBWW -> WWWW -> empty.
// 2 balls from your hand were needed to clear the board.
// Example 3:

// Input: board = "G", hand = "GGGGG"
// Output: 2
// Explanation: To make the board empty:
// - Insert 'G' so the board becomes GG.
// - Insert 'G' so the board becomes GGG. GGG -> empty.
// 2 balls from your hand were needed to clear the board.

// Constraints:

// 1 <= board.length <= 16
// 1 <= hand.length <= 5
// board and hand consist of the characters 'R', 'Y', 'B', 'G', and 'W'.
// The initial row of balls on the board will not have any groups of three or more consecutive balls of the same color.

class Solution
{
private:
    int mask = 0;
    vector<unordered_map<string, int>> dp;

    string updatedBoard(string board)
    {
        int i = 0;

        while (i < board.length())
        {
            int j = i;

            while (j < board.length() && board[j] == board[i])
            {
                j++;
            }

            if (j - i >= 3)
            {
                return updatedBoard(board.substr(0, i) + board.substr(j));
            }

            i = j;
        }

        return board;
    }
    int solve(string board, const string &hand)
    {
        int m = board.length();
        int n = hand.length();

        if (m == 0)
            return 0;

        if (dp[mask].count(board))
            return dp[mask][board];

        int ans = 1e9;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                bool worthTrying = false;
                if (board[i] == hand[j])
                    worthTrying = true;
                else if (i > 0 && board[i] == board[i - 1] &&
                         board[i] != hand[j])
                    worthTrying = true;
                if (!worthTrying)
                    continue;

                bool isUsedCurrHandIdx = mask & (1 << j);

                // checking if we had used this hand index previously or not..
                if (isUsedCurrHandIdx)
                    continue;

                int oldMask = mask;     // Storing used hand Index..
                mask = mask | (1 << j); // Updating mask so, we will not use
                                        // same hand index again..

                // Constructiong new Board..
                string newBoard =
                    board.substr(0, i) + hand[j] + board.substr(i);

                // cheking if we can do operation on our new Board or not. So,
                // we can upadte it again..
                string updateNewBoard = updatedBoard(newBoard);

                int next = solve(updateNewBoard, hand);
                ans = min(ans, 1 + next);

                mask = oldMask; // Backtracking, so we can use this hand index
                                // in future..
            }
        }

        return dp[mask][board] = ans;
    }

public:
    int findMinStep(string board, string hand)
    {
        dp.resize(1 << hand.size());

        int ans = solve(board, hand);
        return ans >= 1e9 ? -1 : ans;
    }
};
// TC-->O(5^n * n^2) where n is the length of the hand.
