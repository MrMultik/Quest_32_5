#include <iostream>
#include <limits>

using namespace std;

void task1();
void task2();
void task3();
void task4();

int main() {
    int choice;

    do {
        cout << "\nPractice Work 33.5\n";
        cout << "Select task to execute:\n";
        cout << "1. Shopping Cart\n";
        cout << "2. Fishing Game\n";
        cout << "3. Registry\n";
        cout << "4. Average Calculator\n";
        cout << "5. Exit Program\n";
        cout << "\nEnter your choice (1-5): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number 1-5.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\nTask 1: Shopping Cart\n";
            task1();
            cout << "\nReturning to main menu...\n";
            break;
        case 2:
            cout << "\nTask 2: Fishing Game\n";
            task2();
            cout << "\nReturning to main menu...\n";
            break;
        case 3:
            cout << "\nTask 3: Registry\n";
            task3();
            cout << "\nReturning to main menu...\n";
            break;
        case 4:
            cout << "\nTask 4: Average Calculator\n";
            task4();
            cout << "\nReturning to main menu...\n";
            break;
        case 5:
            cout << "\nExiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number 1-5.\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice != 5);

    return 0;
}