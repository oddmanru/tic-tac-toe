#include <iostream>
#include <string>
#include <vector>
using namespace std;

// functions
vector<vector <char>> init_ttt () {
    // Initialize a 3X3 2-D vector
    vector<vector <char>> ttt (3, vector<char> (3, '-'));
    for(int i=0; i< ttt.size(); i++) {
        for (int j=0; j<ttt[i].size(); j++ ) {
            cout << ttt[i][j] << " ";

        }
    cout << "\n";

    }
    return ttt;
}

bool game_score (vector<vector <char>> ttt, bool game_result) {
    
    // Identify result in rows
    // cout << "Go over the row check" << "\n";
    for (int i=0; i<3; i++) {
        if (ttt[i][0] != '-') {
            if (ttt[i][0]==ttt[i][1] && ttt[i][1]==ttt[i][2]) {
                // print out result
                cout << ttt[i][0]<< " won! in " << i <<"th row" << "\n";
                game_result=true;
                return game_result;
            } 
        } 
            
    }
    // Identify result in columns
    // cout << "Go over the col check" << "\n";
    for (int i=0; i<3; i++) {
        if (ttt[0][i] != '-') {
            if (ttt[0][i]==ttt[1][i] && ttt[1][i]==ttt[2][i]) {
                // print out result
                cout << ttt[0][i] <<" won in " << i << "th col!" << "\n";
                game_result=true;
                return game_result;
            } 
        } 
        
    }
    // Identify result in diagonals
    if (ttt[1][1]!= '-') {
        // cout << "Go over the 1st diagonal check" << "\n";
        if(ttt[0][0]==ttt[1][1] && ttt[1][1]==ttt[2][2]) {
            cout<< ttt[0][0]<< " won in the diagonal!" << "\n";
            game_result=true;
            return game_result;
        } 

        // cout << "Go over the 2nd diagonal check" << "\n";
        if (ttt[2][0]==ttt[1][1] && ttt[1][1]==ttt[0][2]) {
            cout<< ttt[2][0]<< " won in the diagonal!" << "\n";
            game_result=true;
            return game_result;

        } else {return game_result;}
    } 
    return game_result;
}

// Computer's turn
vector<vector <char>> draw_computer(vector <vector <char>> ttt, char computer) {
    int row=0;
    int col=0;
    cout << "Now is computer's turn... \n";
    row= rand() % 3;
    col= rand() % 3; 
    while (ttt[row][col] !='-') {
        row= rand() % 3; // obtain a row number
        col= rand() % 3; // obtain a col number

    }
    ttt[row][col]= computer;

    return ttt;
}

// Draw chestboard
void draw_chestborad(vector<vector <char>> ttt) {

    // Draw chestbord
    cout << "\n";
    for (int i=0; i<3; i++) {
        for (int j=0;j<3;j++) {
            cout << ttt[i][j] << " ";
        }
        cout << "\n";
    }
}