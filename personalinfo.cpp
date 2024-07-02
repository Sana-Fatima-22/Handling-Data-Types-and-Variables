#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    string name;
    int age;
    float salary;
    char repeat;

    do {
        // Prompt for and read name
        cout << "Enter your name: ";
        getline(cin, name);

        // Prompt for and read age with validation
        while (true) {
            cout << "Enter your age: ";
            cin >> age;

            if (cin.fail() || age <= 0) {
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore last input
                cout << "Invalid age. Please enter a positive integer." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear any remaining input
                break;
            }
        }

        // Prompt for and read salary with validation
        while (true) {
            cout << "Enter your salary: ";
            cin >> salary;

            if (cin.fail() || salary < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid salary. Please enter a non-negative number." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear any remaining input
                break;
            }
        }

        // Output the information
        cout << "Hello, " << name << ", you are " << age << " years old and your salary is $" << salary << "." << endl;

        // Ask if the user wants to enter another set of data
        cout << "Do you want to enter another set of data? (y/n): ";
        cin >> repeat;

        // Clear the newline character left in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
