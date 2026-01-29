#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <limits>

enum SectorType { EMPTY, FISH, BOOT };

void task2_fishing() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<SectorType> field(9, EMPTY);

    int fishPos = std::rand() % 9;
    field[fishPos] = FISH;

    int bootsPlaced = 0;
    while (bootsPlaced < 3) {
        int pos = std::rand() % 9;
        if (field[pos] == EMPTY) {
            field[pos] = BOOT;
            bootsPlaced++;
        }
    }

    std::cout << "\nИгра 'Рыбалка'\n";
    std::cout << "Попробуйте поймать рыбу, избегая сапогов.\n";
    std::cout << "Всего 9 секторов (0-8). У вас максимум 9 попыток.\n\n";

    std::vector<bool> opened(9, false);
    int attempts = 0;
    bool gameOver = false;
    bool caughtFish = false;

    while (!gameOver) {
        std::cout << "Текущее поле: ";
        for (int i = 0; i < 9; ++i) {
            if (opened[i]) {
                switch (field[i]) {
                case FISH: std::cout << "[Р] "; break;
                case BOOT: std::cout << "[С] "; break;
                case EMPTY: std::cout << "[ ] "; break;
                }
            }
            else {
                std::cout << "[" << i << "] ";
            }
        }
        std::cout << "\n\n";

        int sector;
        std::cout << "Введите номер сектора (0-8): ";

        while (!(std::cin >> sector) || sector < 0 || sector > 8) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Введите число от 0 до 8: ";
        }

        if (opened[sector]) {
            std::cout << "Этот сектор уже открыт. Выберите другой.\n";
            continue;
        }

        attempts++;
        opened[sector] = true;

        switch (field[sector]) {
        case FISH:
            std::cout << "\nПОЗДРАВЛЯЕМ! Вы поймали рыбу!\n";
            std::cout << "Количество попыток: " << attempts << "\n";
            caughtFish = true;
            gameOver = true;
            break;

        case BOOT:
            std::cout << "\nВы поймали сапог. Игра окончена.\n";
            std::cout << "Попыток сделано: " << attempts << "\n";
            gameOver = true;
            break;

        case EMPTY:
            std::cout << "\nПусто. Продолжайте ловить.\n";

            if (attempts % 3 == 0) {
                int minDist = 10;
                for (int i = 0; i < 9; ++i) {
                    if (!opened[i] && field[i] == FISH) {
                        int dist = abs(i - sector);
                        if (dist < minDist) minDist = dist;
                    }
                }
                if (minDist <= 2) {
                    std::cout << "Подсказка: рыба где-то рядом.\n";
                }
            }
            break;
        }

        if (attempts >= 9 && !gameOver) {
            std::cout << "\nВы использовали все попытки. Игра окончена.\n";
            gameOver = true;
        }
    }

    std::cout << "\nИтоги игры:\n";
    std::cout << "Все поле:\n";
    for (int i = 0; i < 9; ++i) {
        switch (field[i]) {
        case FISH: std::cout << "[Р] "; break;
        case BOOT: std::cout << "[С] "; break;
        case EMPTY: std::cout << "[ ] "; break;
        }
        if ((i + 1) % 3 == 0) std::cout << "\n";
    }

    if (caughtFish) {
        std::cout << "\nВы выиграли! Рыба поймана за " << attempts << " попыток.\n";
    }
    else {
        std::cout << "\nВы проиграли. Рыба так и не поймана.\n";
        std::cout << "Рыба была в секторе: " << fishPos << "\n";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}