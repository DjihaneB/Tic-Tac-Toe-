#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
bool tie = false;

string n1;
string n2;

bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void functionOne() {
    cout << n1 << " is player 1, so he/she will play first.\n";
    cout << n2 << " is player 2, so he/she will play second.\n";
    cout << "      |     | \n";
    cout << " " << space[0][0] << "    |  " << space[0][1] << "  |  " << space[0][2] << " \n";
    cout << " _____|_____|_____ \n";
    cout << "      |     | \n";
    cout << " " << space[1][0] << "    | " << space[1][1] << "   | " << space[1][2] << " \n";
    cout << " _____|_____|_____ \n";
    cout << "      |     | \n";
    cout << " " << space[2][0] << "    | " << space[2][1] << "   | " << space[2][2] << " \n";
    cout << "      |     | \n";
}

void functionTwo() {
    string input;

    if (token == 'X') {
        cout << n1 << " please enter: ";
        cin >> input;
    }

    if (token == 'O') {
        cout << n2 << " please enter: ";
        cin >> input;
    }

    if (isNumeric(input)) {
        int digit = stoi(input);

        if (digit >= 1 && digit <= 9) {
            row = (digit - 1) / 3;
            column = (digit - 1) % 3;

            if (space[row][column] == 'X' || space[row][column] == 'O') {
                cout << "This place is already taken, please choose another one." << endl;
                return; // Ne réappellez pas la fonctionTwo() ici pour éviter une récursion inutile
            } else {
                if (token == 'X') {
                    space[row][column] = 'X';
                    token = 'O';
                } else {
                    space[row][column] = 'O';
                    token = 'X';
                }
            }
        } else {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            return; // Ne réappellez pas la fonctionTwo() ici pour éviter une récursion inutile
        }
    } else {
        cout << "Invalid input. Please enter a number between 1 and 9." << endl;
        return; // Ne réappellez pas la fonctionTwo() ici pour éviter une récursion inutile
    }
    functionOne();
}

bool functionThree() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
            return true;
        }
    }

    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);

    cout << "Enter the name of the second player: ";
    getline(cin, n2);

    functionOne();

    while (!functionThree()) {
        functionTwo();
    }

    if (tie) {
        cout << "It's a tie!" << endl;
    } else {
        if (token == 'X') {
            cout << n2 << " Player O won the game";
        } else {
            cout << n1 << " Player X won the game";
        }
    }

    return 0;
}
