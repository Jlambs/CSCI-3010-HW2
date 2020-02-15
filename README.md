# CSCI-3010-HW2
 TicTacToe Game

Team Members:
    Julian Lambert (Person 1)
    Andrew Gilfillan (Person 2)

This program simulates a game of Tic-Tac-Toe, where the users input a row and column value to place their marker, either X or O, on the board, the game ends when one user/player connects 3 of their marker, or after 9 turns when the board is full and no player has connected 3 of their marker.

The program can be run by compiling TicTacToe.cpp by typing the following into terminal:
'g++ -Wall TicTacToe.cpp -o TicTacToe'
Then running the executable with:
'./TicTacToe 2>&1 | tee output.txt'
The game will be dispalyed on the screen as well as printed to an output file 'output.txt'