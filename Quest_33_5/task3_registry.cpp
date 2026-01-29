#include <iostream>
#include <vector>
#include <string>

template<typename K, typename V>
struct Entry {
    K key;
    V value;
};

template<typename K, typename V>
class Registry {
    std::vector<Entry<K, V>> data;
public:
    void add(K key, V value) {
        data.push_back({ key, value });
    }

    void remove(K key) {
        data.erase(
            std::remove_if(data.begin(), data.end(),
                [&](Entry<K, V>& e) { return e.key == key; }),
            data.end());
    }

    void print() const {
        for (auto& e : data)
            std::cout << e.key << " : " << e.value << std::endl;
    }

    void find(K key) const {
        for (auto& e : data)
            if (e.key == key)
                std::cout << e.value << std::endl;
    }
};

void task3_registry() {
    Registry<std::string, std::string> reg;

    reg.add("id1", "value1");
    reg.add("id1", "value2");
    reg.add("id2", "value3");

    reg.print();
    std::cout << "Поиск id1:\n";
    reg.find("id1");
}