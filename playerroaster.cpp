#include <iostream>
#include <vector>
using namespace std;

struct Player {

  string Names;
  int jerseyNums;
  int ratingNums;
};

void initialize(vector<Player>& v);
void output(const vector<Player>& v);
void addPlayer(vector<Player>& v, Player player1);
void deletePlayer(vector<Player>& v, int playerNumber);
void updateRating(vector<Player>& v, int playerNumber, int rating);
void aboveRating(const vector<Player>& v, int rating);

Player player1;
vector<Player> Players(5);

vector<string> Names;
vector<int> jerseyNums;
vector<int> ratingNums;

int main() {


    unsigned int i;
    string playerName;
    int playerJersy;
    int playerRating;
    char menuOp;

    cout << "Enter Player1 Info" << endl;
    cin >> Players.at (0).Names;
    cin >> Players.at (0).jerseyNums;
    cin >> Players.at (0).ratingNums;

    cout << "Enter Player2 Info" << endl;
    cin >> Players.at (1).Names;
    cin >> Players.at (1).jerseyNums;
    cin >> Players.at (1).ratingNums;

    cout << "Enter Player3 Info" << endl;
    cin >> Players.at (2).Names;
    cin >> Players.at (2).jerseyNums;
    cin >> Players.at (2).ratingNums;

    cout << "Enter Player4 Info" << endl;
    cin >> Players.at (3).Names;
    cin >> Players.at (3).jerseyNums;
    cin >> Players.at (3).ratingNums;

    cout << "Enter Player5 Info" << endl;
    cin >> Players.at (4).Names;
    cin >> Players.at (4).jerseyNums;
    cin >> Players.at (4).ratingNums;


    vector<string> Names = {Players.at (0).Names, Players.at (1).Names, Players.at (2).Names, Players.at (3).Names, Players.at (4).Names};
    vector<int> jerseyNums = {Players.at (0).jerseyNums, Players.at (1).jerseyNums, Players.at (2).jerseyNums, Players.at (3).jerseyNums, Players.at (4).jerseyNums};
    vector<int> ratingNums = {Players.at (0).ratingNums, Players.at (1).ratingNums, Players.at (2).ratingNums, Players.at (3).ratingNums, Players.at (4).ratingNums};

      cout << "ROSTER" << endl;
      for (i = 0; i < jerseyNums.size(); ++i) {
          cout << "Player " << i + 1 << " -- Name: " <<Names.at(i)<<" -- Jersey number: "
               << jerseyNums.at(i) << ", Rating: " << ratingNums.at(i) << endl;
      }
      cout << endl;

    do {
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl << endl;

        cout << "Choose an option:" << endl;
        cin >> menuOp;

        //Add
        if (menuOp == 'a') {
            Player playerAdd;
            addPlayer(Players, player1);
        }
            //Delete
        else if (menuOp == 'd') {
            int playerDel;
            cin >> playerDel;
            deletePlayer(Players, playerDel);
        }

            //Update
        else if (menuOp == 'u') {
            int playerUpdates;
            int playerratingUp;
            cin >> playerUpdates;
            cin >> playerratingUp;
          updateRating(Players, playerUpdates, playerratingUp);
        }

            // > Rating
        else if (menuOp == 'r') {
            int playerRatingNumR;
            cin >> playerRatingNumR;
         aboveRating(Players, playerRatingNumR);
        }

        //output
        else if (menuOp == 'o') {
            cout << "ROSTER" << endl;
            for (i = 0; i < jerseyNums.size(); ++i) {
                cout << "Player " << i + 1 << " -- Name: " <<Names.at(i)<<" -- Jersey number: "
                     << jerseyNums.at(i) << ", Rating: " << ratingNums.at(i) << endl;
            }
            cout << endl;
        }

    } while(menuOp != 'q');

    return 0;
}

void initialize(vector<Player>& Names){

}

void addPlayer(vector<Player>& v, Player player1){


    cout << "Enter a new player's jersey number:" << endl;

    cin >> player1.jerseyNums;
    int n = player1.jerseyNums;
    jerseyNums.push_back(n);


    cout << "Enter the player's rating:" << endl;
    cin >> player1.ratingNums;
    int m =player1.ratingNums;
    ratingNums.push_back(m);
    cout << endl;

}
void deletePlayer(vector<Player>& v, int playerNumber){
    cout << "Enter a jersey number:" << endl;
    int playerJersy;
    cin >> playerJersy;
    //find the player using her/his jersey number
    for (int i = 0; i < jerseyNums.size(); ++i) {
        if (playerJersy == jerseyNums.at(i)) {
            playerJersy = i;
        }
    }
    //shift the vectors' elements up to remove the element
    for (int i = 0; i < jerseyNums.size() - 1; ++i) {
        if (i >= playerJersy) {
            Names.at(i) = Names.at(i + 1);
            jerseyNums.at(i) = jerseyNums.at(i + 1);
            ratingNums.at(i) = ratingNums.at(i + 1);
        }
    }
    Names.pop_back();
    jerseyNums.pop_back();
    ratingNums.pop_back();
    cout << endl;
}
void updateRating(vector<Player>& v, int playerNumber, int rating){

    for (int i = 0; i < jerseyNums.size(); ++i) {
        if (jerseyNums.at(i) == playerNumber) {
            ratingNums.at(i) = rating;
        }
    }
    cout << endl;
}
void aboveRating(const vector<Player>& v, int rating){


    cout << "ABOVE " << rating << endl;
    for (int i = 0; i < jerseyNums.size(); ++i) {
        if (ratingNums.at(i) > rating) {
            cout << "Player " << i + 1 << " -- Jersey number: "
                 << jerseyNums.at(i) << ", Rating: "
                 << ratingNums.at(i) << endl;
        }
    }
    cout << endl;

}
