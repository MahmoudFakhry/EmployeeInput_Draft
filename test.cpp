#include <iostream>

using namespace std;

int check_num(string str_num) {
    for (int i = 0; i < str_num.length(); i++) {
        if ((str_num[i] != '0') && (str_num[i] != '1') && (str_num[i] != '2') && (str_num[i] != '3')
        &&  (str_num[i] != '4') && (str_num[i] != '5') && (str_num[i] != '6') && (str_num[i] != '7')
        &&  (str_num[i] != '8') && (str_num[i] != '9')) {
            return 0; // Not integer input
        }
    }
    return 1;  // Integer input
}
 
int main() {

    int **arr_keynums = new int*[1001];
    for (int i = 0; i < 1001; i++) {
        arr_keynums[i] = new int[1];
        arr_keynums[i][0] = 0; // By default, set to zero.
    } 

    int invalid = 1, key_number;
    while (invalid) {
        string key_input_0, key_input_1;
        cout << "Enter your key number:" << endl;
        getline(cin, key_input_0);
        cout << "Re-enter your key number:" << endl;
        getline(cin, key_input_1);
        if (key_input_0 != key_input_1) {
            invalid = 1;  // Invalid input
            cout << "Sorry, but the keys entered do not match. Please try again." << endl;
        } else if (!check_num(key_input_0)) {
            invalid = 1;  // Invalid input
            cout << "They key number must be a number from 7,000 to 8,000. Please try again." << endl;
        } else {
            key_number = stoi(key_input_0.c_str());
            // Check to see if number is within 7000 to 8000 number range
            if ((key_number < 7000) || (key_number > 8000)) {
                cout << "Your input was not a value from 7,000 to 8,000. Please try again." << endl;
            } else {
                invalid = 0; // Valid input
            }
        }
    }

    int dollar_num, dollar_invalid = 1;
    while (dollar_invalid) {
        string dollar_input_0, dollar_input_1;
        cout << "Enter the dollar amount associated with this key:" << endl;
        getline(cin, dollar_input_0);
        cout << "Re-enter the dollar amount associated with this key:" << endl;
        getline(cin, dollar_input_1);
        if (dollar_input_0 != dollar_input_1) {
            dollar_invalid = 1;  // Invalid input
            cout << "Sorry, but the dollar amounts entered do not match. Please try again." << endl;
        } else if (!check_num(dollar_input_0)) {
            dollar_invalid = 1;  // Invalid input
            cout << "Dollar amount must be a number input." << endl;
        } else {
            dollar_invalid = 0;  // Valid input
            dollar_num = stoi(dollar_input_0.c_str());
        }
    }
    // Subtract 7000 to get array number
    key_number -= 7000; 

    arr_keynums[key_number][0] = dollar_num;

    for (int i = 0, num; i < 1001; i++) {
        num = i + 7000;
        // Prints key numbers and dollar amount
        cout << "Key number " << num << " has $" << arr_keynums[i][0] << "." << endl;
    }

    return 0;
}

// Put people in keywords in own array to easily find. Ex: 'Refund' or 'Refuse'