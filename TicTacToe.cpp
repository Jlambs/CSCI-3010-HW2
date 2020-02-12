/**
  CSCI 3010 - Programming Project Workshop
  Homework 2, due Friday Feb 14 2019 11:59PM
  Andrew Gilfillan (Person 2)
  Julian Lambert (Person 1)
*/

#include <vector>

/**
  CreateBoard creates an empty board with variable row/col sizes.

  @param board_rows The number of rows the board will have.
  @param board_cols The number of cols the board will have.
  @param blank_char The char you want the board to be populated with.
  @output An empty vector (rows) of vectors (cols) of chars.
*/
std::vector<std::vector<char>> CreateBoard(int board_rows=3, int board_cols=3, char blank_char=' ') {
  // Initialize board
  std::vector<std::vector<char>> board;
  // Iteratively add elements to board
  for (int i = 0; i < board_rows; i++) {
    // Initialize i-th row
    board.push_back(std::vector<char>());
    for (int j = 0; j < board_cols; j++) {
        // Add blank_char as j-th element in i-th row
        // Elements can be accessed using board[i][j]
        board[i].push_back(blank_char);
    }
  }
  // Return populated board
  return board;
}


int main() {

  // CreateBoard() has default arguments specified for all params
  std::vector<std::vector<char>> b = CreateBoard();

}
