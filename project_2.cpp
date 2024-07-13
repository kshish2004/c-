#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    // Input first number
    cout << "Enter first number: ";
    cin >> num1;

    // Input second number
    cout << "Enter second number: ";
    cin >> num2;

    // Input operation
    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    // Perform calculation based on operation
    switch(operation) {
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            // Check if the second number is zero
            if (num2 == 0) {
                cout << "Error! Division by zero is not allowed." << endl;
            } else {
                result = num1 / num2;
                cout << num1 << " / " << num2 << " = " << result << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please choose from '+', '-', '*', or '/'." << endl;
    }

    return 0;
}
