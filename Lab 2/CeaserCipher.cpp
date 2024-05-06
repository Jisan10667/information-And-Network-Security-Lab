#include<iostream>


using namespace std;

// Function to shift characters in a string to the left by the specified key
string shiftLeft(string text, int shiftKey) {
    for(int index = 0; index < text.length(); index++) {
        // Adjust each character in the string by shifting to the left
        text[index] = (text[index] - 'a' - shiftKey + 26) % 26 + 'a';
    }
    return text;
}

// Function to shift characters in a string to the right by the specified key
string shiftRight(string text, int shiftKey) {
    for(int index = 0; index < text.length(); index++) {
        // Adjust each character in the string by shifting to the right
        text[index] = (text[index] - 'a' + shiftKey) % 26 + 'a';
    }
    return text;
}


int main() {
    string encodedText;
    encodedText = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";
    
    // Displaying decoded texts for each possible key from 1 to 25
    for(int key = 1; key < 26; key++) {
        cout << "Using Key = " << key << ": Decoded Text - " << shiftLeft(encodedText, key) << endl;
    }
    
    // Using a specific key to decode and then encode to demonstrate the process
    int correctKey = 10;
    string decodedText = shiftLeft(encodedText, correctKey);
    cout << "Correctly Decoded Text: " << decodedText << endl;
    cout << "Re-encoded Text: " << shiftRight(decodedText, correctKey) << endl;
    return 0;
}
