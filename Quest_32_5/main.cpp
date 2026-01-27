#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main() {
    cout << "=== Movie Database Search ===" << endl;

    // Try to open the file
    ifstream file("movies.json");
    if (!file.is_open()) {
        cout << "Error: movies.json not found!" << endl;
        cout << "Creating sample database..." << endl;

        // Create sample file
        ofstream create("movies.json");
        create << R"({
  "Interstellar": {"country":"USA","year":2014,"cast":[{"character":"Cooper","actor":"Matthew McConaughey"}]},
  "Inception": {"country":"USA","year":2010,"cast":[{"character":"Cobb","actor":"Leonardo DiCaprio"}]},
  "Titanic": {"country":"USA","year":1997,"cast":[{"character":"Jack","actor":"Leonardo DiCaprio"}]}
})";
        create.close();

        // Try again
        file.open("movies.json");
        if (!file) {
            cout << "Failed to create file." << endl;
            return 1;
        }
    }

    json data;
    file >> data;
    file.close();

    cout << "Database loaded: " << data.size() << " movies" << endl;

    // Show available movies
    cout << "\nAvailable movies:" << endl;
    for (auto& [movie, info] : data.items()) {
        cout << " - " << movie << " (" << info["year"] << ")" << endl;
    }

    // Search
    cout << "\nEnter actor name: ";
    string name;
    getline(cin, name);

    bool found = false;

    cout << "\nSearch results for \"" << name << "\":" << endl;
    cout << "----------------------------" << endl;

    for (auto& [movie, info] : data.items()) {
        for (auto& role : info["cast"]) {
            string actor = role["actor"];

            // Case-insensitive search
            string actor_lower = actor;
            string name_lower = name;

            for (char& c : actor_lower) c = tolower(c);
            for (char& c : name_lower) c = tolower(c);

            if (actor_lower.find(name_lower) != string::npos) {
                cout << "Movie: " << movie << endl;
                cout << "  Character: " << role["character"] << endl;
                cout << "  Actor: " << actor << endl;
                cout << "  Year: " << info["year"] << endl;
                cout << "  Country: " << info["country"] << endl;
                cout << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Actor not found." << endl;
        cout << "\nTry: Leonardo, Matthew, Tom, Kate, Christian" << endl;
    }

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}