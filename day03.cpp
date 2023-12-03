// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>


// bool isSymbol(char ch) {
//     return ch != '.' && !isdigit(ch);
// }


// void partOne() {
//     std::ifstream file("data/day01_data.txt");
//     std::string data;

//     if (file) {
//         std::stringstream buffer;
//         buffer << file.rdbuf();
//         data = buffer.str();
//     }

//     std::istringstream iss(data);
//     std::string line;

//     while (std::getline(iss, line)) {

//     }
// }
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


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


int main() {
    std::vector<std::string> schematic;
    std::string line;

    // Read input until an empty line is encountered
    while (std::getline(std::cin, line) && !line.empty()) {
        schematic.push_back(line);
    }

    int sum = 0;
    for (int i = 0; i < schematic.size(); ++i) {
        std::stringstream ss(schematic[i]);
        int number;
        while (ss >> number) {
            if (isAdjacentToSymbol(schematic, i, ss.tellg() - std::to_string(number).length())) {
                sum += number;
            }
        }
    }

    std::cout << "Sum of all part numbers: " << sum << std::endl;

    return 0;
}
