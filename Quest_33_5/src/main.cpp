#include <iostream>
#include <locale>
#include <limits>  // для std::numeric_limits

void task1_cart();
void task2_fishing();
void task3_registry();
void task4_average();

int main() {
    int choice;

    do {
        std::cout << "Практическая работа 33.5\n";
        std::cout << "1 — Корзина магазина\n";
        std::cout << "2 — Игра Рыбалка\n";
        std::cout << "3 — Реестр (шаблоны)\n";
        std::cout << "4 — Среднее арифметическое\n";
        std::cout << "0 — Выход\n";
        std::cout << "Выберите задание: ";

        // Проверка ввода
        if (!(std::cin >> choice)) {
            std::cin.clear(); // сброс флагов ошибок
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера
            std::cout << "Неверный ввод! Пожалуйста, введите число.\n";
            continue;
        }

        if (choice == 0) {
            std::cout << "Завершение программы...\n";
            break;
        }

            switch (choice) {
            case 1:
                task1_cart();
                break;
            case 2:
                task2_fishing();
                break;
            case 3:
                task3_registry();
                break;
            case 4:
                task4_average();
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

        // Ожидание нажатия Enter перед возвратом в меню
        if (choice >= 1 && choice <= 4) {
            std::cout << "\nНажмите Enter для возврата в меню...";
            std::cin.ignore(); // игнорируем оставшийся символ новой строки
            std::cin.get();    // ждем нажатия Enter
        }

    } while (true);  // бесконечный цикл, пока не выберем 0

    return 0;
}