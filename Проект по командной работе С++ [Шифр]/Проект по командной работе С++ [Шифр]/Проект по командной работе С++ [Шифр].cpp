#include <iostream>
#include <string>

using namespace std;

string vigenereCipher(const string& text, const string& key, bool encrypt) {
    string result = "";
    int keyLength = key.length();
    int keyIndex = 0;

    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a'; // Determine base for case
            char keyChar = isupper(key[keyIndex % keyLength]) ? 'A' : 'a'; // Determine base for key character

            // Calculate the shift based on the key character
            int shift = key[keyIndex % keyLength] - keyChar;
            if (!encrypt) {
                shift = -shift; // Reverse shift for decryption
            }

            // Apply the shift
            char encryptedChar = (ch - base + shift + 26) % 26 + base;
            result += encryptedChar;

            keyIndex++; // Move to the next character in the key
        }
        else {
            result += ch; // Non-alphabetic characters remain unchanged
        }
    }

    return result;
}

void getInputAndProcess() {
    string text, key;
    char choice;

    // Input text from the user
    cout << "Enter the text: ";
    getline(cin, text);

    // Input key from the user
    cout << "Enter the key: ";
    getline(cin, key);

    // Input choice for encryption or decryption
    cout << "Do you want to encrypt (e) or decrypt (d)? ";
    cin >> choice;

    // Process based on user choice
    if (choice == 'e' || choice == 'E') {
        string encryptedText = vigenereCipher(text, key, true);
        cout << "Encrypted text: " << encryptedText << endl;
    }
    else if (choice == 'd' || choice == 'D') {
        string decryptedText = vigenereCipher(text, key, false);
        cout << "Decrypted text: " << decryptedText << endl;
    }
    else {
        cout << "Invalid choice. Please enter 'e' for encrypt or 'd' for decrypt." << endl;
    }
}

int letterToNumber(char ch) {
    if (isupper(ch)) {
        return ch - 'A' + 1; // A=1, B=2, ..., Z=26
    }
    else if (islower(ch)) {
        return ch - 'a' + 1; // a=1, b=2, ..., z=26
    }
    return -1; // Return -1 for non-alphabetic characters
}

char numberToLetter(int num, bool isUpper) {
    if (num < 1 || num > 26) {
        return ' '; // Return space for out of range
    }
    return isUpper ? char(num - 1 + 'A') : char(num - 1 + 'a');
}

string caesarCiphertwoo(const string& text, int shift) {
    string encryptedText = "";

    // Iterate through each character in the text
    for (char ch : text) {
        int num = letterToNumber(ch);

        if (num != -1) { // If the character is a letter
            // Apply the shift
            num = (num + shift - 1) % 26 + 1;

            // Convert back to letter
            encryptedText += numberToLetter(num, isupper(ch));
        }
        else {
            // Non-alphabetic characters remain unchanged
            encryptedText += ch;
        }
    }

    return encryptedText;
}

string getInputAndEncrypt() {
    string text;
    int shift;

    // Input text from the user
    cout << "Enter the text to encrypt: ";
    cin >> shift;

    // Input shift value from the user
    cout << "Enter the shift value (1-25): ";
    cin >> shift;

    // Ensure shift is within the valid range
    if (shift < 1 || shift > 25) {
        cout << "Shift value must be between 1 and 25." << endl;
        exit(1); // Exit if the shift value is invalid
    }

    // Encrypt the text using Caesar cipher
    return caesarCiphertwoo(text, shift);
}

string caesarCipher(const string& text, int shift) {
    string encryptedText = "";

    // Iterate through each character in the text
    for (char ch : text) {
        // Check if the character is an uppercase letter
        if (isupper(ch)) {
            // Shift within the range of uppercase letters
            encryptedText += char(int(ch + shift - 'A') % 26 + 'A');
        }
        // Check if the character is a lowercase letter
        else if (islower(ch)) {
            // Shift within the range of lowercase letters
            encryptedText += char(int(ch + shift - 'a') % 26 + 'a');
        }
        else {
            // Non-alphabetic characters remain unchanged
            encryptedText += ch;
        }
    }

    return encryptedText;
}

int UserUseMenu() {

    int userInput;

    do {
        cout << "-------------------------------------" << endl;
        cout << "Application to encrypt Caesar's words" << endl;
        cout << "-------------------------------------" << endl;

        cout << "Choose what you want to do" << endl;

        cout << "1. Encrypt using the Caesar method\n" // Encryption is Caesar;
             << "2. More complex encryption [Letters to numbers]\n"
             << "3. Encryption of Viginaire's words\n"
             << "4. Exit\n";

        cout << "Add: ";
        cin >> userInput;

        if (userInput == 1) {

            string text;
            int shift;

            // Input text from the user
            cout << "Enter the text to encrypt: ";
            cin >> text;

            // Input shift value from the user
            cout << "Enter the shift value (1-25): ";
            cin >> shift;

            // Ensure shift is within the valid range
            if (shift < 1 || shift > 25) {
                cout << "Shift value must be between 1 and 25." << endl;
                return 1;
            }

            string encryptedText = caesarCipher(text, shift);
            cout << "Encrypted text: " << encryptedText << endl;

        }
        else if (userInput == 2) {
            string encryptedText = getInputAndEncrypt();
            cout << "Encrypted text: " << encryptedText << endl;
        }
        else if (userInput == 3) {
            getInputAndProcess();
        } 
        else {
            cout << "Thank you for using the application" << endl;
        }

    } while (userInput != 4);

}

int main()
{
    int output = UserUseMenu();

    cout << output;
}

