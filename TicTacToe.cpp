/**
  CSCI 3010 - Programming Project Workshop
  Homework 2, due Friday Feb 14 2019 11:59PM
  Andrew Gilfillan (Person 2)
  Julian Lambert (Person 1)
*/

#include <iostream>
#include <vector>
#include <tuple>

/**
  CreateBoard creates an empty board with variable row/col sizes.
  @param board_rows The number of rows the board will have.
  @param board_cols The number of cols the board will have.
  @param blank_char The char you want the board to be populated with.
  @return An empty vector (rows) of vectors (cols) of chars.
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

/**
  DisplayBoard prints out the TicTacToe board, from the top left cell to the bottom right cell
  @param board The board (a vector of vectors of chars)
*/
void DisplayBoard(std::vector<std::vector<char>> board) {
  // Iteratre through the rows
  for (unsigned int i = 0; i < board.size(); i++) {
  // Iterate through the board's columns
    for (unsigned int j = 0; j < board[i].size(); j++) {
      if (j > 0) {
        std::cout << "   |";
      }
      std::cout << board[i][j];
    }
    // At the end of every row, start a new line for the next row
    std::cout << "\n";
    if(i < 2) {
      std::cout << "______________\n";
    }
  }
}

/**
  PlaceMarker prints out the TicTacToe board, from the top left cell to the bottom right cell
  @param board The board (a 2-Dimensional array of char's)
  @param locationRow The row index value for the location to place the marker
  @param locationCol The column index value for the location to place the marker 
  @param marker The appropriate marker for the player to place (either x or o)
*/
void PlaceMarker(std::vector<std::vector<char>> &board, int locationRow, int locationCol, char marker) {
  board[locationRow][locationCol] = marker;
}

/**
  GetPlayerChoice prompts the user for a location to play, then returns that choice.
  @return a std::tuple<int, int> of their chosen coordinates.
*/
std::tuple<int, int> GetPlayerChoice() {

  // Prompt user for their move's row
  std::string row_choice;
  // If wrong input format is given, re-prompt the user
  while (row_choice != "1" && row_choice != "2" && row_choice != "3") {
    std::cout << "Enter row (1-3): ";
    std::cin >> row_choice;
  }

  // Prompt user for their move's col
  std::string col_choice;
  // If wrong input format is given, re-prompt the user
  while (col_choice != "1" && col_choice != "2" && col_choice != "3") {
    std::cout << "Enter col (1-3): ";
    std::cin >> col_choice;
  }

  // Return the result as a tuple converted to integers
  return std::tuple<int, int> {std::stoi(row_choice), std::stoi(col_choice)};
}

int main() {

  // CreateBoard() has default arguments specified for all params
  std::vector<std::vector<char>>  b = CreateBoard();

// loop to simulate the game, iterates 9 times as there cannot be more than 9 turns in a game of Tic-Tac-Toe
  for (int i = 0; i < 9; i++) {
    if (i % 2) {
      // O goes second, the board is displayed, and player O is prompted for a choice, that choice is used to place O's marker on the board
      std::cout << "\nO's turn\n";
      DisplayBoard(b);
      std::cout << "\n";
      std::tuple<int, int> choice = GetPlayerChoice();
      PlaceMarker(b, (std::get<0>(choice))-1, (std::get<1>(choice))-1, 'O');
    }
    else {
      // X goes first, the board is displayed, and player X is prompted for a choice, that choice is used to place X's marker on the board
      std::cout << "\nX's turn\n";
      DisplayBoard(b);
      std::cout << "\n";
      std::tuple<int, int> choice = GetPlayerChoice();
      PlaceMarker(b, (std::get<0>(choice))-1, (std::get<1>(choice))-1, 'X');
    }
  }

  // final board is displayed after 9 turns are taken
  std::cout << "\n";
  DisplayBoard(b);

}
