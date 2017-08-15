//mastermind game by Rszvan Radoi
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
int masterNumber, guess,turns=12, n[7],g[7];
bool win=false;
bool lost=false;
//sets initial number
void setMaster()
{
    int i=4;
    srand(time(0));
    masterNumber=rand()%8999+1000;
    while(masterNumber>0)
    {
        n[i]=masterNumber%10;
        i--;
        masterNumber/=10;
    }

}
//displays this gorgeous start screen. admit it. you love it.
void displayTitle()
{
    cout<<"* * * * * * * * * * * * * "<<endl;
    cout<<"* WELCOME TO MASTERMIND *"<<endl;
    cout<<"* * * * * * * * * * * * * "<<endl;
    cout<<endl;
}
//gets player input
void playerInput()
{
    cout<<"WHAT IS YOUR GUESS, PLAYER?"<<endl;
    cout<<"YOU HAVE "<<turns<<" TURNS LEFT."<<endl;
    turns--;
    cin>>guess;
    int i=4;
    while(guess>0)
    {
        g[i]=guess%10;
        i--;
        guess/=10;
    }
}
//checks and gives the answer
void compAnswer()
{
    int checker[7];
    checker[1]=0;checker[2]=0;checker[3]=0;checker[4]=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
    {
        if(g[i]==n[j])
            {
                checker[i]=1;
                if(i==j)
                    checker[i]=2;
            }
    }
    for(int i=1;i<=4;i++)
    {
        if(checker[i]==0)
            cout<<"O ";
        if(checker[i]==1)
            cout<<"! ";
        if(checker[i]==2)
            cout<<"X ";
    }
    cout<<endl<<endl;
}
//checks win and loss
void checkWin()
{
    int flag=1;
    for(int i=1;i<=4;i++)
        if(g[i]!=n[i])
            flag=0;
    if(flag==1)
        win=true;
    if(win==false&&turns==0)
        lost=true;
}
//displays end of game
void endGame()
{
    if(win==true)
        cout<<"YOU WON!"<<endl;
    else
    {
        cout<<"YOU LOST!"<<endl;
        cout<<"THE NUMBER WAS "<<n[1]<<n[2]<<n[3]<<n[4]<<"!"<<endl;
    }
}
int main()
{
    setMaster();
    displayTitle();
    while(win!=true && turns!=0)
    {
        playerInput();
        compAnswer();
        checkWin();
    }
    endGame();
    return 0;
}
