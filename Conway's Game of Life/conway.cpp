// Copyright 2015 Razvan Radoi & IXIA
// please compile using -std=c++11
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct gameBoard {
    int cell = 0;
    int visited = 0;
};

// gets the state for the board cell
int getState(int state, int i, int j, struct gameBoard board[][22]) {
    if(state == 3)
        return 1;
    if(state == 2)
        return board[i][j].cell;
    return 0;
}

// resets by interchanging board and newBoard
void reset(struct gameBoard board[][22], struct gameBoard newBoard[][22]) {
    for(int i = 1; i < 21; i++) {
        for(int j = 1; j < 21; j++) {
                board[i][j].cell = newBoard[i][j].cell;
                board[i][j].visited = newBoard[i][j].visited;
                newBoard[i][j].cell = 0;
        }
    }
}

// the core of the mechanics of the game. checks if cell is alive and
// also marks visited cells with 0
void core(struct gameBoard board[][22], struct gameBoard newBoard[][22]) {
    for(int i = 1; i < 21; i++) {  // for every cell on the board
        for(int j = 1; j < 21; j++) {
               int score = 0; // set a score
               score += board[i][j+1].cell;  // for every cell in its vecinity
               score += board[i][j-1].cell;  // increment the score
               score += board[i-1][j].cell;
               score += board[i+1][j].cell;
               score += board[i-1][j-1].cell;
               score += board[i+1][j+1].cell;
               score += board[i-1][j+1].cell;
               score += board[i+1][j-1].cell;
               // evaluate next state
               newBoard[i][j].cell = getState(score, i, j, board);
               if(newBoard[i][j].cell == 1)  // and update cell
                  newBoard[i][j].visited=1;
            }
    }
}

//displays the board
void print(struct gameBoard newBoard[][22]) {
    cout<<" # # # # # # # # # # # # # # # # # # # # # "<<'\n';
    for(int i = 1; i < 21; i++) {
        cout << "#";
        for(int j=1; j < 21; j++) {
                if(newBoard[i][j].cell==0 && newBoard[i][j].visited==0)
                    cout << "  ";
                if(newBoard[i][j].cell==1)
                    cout << " *";
                if(newBoard[i][j].cell==0 && newBoard[i][j].visited==1)
                    cout << " 0";
            }
        cout << "#";
        cout << endl;

    }
    cout << " # # # # # # # # # # # # # # # # # # # # # "<< endl;
}

// this is to make it so that you can see the evolution
// adjust the number to your computer's needs
void sleep() {
    for(int i = 0; i < 100000000; i++);
    system("cls");  // clear screen
}

int main()
{
    struct gameBoard board[22][22];
    struct gameBoard newBoard[22][22];

    system("cls");
    cout << "ENTER THE NUMBER OF EVOLUTION STEPS TO BE SIMULATED:" << endl;
    int evolutionSteps;
    cin >> evolutionSteps;  // get number of evolution steps

    ifstream in("conway.in");  // file contains initial board
    for( int i = 1; i < 21; i++ ) {
        for( int j = 1; j < 21; j++ ) {
                in >> board[i][j].cell;  // read boatd from file and
                if( board[i][j].cell == 1)  // mark cells as visited or
                    board[i][j].visited = 1;
                else
                    board[i][j].visited = 0;  //not visited
            }
    }
    in.close();

    for(int k = 0; k < evolutionSteps; k++) {
            core(board, newBoard);   // evaluate board
            print(newBoard);  // print board state
            reset(board, newBoard);  // reset board
            sleep();  // wait
    }
    return 0;
}
