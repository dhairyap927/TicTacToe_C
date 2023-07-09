#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char x = 'F';

int winner_checker(char *board) {
    int i;
    int winner_found = 0;

    if ((board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
        (board[22] == 'X' && board[26] == 'X' && board[30] == 'X') ||
        (board[44] == 'X' && board[48] == 'X' && board[52] == 'X') ||
        (board[0] == 'X' && board[22] == 'X' && board[44] == 'X') ||
        (board[4] == 'X' && board[26] == 'X' && board[48] == 'X') ||
        (board[8] == 'X' && board[30] == 'X' && board[52] == 'X') ||
        (board[0] == 'X' && board[26] == 'X' && board[52] == 'X') ||
        (board[8] == 'X' && board[26] == 'X' && board[44] == 'X')) {

        for (i = 0; i < strlen(board); i++) {
            if (board[i] == '1' || board[i] == '2' || board[i] == '3' || board[i] == '4' || board[i] == '5' ||
                board[i] == '6' || board[i] == '7' || board[i] == '8' || board[i] == '9') {
                board[i] = '-';
            }
        }

        x = 'T';

        printf("X is the winner\n");
        printf("%s\n", board);
        winner_found = 1;
        exit(4);
    }

    if ((board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
        (board[22] == 'O' && board[26] == 'O' && board[30] == 'O') ||
        (board[44] == 'O' && board[48] == 'O' && board[52] == 'O') ||
        (board[0] == 'O' && board[22] == 'O' && board[44] == 'O') ||
        (board[4] == 'O' && board[26] == 'O' && board[48] == 'O') ||
        (board[8] == 'O' && board[30] == 'O' && board[52] == 'O') ||
        (board[0] == 'O' && board[26] == 'O' && board[52] == 'O') ||
        (board[8] == 'O' && board[26] == 'O' && board[44] == 'O')) {

        for (i = 0; i < strlen(board); i++) {
            if (board[i] == '1' || board[i] == '2' || board[i] == '3' || board[i] == '4' || board[i] == '5' ||
                board[i] == '6' || board[i] == '7' || board[i] == '8' || board[i] == '9') {
                board[i] = '-';
            }
        }
        x = 'T';

        printf("Player 'O' wins!\n");
        printf("%s\n", board);
        winner_found = 1;
        exit(5);
    }

    return winner_found;
}

bool isUnique(int *arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <first_player>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char first = argv[2][0];

    if (first != 'X' && first != 'O') {
        printf("Invalid first player. Please choose 'X' or 'O'.\n");
        exit(1);
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        exit(2);
        return 1;
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch != ' ' && ch != '\n') {
            count++;
        }
    }

    if (count != 9) {
        printf("The file should contain exactly 9 integers.\n");
        fclose(file);
        exit(3);
        return 1;
    }

    rewind(file);

    int *numbers = malloc(count * sizeof(int));
    if (numbers == NULL) {
        printf("Failed to allocate memory.\n");
        fclose(file);
        return 1;
    }

    int uniqueCount = 0;
    int i = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch != ' ' && ch != '\n') {
            numbers[i] = atoi(&ch);
            i++;
            uniqueCount++;
        }
    }

    fclose(file);

    if (uniqueCount != 9 || !isUnique(numbers, uniqueCount)) {
        printf("The file should contain exactly 9 unique integers.\n");
        free(numbers);
        return 1;
    }

    file = fopen(filename, "r");

    char *input = malloc(count * sizeof(char));
    if (input == NULL) {
        printf("Failed to allocate memory.\n");
        free(numbers);
        fclose(file);
        return 1;
    }

    i = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch != ' ' && ch != '\n') {
            input[i] = ch;
            i++;
        }
    }

    fclose(file);

    char second;
    if (first == 'X') {
        second = 'O';
    } else {
        second = 'X';
    }

    char board[] = "1 | 2 | 3 \n----------\n4 | 5 | 6 \n----------\n7 | 8 | 9 ";
    int len = count;

    int winner_found = 0;

    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 9; j = j + 4) {
                if (input[i] == board[j]) {
                    board[j] = first;
                    if (winner_checker(board)) {
                        winner_found = 1;
                        break;
                    }
                }
            }
            for (int k = 22; k < 31; k = k + 4) {
                if (input[i] == board[k]) {
                    board[k] = first;
                    if (winner_checker(board)) {
                        winner_found = 1;
                        break;
                    }
                }
            }
            for (int m = 44; m < 53; m = m + 4) {
                if (input[i] == board[m]) {
                    board[m] = first;
                    if (winner_checker(board)) {
                        winner_found = 1;
                        break;
                    }
                }
            }
        }
        else {
            for (int j = 0; j < 9; j = j + 4) {
                if (input[i] == board[j]) {
                    board[j] = second;
                    if (winner_checker(board)) {
                        winner_found = 1;
                        break;
                    }
                }
            }
            for (int k = 22; k < 31; k = k + 4) {
                if (input[i] == board[k]) {
                    board[k] = second;
                    if (winner_checker(board)) {
                        winner_found = 1;
                        break;
                    }
                }
            }
            for (int m = 44; m < 53; m = m + 4) {
                if (input[i] == board[m]) {
                    board[m] = second;
                    if (winner_checker(board)) {
                        winner_found = 1;
                        break;
                    }
                }
            }
        }
        if (winner_found) {
            break;
        }
    }

    if (!winner_found) {
        printf("THE GAME IS TIE\n");
        printf("%s\n", board);
        exit(6);
    }

    free(input);
    free(numbers);

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                       