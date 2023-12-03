#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

bool isSymbol(char ch) {
    return ch != '.' && !isdigit(ch);
}

bool isAdjacentToSymbol(const std::vector<std::string>& schematic, int x, int y) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < schematic.size() && newY >= 0 && newY < schematic[0].size()) {
                if (isSymbol(schematic[newX][newY])) {
                    return true;
                }
            }
        }
    }
    return false;
}

void partOne() {
    std::ifstream file("data/day03_data.txt");
    std::string data;

    if (file) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        data = buffer.str();
    }

    std::istringstream iss(data);
    std::string line;
    std::vector<std::string> schematic;

    while (std::getline(iss, line)) {
        schematic.push_back(line);
    }

    std::string number;
    char curr_char;
    int sum = 0;
    for (int i = 0; i < schematic.size(); ++i) {
        for (int j = 0; j < schematic[i].size(); ++j) {
            curr_char = schematic[i][j];
            
            if (isdigit(curr_char) ) {
                number = number + curr_char;
                if (isAdjacentToSymbol(schematic, i, j)) {
                    j += 1;
                    if (j < schematic[i].size()) {
                        curr_char = schematic[i][j];
                        while (isdigit(curr_char) && j < schematic[i].size()) {
                            number = number + curr_char;
                            j += 1;
                            curr_char = schematic[i][j];
                        }
                        std::cout << number << std::endl;
                        sum += stoi(number);
                        number = "";
                    }

                }
            } else {
                number = "";
            }
        }
    }

    std::cout << "Sum of all part numbers: " << sum << std::endl;
}

int main() {
    partOne();
}