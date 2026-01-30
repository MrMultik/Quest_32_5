#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

template<typename K, typename V>
class KeyValuePair {
private:
    K key;
    V value;

public:
    KeyValuePair(const K& k, const V& v) : key(k), value(v) {}

    K getKey() const { return key; }
    V getValue() const { return value; }

    void print() const {
        cout << key << " -> " << value << "\n";
    }
};

template<typename K, typename V>
class Registry {
private:
    vector<KeyValuePair<K, V>> data;

public:
    void add(const K& key, const V& value) {
        data.push_back(KeyValuePair<K, V>(key, value));
        cout << "Added: ";
        data.back().print();
    }

    void remove(const K& key) {
        int count = 0;
        auto it = data.begin();
        while (it != data.end()) {
            if (it->getKey() == key) {
                it = data.erase(it);
                count++;
            }
            else {
                ++it;
            }
        }
        cout << "Removed: " << count << "\n";
    }

    vector<V> find(const K& key) const {
        vector<V> result;
        for (const auto& item : data) {
            if (item.getKey() == key) {
                result.push_back(item.getValue());
            }
        }
        return result;
    }

    void print() const {
        if (data.empty()) {
            cout << "Empty\n";
            return;
        }

        cout << "Registry:\n";
        for (const auto& item : data) {
            item.print();
        }
    }
};

template<typename K, typename V>
void testRegistry() {
    Registry<K, V> registry;

    while (true) {
        cout << "\n1. Add\n2. Remove\n3. Find\n4. Print\n5. Exit\n";
        cout << "Command: ";

        string cmd;
        cin >> cmd;

        if (cmd == "5" || cmd == "exit") break;

        if (cmd == "1" || cmd == "add") {
            K key;
            V value;

            cout << "Key: ";
            cin >> key;
            cout << "Value: ";
            cin >> value;

            registry.add(key, value);

        }
        else if (cmd == "2" || cmd == "remove") {
            K key;
            cout << "Key: ";
            cin >> key;

            registry.remove(key);

        }
        else if (cmd == "3" || cmd == "find") {
            K key;
            cout << "Key: ";
            cin >> key;

            auto results = registry.find(key);
            cout << "Found: " << results.size() << "\n";
            for (const auto& v : results) {
                cout << v << "\n";
            }

        }
        else if (cmd == "4" || cmd == "print") {
            registry.print();

        }
        else {
            cout << "Unknown\n";
        }

        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void task3() {
    cout << "Registry Test\n";

    int choice;
    do {
        cout << "\n1. int key, string value\n";
        cout << "2. string key, double value\n";
        cout << "3. double key, int value\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            testRegistry<int, string>();
            break;
        case 2:
            testRegistry<string, double>();
            break;
        case 3:
            testRegistry<double, int>();
            break;
        case 4:
            break;
        default:
            cout << "Invalid\n";
        }

    } while (choice != 4);
}