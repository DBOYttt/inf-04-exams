#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>
#include <stdexcept>

class Album {
public:
    std::string artist;
    std::string album;
    int songsNumber;
    int year;
    int64_t downloadNumber;

    Album(std::string artist, std::string album, int songsNumber, int year, int64_t downloadNumber)
        : artist(artist), album(album), songsNumber(songsNumber), year(year), downloadNumber(downloadNumber) {}

    void display() const {
        std::cout << "Artist: " << artist << "\n"
                  << "Album: " << album << "\n"
                  << "Songs Number: " << songsNumber << "\n"
                  << "Year: " << year << "\n"
                  << "Download Number: " << downloadNumber << "\n\n";
    }
};

std::vector<Album> readData(const std::string& filename) {
    std::vector<Album> albums;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + filename);
    }

    std::string artist, album;
    int songsNumber, year;
    int64_t downloadNumber;

    while (file >> artist >> album >> songsNumber >> year >> downloadNumber) {
        albums.emplace_back(artist, album, songsNumber, year, downloadNumber);
    }

    return albums;
}

void displayData(const std::vector<Album>& albums) {
    for (const auto& album : albums) {
        album.display();
    }
}

int main() {
    std::string filename = "Data.txt";
    try {
        std::vector<Album> albums = readData(filename);
        displayData(albums);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}