#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>  // random number
#include "ttt_functions.hpp"
using namespace std;


int main () {
    cout << "========================================\n";
    cout << "Welcome to play tic-tac-toe with me! \n"; 
    cout << "========================================\n";
    cout << "\n";

    // Initialize tic-tac-toe 
    cout <<"Initialize tic-tac-toe checkboard... \n";
    vector<vector <char>> ttt= init_ttt();
    cout <<"\n";

    // persons result
    bool game_result=false;  
    char human= '-';
    char computer= '-';
    int h_row=0;
    int h_col=0;
    int step=9;

    // Choose x or o 
    cout << "Please select either 'x' or 'o' to play: \n"; 
    cin >> human;
    if (human=='x') {
        computer= 'o';
    } else {computer= 'x';}

    // loop over 
    while (game_result== false && step>1) {
        // 
        cout << "Game remains " << step << " steps" << "\n";
        cout << "Please enter row number (0-2): ";
        cin >> h_row;
        // cout << "\n";
        cout << "Please enter col number (0-2): ";
        cin >> h_col;
        cout << "\n";

        // insert 'x' or 'o' 
        ttt[h_row][h_col]=(human);

        // computer's turn 
        ttt= draw_computer(ttt, computer);

        draw_chestborad(ttt); // Draw chestboard


        game_result = game_score(ttt, game_result);
        // cout << "The current score: " << game_result<< "\n";

        //
        step-=2;


    }
    if (game_result ==1) {
        cout << "Congratulations to the winner!" << "\n";
    } else {
        cout << "Game ends in a tie! Let's play again. \n";
    }


}

