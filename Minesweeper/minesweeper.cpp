//minesweeper game by RAZVAN RADOI. please do not remove
//contrary to the original game, this one only shows only the cell that the player selected;
// everything else is almost the same - win by ticking all the boxes that have no bombs

//libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;

//variables and boards
struct game
{
    int show;
    int hidden;
} board[10][10];
int moves=0;
int a,b;
struct fake{
    int value;
    bool visited;
} fakeBoard[10][10];;
bool gameEnd=false;
bool win=false;

//puts the bombs in place. no need to understand the algorithm. it looks like this because there was a bug and after an hour, this is the only thing i could come up with
void setBombs()
{
    int qrry[79];
    int aux=91;
    for(int i=1;i<=79;i++)
        if((i+11)%10!=0)
            qrry[i]=i+11;
        else
        {
            qrry[i]=aux;
            aux++;
        }
    cout<<endl;
    srand(time(NULL));
    random_shuffle(qrry+1,qrry+79);
    for(int i=1;i<=9;i++)
    {
        a=qrry[i]/10;
        b=qrry[i]%10;
        board[a][b].hidden=1;
    }
}
//counts player's moves
void displayMoves()
{

    cout<<"MOVES MADE:"<<moves<<endl;
    moves++;
}
//counts how many bombs there are around a cell
void counter(){
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
        {
            if(board[i+1][j].hidden==1)
                board[i][j].show++;
            if(board[i-1][j].hidden==1)
                board[i][j].show++;
            if(board[i][j-1].hidden==1)
                board[i][j].show++;
            if(board[i][j+1].hidden==1)
                board[i][j].show++;

            if(board[i+1][j+1].hidden==1)
                board[i][j].show++;
            if(board[i-1][j+1].hidden==1)
                board[i][j].show++;
            if(board[i-1][j-1].hidden==1)
                board[i][j].show++;
            if(board[i+1][j-1].hidden==1)
                board[i][j].show++;
        }
}
//gets player input
void playerInput()
{
    cout<<"PLEASE ENTER ROW NUMBER AND COLUMN NUMBER:"<<endl;
    cin>>a>>b;
    fakeBoard[a][b].visited=true;
    if(board[a][b].hidden==1)
        gameEnd=true;
    if(board[a][b].hidden!=1)
        fakeBoard[a][b].value=board[a][b].show;
}
//displays the board;
void displayGame()
{
    int inr=1;
    cout<<"  1  2  3  4  5  6  7  8  9"<<endl;
    for(int i=1;i<=9;i++)
    {
        cout<<inr;
        inr++;
        for(int j=1;j<=9;j++)
            if(fakeBoard[i][j].value==0&&fakeBoard[i][j].visited==0)
                cout<<" * ";
            else
                cout<<" "<<fakeBoard[i][j].value<<" ";
        cout<<endl<<endl;
    }
}
//checks if the player won by comparing moves number to empty cells number
void checkWin()
{
    if(moves==72)
        win=true;
}
void displayLogo()
{
    cout<<"-------------------"<<endl;
    cout<<"|***Minesweeper***|"<<endl;
    cout<<"-------------------"<<endl;
}
int main()
{
    setBombs();
    counter();
    while(win!=true&&gameEnd!=true)
    {
        displayLogo();
        displayMoves();
        displayGame();
        playerInput();
        checkWin();
        system("cls");
    }
    if(win==true&& gameEnd==false){
        cout<<"YOU WON!"<<endl;
    }
    if(gameEnd==true)
        cout<<"YOU LOST!"<<endl;
    return 0;
}
