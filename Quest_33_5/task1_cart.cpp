#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

class OnlineStore {
private:
    map<string, int> database;
    map<string, int> cart;

public:
    void addToDatabase(const string& article, int quantity) {
        if (quantity <= 0) {
            throw invalid_argument("Quantity must be positive");
        }
        database[article] = quantity;
    }

    void addToCart(const string& article, int quantity) {
        if (database.find(article) == database.end()) {
            throw invalid_argument("Product not found in database");
        }

        if (quantity <= 0) {
            throw invalid_argument("Quantity must be positive");
        }

        int available = database[article];
        int inCart = (cart.find(article) != cart.end()) ? cart[article] : 0;

        if (quantity > available) {
            throw runtime_error("Not enough product in stock");
        }

        cart[article] = inCart + quantity;
        cout << "Added " << quantity << " items to cart\n";
    }

    void removeFromCart(const string& article, int quantity) {
        if (cart.find(article) == cart.end()) {
            throw invalid_argument("Product not in cart");
        }

        if (quantity <= 0) {
            throw invalid_argument("Quantity must be positive");
        }

        if (quantity > cart[article]) {
            throw runtime_error("Cannot remove more than in cart");
        }

        cart[article] -= quantity;

        if (cart[article] == 0) {
            cart.erase(article);
        }

        cout << "Removed " << quantity << " items from cart\n";
    }

    void showCart() const {
        if (cart.empty()) {
            cout << "Cart is empty\n";
            return;
        }

        cout << "Cart contents:\n";
        for (const auto& item : cart) {
            cout << "Article: " << item.first
                << ", Quantity: " << item.second << "\n";
        }
    }

    void showDatabase() const {
        cout << "Store database:\n";
        for (const auto& item : database) {
            cout << "Article: " << item.first
                << ", In stock: " << item.second << "\n";
        }
    }
};

void task1() {
    OnlineStore store;

    cout << "Filling store database\n";
    cout << "Enter number of products to add: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        try {
            string article;
            int quantity;

            cout << "Product " << i + 1 << ":\n";
            cout << "Article: ";
            cin >> article;
            cout << "Quantity: ";
            cin >> quantity;

            store.addToDatabase(article, quantity);
            cout << "Product added\n";
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            i--;
        }
    }

    cout << "Working with cart\n";
    while (true) {
        try {
            cout << "\nSelect operation:\n";
            cout << "1. Add product to cart\n";
            cout << "2. Remove product from cart\n";
            cout << "3. Show cart\n";
            cout << "4. Show database\n";
            cout << "5. Return to main menu\n";
            cout << "Your choice: ";

            int choice;
            cin >> choice;

            if (choice == 5) break;

            switch (choice) {
            case 1: {
                string article;
                int quantity;

                cout << "Article: ";
                cin >> article;
                cout << "Quantity: ";
                cin >> quantity;

                store.addToCart(article, quantity);
                break;
            }
            case 2: {
                string article;
                int quantity;

                cout << "Article: ";
                cin >> article;
                cout << "Quantity: ";
                cin >> quantity;

                store.removeFromCart(article, quantity);
                break;
            }
            case 3:
                store.showCart();
                break;
            case 4:
                store.showDatabase();
                break;
            default:
                cout << "Invalid choice\n";
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}