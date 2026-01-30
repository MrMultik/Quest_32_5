#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <vector>
#include <limits>

using namespace std;

class FishCaught : public exception {
private:
    int attempts;
public:
    FishCaught(int attempts) : attempts(attempts) {}

    const char* what() const noexcept override {
        return "Fish caught!";
    }

    int getAttempts() const { return attempts; }
};

class BootCaught : public exception {
public:
    const char* what() const noexcept override {
        return "Caught a boot!";
    }
};

class FishingGame {
private:
    vector<string> field;
    int fishPosition;
    vector<int> bootPositions;
    int attempts;

public:
    FishingGame() : attempts(0) {
        field.resize(9, "empty");

        srand(static_cast<unsigned>(time(nullptr)));

        fishPosition = rand() % 9;
        field[fishPosition] = "fish";

        bootPositions.clear();
        for (int i = 0; i < 3; i++) {
            int pos;
            do {
                pos = rand() % 9;
            } while (field[pos] != "empty");

            bootPositions.push_back(pos);
            field[pos] = "boot";
        }
    }

    void castRod(int sector) {
        if (sector < 1 || sector > 9) {
            throw invalid_argument("Sector 1-9 only");
        }

        int index = sector - 1;
        attempts++;

        cout << "Sector " << sector << ": ";

        if (index == fishPosition) {
            cout << "Fish!\n";
            throw FishCaught(attempts);
        }

        for (int bootPos : bootPositions) {
            if (index == bootPos) {
                cout << "Boot!\n";
                throw BootCaught();
            }
        }

        cout << "Empty\n";
    }

    void showField() const {
        cout << "\nField:\n";
        for (int i = 0; i < 9; i++) {
            cout << "Sector " << (i + 1) << ": ";
            if (field[i] == "fish" || field[i] == "boot") {
                cout << "[?]";
            }
            else {
                cout << "empty";
            }
            cout << "\n";
        }
    }
};

void task2() {
    cout << "Fishing Game\n";
    cout << "Catch fish, avoid boots\n";

    FishingGame game;

    while (true) {
        try {
            game.showField();

            int sector;
            cout << "\nSector (1-9): ";
            cin >> sector;

            game.castRod(sector);

        }
        catch (const FishCaught& e) {
            cout << e.what() << "\n";
            cout << "Attempts: " << e.getAttempts() << "\n";
            cout << "Game over!\n";
            break;

        }
        catch (const BootCaught& e) {
            cout << e.what() << "\n";
            cout << "Game over!\n";
            break;

        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
        }

        cin.clear();
        cin.ignore(10000, '\n');
    }
}