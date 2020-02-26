#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace std;

//Learning Objectives:
//●	Write C++ programs in a modern software development using the CLion IDE and version control with Github repositories.
//●	Perform basic computational operations such as i/o,
//●	Apply control structures such as if statements, loops, and error messages.
//●	Implement and manipulate the contents of a 2D vector.

//author：Tao Long
//studentID: 06558480
//project: CSC112-Project1
//instructor： Dr.Alqahtani

int main() {

    //declare variables to draw the gamefield
    //signal for the actual spot that battleship could stays
    //field for the full canvas ( "!","~" in addition to signals )
    int signal[3][3];
    string field[5][5];

    //initialize all the nine spots and assign with a value of -1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            signal[i][j] = -1;
        }
    }

    //assign the values for the each elements in the canvas
    // ! !  rowstep = 0
         // " "  rowstep = 0/2/4; coluStep = 0/2/4
         // "!"  rowstep = 0/2/4; coluStep = 1/3
    //~~~~~ rowstep = 1
         // "~"  rowstep = 1/3; coluStep = 0/1/2/3/4
    //print each element
    //end with a new line after each element in a row has been assigned and printed
    for (int rowStep = 0; rowStep < 5; rowStep++) {
        for (int coluStep = 0; coluStep < 5; coluStep++) {
            if (rowStep % 2 == 0) {

                if (coluStep % 2 == 0) {
                    field[rowStep][coluStep] = " ";
                    cout << field[rowStep][coluStep];
                }
                if (coluStep % 2 == 1) {
                    field[rowStep][coluStep] = "!";
                    cout << field[rowStep][coluStep];
                }
            }
            else {
                field[rowStep][coluStep] = "~";
                cout << field[rowStep][coluStep];
            }
        }
        cout << endl;
    }

    //get new random numbers each time and use srand()
    //assign two random number from 0-2 for the battleship's position
    //Location (row[1-3] column[1-3]):
    //assign the position with a value of 1, being different from others (which are -1)
    srand(time(0));
    int shipPosX = rand() % 3;
    int shipPosY = rand() % 3;
    signal[shipPosX][shipPosY] = 1;

    //help find the answer if you want
    //cout << "shipPos: " << shipPosX + 1 << ", " << shipPosY  + 1 << endl;

    //int the player's choice
    int playerPosX = 0;
    int playerPosY = 0;

    //get a signally variable for the big while loop
    string passfail = "fail";

    //find the time
    int timeCounts = 0;

    //great loop contains most of the game details
    while (passfail == "fail") {

        //ask player to type-in his/her chosen position
        cout << "Location (row[1-3] column[1-3]): ";
        cin >> playerPosX;
        cin >> playerPosY;

        //an if-statement for the wrong input
        if ((playerPosX != 1 && playerPosX != 2 && playerPosX != 3) || (playerPosY != 1 && playerPosY != 2 && playerPosY != 3)){
            cout <<"Wrong input! Retype Location (row[1-3] column[1-3]): " << endl;
            cin >> playerPosX;
            cin >> playerPosY;
        }

        //initialize the past tries
        //assign all of the spots in vectors to be -10000 as initial assignment
        vector<int> pastTryRow(9);
        vector<int> pastTryColu(9);
        for (int i = 0; i < 9; i++) {
            pastTryRow[i] = -10000;
            pastTryColu[i] = -10000;
        }

        //add current attempt to the pastTry[timeCounts]
        pastTryRow[timeCounts] = (playerPosX - 1) * 2;
        pastTryColu[timeCounts] = (playerPosY - 1) * 2;

        //for failed attempt, we assign the postion's signal with the value of 0,
        // being differernt from the actual battleship position's signal = 1, the untouched positions' signal -1
         if (playerPosX - 1 != shipPosX || playerPosY - 1 != shipPosY) {
            signal[playerPosX - 1][playerPosY - 1] = 0;
        }

            //if the player's choice of position does NOT MATCH with teh actual battlehsip position
             if (signal[playerPosX - 1][playerPosY - 1] == 0) {

                    //for the field, these pieces of codes are tryig to change the specific position that the player has
                    //reached with X
                    for (int changeRow = 0; changeRow < 9; changeRow++) {
                        for (int changeColu = 0; changeColu < 9; changeColu++) {
                                if (pastTryRow[changeRow] != -10000 && pastTryColu[changeColu] != -10000) {
                                    field[pastTryRow[changeRow]][pastTryColu[changeColu]] = "X";
                            }
                        }
                    }

                    //print the whole new field
                    for (int printCurrentRow = 0; printCurrentRow < 5; printCurrentRow++) {
                        for (int printCurrentColu = 0; printCurrentColu < 5; printCurrentColu++) {
                            cout << field[printCurrentRow][printCurrentColu];
                        }
                        cout << endl;
                    }

                    //after each unsuccessful attempt, add 1 to the timeCounts
                    timeCounts = timeCounts + 1;
            }

        //if the player's choice of position does MATCH with teh actual battleship position
        else {

            //assign passfail to a new value to escape from the great loop
            passfail = "success";

                 //for the field, these pieces of codes are tryig to change the found position with O
                 for (int changeRow = 0; changeRow < 9; changeRow++) {
                     for (int changeColu = 0; changeColu < 9; changeColu++) {
                         if (pastTryRow[changeRow] != -10000 && pastTryColu[changeColu] != -10000) {
                             field[pastTryRow[changeRow]][pastTryColu[changeColu]] = "O";
                         }
                     }
                 }

                 //print the whole new field
                 for (int printCurrentRow = 0; printCurrentRow < 5; printCurrentRow++) {
                     for (int printCurrentColu = 0; printCurrentColu < 5; printCurrentColu++) {
                         cout << field[printCurrentRow][printCurrentColu];
                     }
                     cout << endl;
                 }

                 //still add 1 to the num. of guess
                 timeCounts = timeCounts + 1;

                 //print success notifiction
                 cout << "You sunk my battleship! (" << timeCounts << " guesses.)";

                 //break from the great loop
                 break;
        }
    }

    return 0;
}
