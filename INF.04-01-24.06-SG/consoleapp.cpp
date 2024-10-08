#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>

void rollDice(int numDice, std::vector<int>& results) {
    results.clear();
    for (int i = 0; i < numDice; ++i) {
        results.push_back(rand() % 6 + 1);
    }
}

int calculatePoints(const std::vector<int>& results) {
    std::map<int, int> counts;
    for (int result : results) {
        counts[result]++;
    }
    int points = 0;
    for (const auto& pair : counts) {
        if (pair.second >= 2) {
            points += pair.first * pair.second;
        }
    }
    return points;
}

int main() {
    srand(time(0));
    char playAgain;
    do {
        int numDice;
        do {
            std::cout << "Podaj liczbe kostek (3-10): ";
            std::cin >> numDice;
        } while (numDice < 3 || numDice > 10);

        std::vector<int> results;
        rollDice(numDice, results);

        std::cout << "Wyniki rzutow:" << std::endl;
        for (size_t i = 0; i < results.size(); ++i) {
            std::cout << "Kostka " << i + 1 << ": " << results[i] << std::endl;
        }

        int points = calculatePoints(results);
        std::cout << "Punkty: " << points << std::endl;

        std::cout << "Czy chcesz zagrac ponownie? (t/n): ";
        std::cin >> playAgain;
    } while (playAgain == 't');

    return 0;
}