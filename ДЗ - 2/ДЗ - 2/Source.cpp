#include <iostream>
#include <string>
using namespace std;

/*
* @Author: Valera Leontev
*/

/*
* I create an enum so as
* not to work with
* magic numbers
*/
enum ChoiceUser {
    LineOutput = 1,
    FactorialCalculation,
    CheckingNumberPrimality,
    Exit
};

/*
* A menu function
* that accepts pointers
* to other functions
*/
void menuUser(void (*fooLine)(), int (*fooFactorial)(int numItFactorial), bool (*fooCheckNumber)(int numberPrimality)) {

    /*
    * I create variables
    * to work with them in
    * what will happen in
    * the switch
    */
    int numItFactorial;
    int numberPrimality;
    int userInput;

    do {
        cout << "Choose what you want:" << endl;

        cout << "Line output [1]\n"
            << "Factorial calculation [2]\n"
            << "Checking a number for primality [3]\n"
            << "Exit [4]\n" << endl; //

        cout << "Enter your choice: ";
        cin >> userInput;

        switch (userInput) {

        case LineOutput:

            cout << "You chose Line Output.\n" << endl;
            fooLine();

            break;
        case FactorialCalculation:

            cout << "You chose Factorial Calculation.\n" << endl;

            cout << "Input Factorial Number: ";
            cin >> numItFactorial;

            int result = fooFactorial(numItFactorial);

            if (numItFactorial >= 0) {
                cout << "Factorial of " << numItFactorial << " is " << result << endl;
            }

            break;
        case CheckingNumberPrimality:

            cout << "You chose Checking a Number for Primality.\n" << endl;

            cout << "";
            cin >> numberPrimality;

            if (fooCheckNumber(numberPrimality)) {
                cout << numberPrimality << " is a prime number." << endl;
            }
            else {
                cout << numberPrimality << " is not a prime number." << endl;
            }

            break;
        case Exit:

            cout << "Exiting program." << endl;
            break;
        default:

            cout << "Error: not the right choice" << endl;
            break;
        }
    } while (userInput != Exit); // i know beautiful
}

void fonctionLineOutput() {

    string textOutputItUser;

    cout << "Input text pleas: ";
    cin >> textOutputItUser;

    int numInput;
    cout << "How many times do you want to withdraw it?" << endl;
    cout << "Input: ";
    cin >> numInput;

    for (int i = 0; i < numInput; i++) {
        cout << textOutputItUser << " " << endl;
    }
}

int fonctionFactorialCalculation(int FactorialNumber) {

    if (FactorialNumber < 0) {
        cout << "Error!!!" << endl;
        return 0;
    }

    if (FactorialNumber == 0 || FactorialNumber == 1)
        return 1;

    return FactorialNumber * fonctionFactorialCalculation(FactorialNumber - 1);
}
/*
* It works interesting, but it works.
* I ran it through gpt for testing,
* he didn it understand it himself,
* I decided to do it purely by recursion,
* since I think that it has a faster method
*/
bool fonctionCheckingNumberPrimality(int n, int divisor = 3) { // cringe

    if (n <= 1)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    if (divisor * divisor > n)
        return true;

    if (n % divisor == 0)
        return false;

    return fonctionCheckingNumberPrimality(n, divisor + 2);
}

int main() {
    //here it emphasizes check
    menuUser(fonctionLineOutput, fonctionFactorialCalculation, fonctionCheckingNumberPrimality);

}
