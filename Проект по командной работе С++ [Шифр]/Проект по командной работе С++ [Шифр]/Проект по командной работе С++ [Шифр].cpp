#include <iostream>

using namespace std;

void UserUseMenu() {

    int userInput;

    do {
        cout << "-------------------------------------" << endl;
        cout << "Application to encrypt Caesar's words" << endl;
        cout << "-------------------------------------" << endl;

        cout << "Choose what you want to do" << endl;

        cout << "1. Encrypt using the Caesar method\n"
             << "2. More complex encryption [Letters to numbers]\n"
             << "3. Encryption of Viginaire's words\n"
             << "4. Exit\n";

        cout << "Add: ";
        cin >> userInput;

        if (userInput == 1) {

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
    UserUseMenu();
}

