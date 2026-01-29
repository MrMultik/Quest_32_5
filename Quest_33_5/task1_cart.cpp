#include <iostream>
#include <map>
#include <stdexcept>
#include <limits>
#include <string>

void task1_cart() {
    std::map<std::string, int> warehouse;
    std::map<std::string, int> cart;

    int n;
    std::cout << "Введите количество товаров в магазине: ";
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        std::string name;
        int count;

        std::cout << "Артикул и количество: ";
        std::cin >> name >> count;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        warehouse[name] = count;
        std::cout << "Добавлен товар: " << name << " - " << count << " шт.\n";
    }

    while (true) {
        std::string cmd;
        std::cout << "\nКоманды:\n";
        std::cout << "add    - добавить товар в корзину\n";
        std::cout << "remove - удалить товар из корзины\n";
        std::cout << "cart   - показать корзину\n";
        std::cout << "store  - показать склад\n";
        std::cout << "exit   - выход\n";
        std::cout << "Введите команду: ";
        std::getline(std::cin, cmd);

        if (cmd == "exit") {
            std::cout << "Выход из программы...\n";
            break;
        }

        if (cmd == "cart") {
            std::cout << "\nКорзина:\n";
            if (cart.empty()) {
                std::cout << "Корзина пуста\n";
            }
            else {
                for (auto& p : cart) {
                    std::cout << p.first << " : " << p.second << " шт.\n";
                }
            }
            continue;
        }

        if (cmd == "store") {
            std::cout << "\nСклад:\n";
            for (auto& p : warehouse) {
                std::cout << p.first << " : " << p.second << " шт.\n";
            }
            continue;
        }

        if (cmd == "add" || cmd == "remove") {
            std::string name;
            int count;

            std::cout << "Введите артикул товара: ";
            std::cin >> name;
            std::cout << "Введите количество: ";
            std::cin >> count;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            try {
                if (!warehouse.count(name)) {
                    throw std::invalid_argument("Товар '" + name + "' отсутствует на складе");
                }

                if (cmd == "add") {
                    if (count > warehouse[name]) {
                        throw std::runtime_error("Недостаточно товара на складе. Доступно: " +
                            std::to_string(warehouse[name]) + " шт.");
                    }

                    warehouse[name] -= count;
                    cart[name] += count;
                    std::cout << "Добавлено в корзину: " << name << " - " << count << " шт.\n";
                    std::cout << "Остаток на складе: " << warehouse[name] << " шт.\n";
                }
                else if (cmd == "remove") {
                    if (!cart.count(name)) {
                        throw std::runtime_error("Товар '" + name + "' отсутствует в корзине");
                    }
                    if (count > cart[name]) {
                        throw std::runtime_error("Недостаточно товара в корзине. В корзине: " +
                            std::to_string(cart[name]) + " шт.");
                    }

                    cart[name] -= count;
                    warehouse[name] += count;

                    if (cart[name] == 0) {
                        cart.erase(name);
                    }

                    std::cout << "Удалено из корзины: " << name << " - " << count << " шт.\n";
                    std::cout << "Теперь в корзине: " << (cart.count(name) ? std::to_string(cart[name]) : "0") << " шт.\n";
                }
            }
            catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
        }
        else {
            std::cout << "Неизвестная команда. Попробуйте снова.\n";
        }
    }

    std::cout << "\nИтоговая корзина:\n";
    if (cart.empty()) {
        std::cout << "Корзина пуста\n";
    }
    else {
        for (auto& p : cart) {
            std::cout << p.first << " : " << p.second << " шт.\n";
        }
    }
}