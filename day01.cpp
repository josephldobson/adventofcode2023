#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("data/day01_data.txt");
    std::string data;

    if (file) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        data = buffer.str();
    }

    int total = 0;

    std::istringstream iss(data);
    std::string word;

    while (iss >> word) {
        std::string curr;
        char firstDigit = '\0', lastDigit = '\0';

        for (char c : word) {
            if (std::isdigit(c)) {
                if (firstDigit == '\0') {
                    firstDigit = c;
                }
                lastDigit = c;
            }
    }
        curr += firstDigit;
        curr += lastDigit;
        total += std::stoi(curr);
    }

    std::cout << "Total value with string numbers: " << total << std::endl;
    return 0;
}