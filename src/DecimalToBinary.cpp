#include <iostream>
#include <stack>

using namespace std;

string decimalToBinary(int n) {
    stack<int> binaryStack;
    // modulo 2 to get binary
    while (n > 0) {
        binaryStack.push(n % 2);
        n /= 2;
    }
    string binaryNumber = "";
    // concatenate stack to form binary
    while (!binaryStack.empty()) {
        binaryNumber += to_string(binaryStack.top());
        binaryStack.pop();
    }
    return binaryNumber;
}

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    string binaryNumber = decimalToBinary(decimalNumber);
    cout << "Binary representation: " << binaryNumber << endl;

    return 0;
}