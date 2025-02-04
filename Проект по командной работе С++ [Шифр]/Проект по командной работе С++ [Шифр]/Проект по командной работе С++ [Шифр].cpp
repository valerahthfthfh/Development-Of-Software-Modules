#include <iostream>
#include <string>

using namespace std;

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

        }
        else if (userInput == 3) {

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

