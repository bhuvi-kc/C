#include <stdio.h>

char board[3][3];

// Initialize the board
void initBoard() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = ' ';
}

// Print the board
void printBoard() {
    printf("\n");
    for(int i=0;i<3;i++){
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i<2) printf("---|---|---\n");
    }
    printf("\n");
}

// Check for winner
char checkWin() {
    for(int i=0;i<3;i++){
        // check rows
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ')
            return board[i][0];
        // check columns
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
            return board[0][i];
    }
    // check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
        return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
        return board[0][2];
    return ' '; // no winner
}

int main() {
    initBoard();
    int moves = 0;
    char winner = ' ';
    int row, col;
    char player = 'X';

    while(moves < 9 && winner==' ') {
        printBoard();
        printf("Player %c, enter row and column (1-3): ", player);
        scanf("%d %d", &row, &col);

        // subtract 1 to convert 1-3 input to 0-2 array index
        row -= 1;
        col -= 1;

        if(row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ') {
            board[row][col] = player;
            moves++;
            winner = checkWin();
            if(winner==' ')
                player = (player=='X') ? 'O' : 'X';
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    printBoard();
    if(winner!=' ')
        printf("Player %c wins!\n", winner);
    else
        printf("It's a draw!\n");

    return 0;
}