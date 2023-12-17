#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

int firstpart() {
    int sum{};

    std::ifstream file;
    file.open("data/dataDay1.txt");
    std::string cL;
    while (std::getline(file, cL)) {
        int firstDigit{};
        int lastDigit{};


        // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
        for (const auto x: cL) {
            if (std::isdigit(x)) {
                firstDigit = x - '0';
                break;
            }
        }
        std::ranges::reverse(cL);

        for (const auto x: cL) {
            if (std::isdigit(x)) {
                lastDigit = x - '0';
                break;
            }
        }
        sum += firstDigit * 10 + lastDigit;
    }

    return sum;
}

int returnDigitInLetters(const std::string& text) {
    if (text == "one") return 1;
    if (text == "two") return 2;
    if (text == "three") return 3;
    if (text == "four") return 4;
    if (text == "five") return 5;
    if (text == "six") return 6;
    if (text == "seven") return 7;
    if (text == "eight") return 8;
    if (text == "nine") return 9;
    return 0;
}

int secondpart() {
    int sum{};

    std::ifstream file;
    file.open("data/dataDay1.txt");
    std::string cL;
    while (std::getline(file, cL)) {
        int firstDigit{};
        int lastDigit{};

        for (int i{0}; i < cL.length(); i++) {
            if (std::isdigit(cL[i])) {
                firstDigit = cL[i] - '0';
                break;
            }

            if (i + 2 < cL.length()) {
                const int dig{returnDigitInLetters(cL.substr(i, 3))};
                if (dig != 0) {
                    firstDigit = dig;
                    break;
                }
            }

            if (i + 3 < cL.length()) {
                const int dig{returnDigitInLetters(cL.substr(i, 4))};
                if (dig != 0) {
                    firstDigit = dig;
                    break;
                }
            }

            if (i + 4 < cL.length()) {
                const int dig{returnDigitInLetters(cL.substr(i, 5))};
                if (dig != 0) {
                    firstDigit = dig;
                    break;
                }
            }
        }

        for (int i{static_cast<int>(cL.length()) - 1}; i >= 0; i--) {
            if (std::isdigit(cL[i])) {
                lastDigit = cL[i] - '0';
                break;
            }

            if (i - 2 >= 0) {
                const int dig{returnDigitInLetters(cL.substr(i - 2, 3))};
                if (dig != 0) {
                    lastDigit = dig;
                    break;
                }
            }

            if (i - 3 >= 0) {
                const int dig{returnDigitInLetters(cL.substr(i - 3, 4))};
                if (dig != 0) {
                    lastDigit = dig;
                    break;
                }
            }

            if (i - 4 >= 0) {
                const int dig{returnDigitInLetters(cL.substr(i - 4, 5))};
                if (dig != 0) {
                    lastDigit = dig;
                    break;
                }
            }
        }

        sum += firstDigit * 10 + lastDigit;
    }

    return sum;
}

int main() {
    std::cout << "Sum is: " << firstpart() << '\n';
    std::cout << "Sum is: " << secondpart() << '\n';
    return 0;
}
