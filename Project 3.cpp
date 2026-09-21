#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

int main() {
    vector<string> history;
    string input;

    cout << "=== Interactive Calculator ===\n";
    cout << "Operators: +  -  *  /  %  ^\n";
    cout << "Type 'h' for history and 'q' to quit.\n\n";

    while (true) {
        cout << "Enter calculation (example: 10 + 5): ";
        getline(cin, input);

        if (input == "q" || input == "Q")
            break;

        if (input == "h" || input == "H") {
            cout << "\n--- Last 10 Calculations ---\n";

            if (history.empty()) {
                cout << "No calculations yet.\n";
            } else {
                for (string item : history)
                    cout << item << endl;
            }

            cout << endl;
            continue;
        }

        stringstream ss(input);
        double a, b;
        char op;

        if (!(ss >> a >> op >> b)) {
            cout << "Invalid input! Example: 10 + 5\n\n";
            continue;
        }

        double result;
        bool valid = true;

        switch (op) {
            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                if (b == 0) {
                    cout << "Error: Cannot divide by zero!\n\n";
                    valid = false;
                } else {
                    result = a / b;
                }
                break;

            case '%':
                if (b == 0) {
                    cout << "Error: Cannot use zero with modulus!\n\n";
                    valid = false;
                } else {
                    result = fmod(a, b);
                }
                break;

            case '^':
                result = pow(a, b);
                break;

            default:
                cout << "Invalid operator!\n\n";
                valid = false;
        }

        if (valid) {
            cout << "Result = " << result << "\n";

            string record = input + " = " + to_string(result);

            history.push_back(record);

            if (history.size() > 10)
                history.erase(history.begin());

            cout << endl;
        }
    }

    cout << "Calculator closed. Thank you!\n";
    return 0;
}
