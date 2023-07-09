# TicTacToe_C
This project is a command-line implementation of Tic-Tac-Toe in C. It reads moves from a file, validates the game board, checks for a winner or tie, and displays the final state. Enjoy playing or simulating the classic game in a simple and interactive manner.

Certainly! Here's an example of a README file specifically for the provided Tic Tac Toe code:

## Features

- Supports two-player mode ('X' and 'O').
- Reads moves from a file.
- Validates the file format and contents.
- Checks for a winner or a tie.
- Outputs the final state of the game board.

## How to Run

To run the Tic Tac Toe game, follow these steps:

### Compilation

1. Clone the repository or download the source code files to your local machine.

2. Open a terminal or command prompt and navigate to the project directory.

3. Compile the source code using the following command:

   ```shell
   gcc -o tic_tac_toe tic_tac_toe.c
   ```

### Execution

4. Run the compiled executable:

   ```shell
   ./tic_tac_toe <file_name> <first_player>
   ```

   Replace `<file_name>` with the name of the file containing 9 unique integers representing the initial game state. Replace `<first_player>` with either 'X' or 'O' to specify the first player.

5. The game will display the initial game board and prompt the players to enter their moves. Players should input the number corresponding to the cell they want to mark.

6. Players take turns making moves by entering the cell number they wish to mark. The game will validate the moves and display the updated game board after each move.

7. The game will continue until one player wins or the game ends in a tie. The final game board and the result will be displayed.
   
## Input File Format

The file containing the moves should adhere to the following format:

- The file should contain exactly 9 unique integers separated by spaces.
- Each integer represents a move on the game board, corresponding to the position of the numbers 1-9 on a 3x3 grid.

Example file contents:

```
5 1 9 2 7 8 4 6 3
```

This represents the moves made in the order shown below:

```
X is the winner!

 O | O | 3
-----------
 4 | X | 6
-----------
 X | X | X
```

## Gameplay

The program will simulate the game based on the moves provided in the file. It will update the game board after each move and check for a winner or a tie.

- If a player wins, the program will display the final game board and declare the winner.
- If the game ends in a tie, the program will display the final game board and declare a tie.
