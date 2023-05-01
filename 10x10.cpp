#include<stdio.h>
#include <stdlib.h>

char board[10][10] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};
char turn='X';
void printBoard(){
    printf("\n");
    printf("____________________________________________________________\n");
    for(int i=0;i<10;i++){
        printf("|  ");
        for(int j=0;j<10;j++){
            printf("%c  |  ",board[i][j]);
        }
        printf("\n");
    printf("____________________________________________________________\n");
    }
}
void playerMove(){
    int x,y;
    printf("Enter ur move: ");
    scanf("%d%d",&x,&y);
    while(board[x][y] != ' '){
        printf("Cell already occupied or Size overwhelmed. Try again.");
        printf("Enter ur move: ");
        scanf("%d%d",&x,&y);
    }
    
    board[x][y]=turn;
         
}
int checkWin(){
    for(int i=0;i<10;i++){
        for(int j=0;j<6;j++){
            if(board[i][j]==turn && board[i][j+1]==turn && board[i][j+2]==turn && board[i][j+3]==turn && board[i][j+4]==turn ){
                return 1;
            }
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<10;j++){
            if(board[i][j]==turn && board[i+1][j]==turn && board[i+2][j]==turn && board[i+3][j]==turn && board[i+4][j]==turn ){
                return 1;
           }
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(board[i][j]==turn && board[i+1][j+1]==turn && board[i+2][j+2]==turn && board[i+3][j+3]==turn && board[i+4][j+4]==turn ){
                return 1;
            }
        }
    }
    for(int i=4;i<10;i++){
        for(int j=0;j<6;j++){
            if(board[i][j]==turn && board[i-1][j+1]==turn && board[i-2][j+2]==turn && board[i-3][j+3]==turn && board[i-4][j+4]==turn )
                return 1;
        }
    }
    return 0;
}


int main(){
    int move=0;
    while(1){
        system("clear");
        printBoard();
        if(move==100){
        	printf("Its a draw game");
        	break;
		}
		playerMove();
        if(checkWin()){
            printBoard();
            printf("Player %c win da game",turn);
            printf("\nPlayer %c loose da game",(turn=='X'?'O':'X'));
            break;
        }
        else
            turn = (turn == 'X' ? 'O' : 'X');
        move++;
    }
    return 0;
}
