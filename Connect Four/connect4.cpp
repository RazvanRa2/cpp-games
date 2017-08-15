//tiny 2 player connect four by Razvan Radoi
#include <iostream>
#include <cstdlib>
using namespace std;

bool win=false;
bool endG=false;
int board[10][10];
int turn=1;
//displays the beautiful title
void displayTitle()
{
    cout<<'\t'<<"****************"<<endl;
    cout<<'\t'<<"* CONNECT FOUR *"<<endl;
    cout<<'\t'<<"****************"<<endl;
}
//sets row 0 for the game. used like this to avoid using new vector
void setGame()
{
    for(int i=1;i<=4;i++)
        board[0][i]=4;
}
//displays whose turn it is
void displayTurn()
{
    if(turn%2==0)
        cout<<'\t'<<"PLAYER 2 MOVE!"<<endl<<endl;
    else
        cout<<'\t'<<"PLAYER 1 MOVE!"<<endl<<endl;
}
//displays the board. them graphics are so smooth
void displayBoard()
{
    cout<<'\t'<<"-----------------"<<endl;
    cout<<'\t'<<"| 1 | 2 | 3 | 4 |"<<endl;
    cout<<'\t'<<"-----------------"<<endl;
    for(int i=1;i<=4;i++)
    {
        cout<<'\t';
        for(int j=1;j<=4;j++)
            cout<<"| "<<board[i][j]<<" ";
        cout<<"|"<<endl;
        cout<<'\t'<<"-----------------"<<endl;
    }
    cout<<'\t'<<"|               |"<<endl;
    cout<<'\t'<<"/               /"<<endl<<endl;
}
//gets player input
void input()
{
    int pInput;
    cout<<'\t'<<"CHOOSE COLUMN:";
    cin>>pInput;
    if(turn%2==0)
    board[board[0][pInput]][pInput]=2;
    else
    board[board[0][pInput]][pInput]=1;
    board[0][pInput]--;

}
//hardcoded win checker
void checkWin()
{
    if(board[1][1]==1&&board[1][2]==1&&board[1][3]==1&&board[1][4]==1) win=true;
    if(board[2][1]==1&&board[2][2]==1&&board[2][3]==1&&board[2][4]==1) win=true;
    if(board[3][1]==1&&board[3][2]==1&&board[3][3]==1&&board[3][4]==1) win=true;
    if(board[4][1]==1&&board[4][2]==1&&board[4][3]==1&&board[4][4]==1) win=true;

    if(board[1][1]==1&&board[2][1]==1&&board[3][1]==1&&board[4][1]==1) win=true;
    if(board[1][2]==1&&board[2][2]==1&&board[3][2]==1&&board[4][2]==1) win=true;
    if(board[1][3]==1&&board[2][3]==1&&board[3][3]==1&&board[4][3]==1) win=true;
    if(board[1][4]==1&&board[2][4]==1&&board[3][4]==1&&board[4][4]==1) win=true;

    if(board[1][1]==1&&board[2][2]==1&&board[3][3]==1&&board[4][4]==1) win=true;
    if(board[1][4]==1&&board[2][3]==1&&board[3][2]==1&&board[4][1]==1) win=true;


    if(board[1][1]==2&&board[1][2]==2&&board[1][3]==2&&board[1][4]==2) win=true;
    if(board[2][1]==2&&board[2][2]==2&&board[2][3]==2&&board[2][4]==2) win=true;
    if(board[3][1]==2&&board[3][2]==2&&board[3][3]==2&&board[3][4]==2) win=true;
    if(board[4][1]==2&&board[4][2]==2&&board[4][3]==2&&board[4][4]==2) win=true;

    if(board[1][1]==2&&board[2][1]==2&&board[3][1]==2&&board[4][1]==2) win=true;
    if(board[1][2]==2&&board[2][2]==2&&board[3][2]==2&&board[4][2]==2) win=true;
    if(board[1][3]==2&&board[2][3]==2&&board[3][3]==2&&board[4][3]==2) win=true;
    if(board[1][4]==2&&board[2][4]==2&&board[3][4]==2&&board[4][4]==2) win=true;

    if(board[1][1]==2&&board[2][2]==2&&board[3][3]==2&&board[4][4]==2) win=true;
    if(board[1][4]==2&&board[2][3]==2&&board[3][2]==2&&board[4][1]==2) win=true;
    // it also checks for draw and displays the text if it's a draw
    if(turn==17)
    {
        endG=true;
        cout<<"IT'S A DRAW!"<<endl;
    }
}
//displays who won, if anybody did
void endGame()
{
    if(win==true)
    {
        if(turn%2==1)
            cout<<"PLAYER2 WINS!"<<endl;
        if(turn%2==0)
            cout<<"PLAYER1 WINS!"<<endl;
    }
}
//main, self explanatory
int main()
{
    setGame();
    while(win==false && endG==false)
    {
        displayTitle();
        displayTurn();
        displayBoard();
        input();
        turn++;
        system("cls");
        checkWin();
    }
    endGame();
    return 0;
}
