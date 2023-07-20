#include <iostream>
#include <unordered_map>
using namespace std;

char firstNonRepeatingCharacter(string s) {
    unordered_map<char, int> charFrequency;

    // Count the frequency of each character in the string
    for (char c : s) {
        charFrequency[c]++;
    }

    // Find the first non-repeating character
    for (char c : s) {
        if (charFrequency[c] == 1) {
            return c;
        }
    }

    // If no non-repeating character is found, return '$'
    return '$';
}

int main() {
    string inputString;
    cout << "Enter the string: ";
    cin >> inputString;

    char result = firstNonRepeatingCharacter(inputString);

    if (result == '$') {
        cout << "No non-repeating character found." << endl;
    } else {
        cout << "The first non-repeating character is: " << result << endl;
    }

    return 0;
}
