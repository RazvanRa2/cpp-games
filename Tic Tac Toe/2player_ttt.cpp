//A 2-PLAYER GAME OF TIC TAC TOE BY RAZVAN RADOI. PLEASE DO NOT REMOVE
#include<iostream> //needed for player input and display output
#include<cstring> //needed for player name input
#include<stdlib.h> //needed for clearing the screen
using namespace std;

//global variables should never be used
int board[5][5];
char player1[20];
char player2[20];
int turn=1;
bool flag=0;
bool win=false;
int score1;
int score2;
bool play=true;
//takes player names
void playerNameInput()
{
    cout<<"--------------------------------"<<endl;
    cout<<"WELCOME TO A GAME OF TIC TAC TOE"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<endl;
    cout<<"PLEASE ENTER THE NAME FOR PLAYER1 (X);"<<endl;
    cin>>player1;
    cout<<"PLEASE ENTER THE NAME FOR PLAYER2 (O);"<<endl;
    cin>>player2;
}
//displays whose turn it is
void turnDisplay()
{
    if(turn%2==1)
        cout<<player1<<"(X)'s turn";
    if(turn%2==0)
        cout<<player2<<"(0)'s turn";
    cout<<endl;
    cout<<endl;
}
//displays the board
void display()
{
        cout<<"-------";
        cout<<endl;
        for(int i=1;i<=3;i++){
            cout<<"|";
            for(int j=1;j<=3;j++){
                if(board[i][j]==1)
                    cout<<"X"<<"|";
                if(board[i][j]==2)
                    cout<<"0"<<"|";
                if(board[i][j]==0)
                    cout<<" "<<"|";
            }
            cout<<endl;
            cout<<"-------";
            cout<<endl;
        }
}
//takes player input and changes turns
void playerInput()
{
    int i, j;
    cout<<"PLEASE ENTER ROW AND COLUMN NUMBERS:"<<endl;
    cin>>i>>j;
    if(turn%2==1)
        board[i][j]=1;
    else
        board[i][j]=2;
    turn++;
}
//checks if the game ended; not the most elegant solution
void checkWin()
{
    //casses in which X wins
    //horizontal cases
    if(board[1][1]==1&&board[1][2]==1&&board[1][3]==1)
        win=true;
    if(board[2][1]==1&&board[2][2]==1&&board[2][3]==1)
        win=true;
    if(board[3][1]==1&&board[3][2]==1&&board[3][3]==1)
        win=true;
    //vertical cases
    if(board[1][1]==1&&board[2][1]==1&&board[3][1]==1)
        win=true;
    if(board[1][2]==1&&board[2][2]==1&&board[3][2]==1)
        win=true;
    if(board[1][3]==1&&board[2][3]==1&&board[3][3]==1)
        win=true;
    //diagonal cases
    if(board[1][1]==1&&board[2][2]==1&&board[3][3]==1)
        win=true;
    if(board[3][1]==1&&board[2][2]==1&&board[1][3]==1)
        win=true;

    //cases in which Y wins
    //horizontal cases
    if(board[1][1]==2&&board[1][2]==2&&board[1][3]==2)
        win=true;
    if(board[2][1]==2&&board[2][2]==2&&board[2][3]==2)
        win=true;
    if(board[3][1]==2&&board[3][2]==2&&board[3][3]==2)
        win=true;
    //vertical cases
    if(board[1][1]==2&&board[2][1]==2&&board[3][1]==2)
        win=true;
    if(board[1][2]==2&&board[2][2]==2&&board[3][2]==2)
        win=true;
    if(board[1][3]==2&&board[2][3]==2&&board[3][3]==2)
        win=true;
    //diagonal cases
    if(board[1][1]==2&&board[2][2]==2&&board[3][3]==2)
        win=true;
    if(board[3][1]==2&&board[2][2]==2&&board[1][3]==2)
        win=true;

}
//checksDraw
void checkDraw()
{
    if(turn==10&&win==false)
        flag=true;
}
//anounces winner or draw and keeps score
void announceWin()
{

    cout<<endl;cout<<endl;
    if(turn%2==0&&flag!=true)
    {
        cout<<player1<<" WINS!"<<endl;
        score1++;
    }
    if(turn%2==1&&flag!=true)
    {
        cout<<player2<<" WINS!"<<endl;
        score2++;
    }
    if(flag==true)
        cout<<"DRAW"<<endl;

}
//displays the score
void scoreDisplay()
{
    cout<<player1<<" - "<<score1<<" ---- "<<score2<<" - "<<player2<<endl;
}

void newGame()
{
    cout<<"Do you want to play a new game? [y/n]"<<endl;
    char answer[2];
    cin>>answer;
    if(answer[0]=='n' || answer[0]=='N')
        play=false;
    if(answer[0]=='y' || answer[0]=='Y')
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                board[i][j]=0;
        flag=false;
        win=false;
        turn=1;
        play=true;
    }

}
void finalScore()
{
    cout<<"FINAL SCORE IS:"<<endl;
    cout<<player1<<" - "<<score1<<" ---- "<<score2<<" - "<<player2<<endl;
    if(score1>score2)
        cout<<player1<<" WINS THE WHOLE GAME!"<<endl;
    if(score2>score1)
        cout<<player2<<" WINS THE WHOLE GAME!"<<endl;
    if(score1==score2)
        cout<<"IT'S A DRAW!"<<endl;
}
int main()
{
    playerNameInput();
    system("cls");
    while(play==true)
    {
        while(win!=true && flag!=true)
        {
        scoreDisplay();
        turnDisplay();
        display();
        playerInput();
        checkWin();
        checkDraw();
        system("cls");
        }
        display();
        announceWin();
        newGame();
        system("cls");
    }
    finalScore();
    return 0;
}
