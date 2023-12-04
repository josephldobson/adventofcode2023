#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>
#include <cmath>


int valueOfLine(std::string line) {
    std::string part1 = line.substr(line.find(":") + 2, line.find("|") - line.find(":") - 2);
    std::string part2 = line.substr(line.find("|") + 2);

    std::vector<int> nums_a, nums_b;
    std::stringstream ss1(part1), ss2(part2);
    int number;

    while (ss1 >> number) {
        nums_a.push_back(number);
    }

    while (ss2 >> number) {
        nums_b.push_back(number);
    }

    int value = -1;

    for (size_t i = 0; i < nums_a.size(); ++i) {
        if (std::find(nums_b.begin(), nums_b.end(), nums_a[i]) != nums_b.end()) {
            value += 1;
        }
    }

    if (value == -1) {
        return 0;
    } else {
        return std::pow(2, value);
    }
}


void partOne() {
    std::ifstream file("data/day04_data.txt");
    std::string data;

    if (file) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        data = buffer.str();
    }

    int total = 0;

    std::istringstream iss(data);
    std::string line;

    while (std::getline(iss, line)) {
        total += valueOfLine(line);
    }

    std::cout << total << std::endl;
}


void partTwo() {
    std::ifstream file("data/day04_data.txt");
    std::string data;

    if (file) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        data = buffer.str();
    }

    int total = 0;

    std::istringstream iss(data);
    std::string line;

    while (std::getline(iss, line)) {
        total += valueOfLine(line);
    }

    std::cout << total << std::endl;
}


int main() {
    partOne();
}