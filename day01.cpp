#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>

// This function is too hard to write - my c++ isnt good enough, im going to try a different approach

// std::string extractAndReplaceNumbers(std::string str) {
//     std::vector<std::pair<std::string, char>> numberWords = {
//         {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'},
//         {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'},
//         {"eight", '8'}, {"nine", '9'}
//     };

//     std::string result;

//     for (size_t i = 0; i < str.length(); ++i) {
//         if (isdigit(str[i])) {
//             result += str[i];
//             continue;
//         }

//         bool found = false;
//         for (const auto& pair : numberWords) {
//             const std::string& word = pair.first;
//             const char& digit = pair.second;

//             if (str.substr(i, word.length()) == word) {
//                 result += digit;
//                 i += word.length() - 1;
//                 found = true;
//                 break;
//             }
//         }

//         if (!found && isdigit(str[i])) {
//             result += str[i];
//         }
//     }

//     return result;
// }

// // int main() {
// //     std::string test_word = "onedgs2hj4sf";
// //     test_word = extractAndReplaceNumbers(test_word);
// //     std::cout << test_word << std::endl;
// // }

// int main() {
//     std::ifstream file("data/day01_data.txt");
//     std::string data;

//     if (file) {
//         std::stringstream buffer;
//         buffer << file.rdbuf();
//         data = buffer.str();
//     }

//     int total = 0;

//     std::istringstream iss(data);
//     std::string word;

//     while (iss >> word) {
//         char firstDigit = '\0', lastDigit = '\0';
//         word = extractAndReplaceNumbers(word);
//         std::cout << word << std::endl;

//         for (char c : word) {
//             if (firstDigit == '\0') {
//                 firstDigit = c;
//             }
//             lastDigit = c;

//     }
//         std::string curr;
//         curr += firstDigit;
//         curr += lastDigit;
//         total += std::stoi(curr);
//     }

//     std::cout << "Total value with string numbers: " << total << std::endl;
//     return 0;
// }

int getNumberWordDigit(const std::string& str, size_t pos) {
    std::vector<std::pair<std::string, int>> numberWords = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3},
        {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7},
        {"eight", 8}, {"nine", 9}
    };

    for (const auto& pair : numberWords) {
        if (str.substr(pos, pair.first.length()) == pair.first) {
            return pair.second;
        }
    }
    return -1;
}

int findFirstNumber(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (isdigit(str[i])) {
            return str[i] - '0';
        }

        int num = getNumberWordDigit(str, i);
        if (num != -1) {
            return num;
        }
    }
    return -1;
}

int findLastNumber(const std::string& str) {
    int lastNumber = -1;

    for (size_t i = 0; i < str.length(); ++i) {
        if (isdigit(str[i])) {
            lastNumber = str[i] - '0';
        } else {
            int num = getNumberWordDigit(str, i);
            if (num != -1) {
                lastNumber = num;
                i += std::to_string(num).length() - 1;
            }
        }
    }
    return lastNumber;
}

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
        int firstDigit = findFirstNumber(word), lastDigit = findLastNumber(word);

        total += 10*firstDigit + lastDigit;
    }

    std::cout << "Total value with string numbers: " << total << std::endl;
    return 0;
}