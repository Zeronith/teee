#include <iostream>
using namespace std;

void printHeart(int n) {
    // Adjust n if it is too small for a proper heart
    if (n < 6) {
        cout << "Heart shape requires n >= 6" << endl;
        return;
    }

    // Top part of the heart (two semicircles)
    for (int i = n / 2; i < n; i += 2) {
        // Print leading spaces
        for (int j = 1; j < n - i; j += 2) {
            cout << " ";
        }
        // Print the left side of the heart
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        // Print the space between the two sides
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
        }
        // Print the right side of the heart
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // Bottom part of the heart (inverted triangle)
    for (int i = n; i >= 1; --i) {
        // Print leading spaces
        for (int j = i; j < n; ++j) {
            cout << " ";
        }
        // Print stars for the inverted triangle
        for (int j = 1; j <= (2 * i - 1); ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter a value for n: ";
    cin >> n;

    printHeart(n);

    return 0;
}
