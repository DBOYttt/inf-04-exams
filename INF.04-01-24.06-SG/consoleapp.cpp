#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>

/**
 * Rolls a specified number of dice and stores the results in a vector.
 *
 * @param numDice The number of dice to roll (should be between 3 and 10).
 * @param results A reference to a vector where the rolled results will be stored.
 *                The vector will be cleared before new results are added.
 */

void rollDice(int numDice, std::vector<int>& results) {
    results.clear();
    for (int i = 0; i < numDice; ++i) {
        results.push_back(rand() % 6 + 1);
    }
}

/**
 * Calculates the points based on the rolled dice results.
 * Points are awarded for each unique die value that appears at least twice.
 *
 * @param results A constant reference to a vector containing the results of the dice rolls.
 * @return The total points calculated based on the rolled results.
 */

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
