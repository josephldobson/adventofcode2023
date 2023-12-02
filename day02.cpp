#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


bool checkIfValid(std::string game) {
    std::istringstream iss(game);
    std::string token;
    int red, green, blue;
    int number;
    std::string color;

    red = green = blue = 0;

    while (iss >> number >> color) {
        if (color == "red," || color == "red") {
            red = number;
        } else if (color == "blue," || color == "blue") {
            blue = number;
        } else if (color == "green," || color == "green") {
            green = number;
        }
    }
    return (red <= 12) && (green <= 13) && (blue <= 14);
}


void partOne () {
    std::ifstream file("data/day02_data.txt");
    std::string data;

    if (file) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        data = buffer.str();
    }

    int total = 0;
    int index = 0;

    std::istringstream iss(data);
    std::string line;

    while (std::getline(iss, line)) {
        index += 1;
        bool line_valid = true;
        size_t colonPos = line.find(':');
        line = line.substr(colonPos + 1);

        std::istringstream iss(line);
        std::string game;

        while (std::getline(iss, game, ';')) {
            line_valid = line_valid && checkIfValid(game);
        }
        if (line_valid) {
            total += index;
        }
    }

    std::cout << "Sum of index values: " << total << std::endl;
}


void findColorValues(const std::string& input, int& red, int& blue, int& green) {
    std::istringstream iss(input);
    int number;
    std::string color;

    red = blue = green = -1;

    while (iss >> number >> color) {
        if (color == "red," || color == "red") {
            red = number;
        } else if (color == "blue," || color == "blue") {
            blue = number;
        } else if (color == "green," || color == "green") {
            green = number;
        }
    }
}


void partTwo () {
    std::ifstream file("data/day02_data.txt");
    std::string data;

    if (file) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        data = buffer.str();
    }

    int total = 0;
    int index = 0;
    int red, blue, green;
    int max_red, max_blue, max_green;

    std::istringstream iss(data);
    std::string line;

    while (std::getline(iss, line)) {
        index += 1;
        max_red = max_green = max_blue = 0;
        size_t colonPos = line.find(':');
        line = line.substr(colonPos + 1);

        std::istringstream iss(line);
        std::string game;

        while (std::getline(iss, game, ';')) {
            findColorValues(game, red, blue, green);
            max_red = std::max(max_red, red);
            max_green = std::max(max_green, green);
            max_blue = std::max(max_blue, blue);
        }
        total += max_red * max_green * max_blue;
    }

    std::cout << "Sum of powers: " << total << std::endl;
}

int main () {
    // partOne();
    partTwo();
}