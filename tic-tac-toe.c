#include <stdio.h>

char board[3][3];

//board:
void iniboard ()
{
    for (int i = 0; i < 3; i++)
    {
        for  (int j = 0; j < 3; j++)
        {
           board[i][j] = ' ';
        }
    }
} 

//print the board:
void printboard ()
{
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);

        if (i < 2)    
        {
        printf("---|---|---\n");        
        }    
    }
}

//check for winner:
char wincheck ()
{
    for (int i = 0; i < 3; i++)
    {
        //rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }

        //columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[0][i];
        }

        //diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    }
    return ' ';   //no winner
}

int main()
{
    iniboard();
    printboard();

    int rows, cols;
    char player = 'X';
    char winner = wincheck();
 
    for (int move = 0; move < 9; move++)
    {
        printf("enter row: ");
        scanf("%d", &rows);
        printf("enter column: ");
        scanf("%d", &cols);

        rows -= 1;
        cols -= 1;

        if (rows >= 0 && rows < 3 && cols >= 0 && cols < 3 && board[rows][cols] == ' ')
        {
            board[rows][cols] = player;
            printboard();
            winner = wincheck();
            player = (player == 'X') ? 'O' : 'X';
        }

        else 
        {
            printf("invalid input.\n");
            move--;
        }
    
        if (winner != ' ')
        {
            printf("player %c wins.\n", winner);
            break;
        }
    }

    if (winner == ' ')
    printboard();
    printf("it was a draw match.\n");
    return 0;
}
