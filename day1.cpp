#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <fstream>


int main() {
	bool cont{true};
	int sum{};
	
	std::ifstream file;
	file.open("data/dataDay1.txt");

	std::string cL;
	while(std::getline(file, cL)) {
		std::cout << "line: " << cL << '\n';

		int firstDigit{};
		int lastDigit{};


// https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
		for (auto x : cL) {
			if (std::isdigit(x)) {
				firstDigit = x  - '0';
				break;
			}
		}
		
	std::cout << "First digit: " << firstDigit;

		std::reverse(cL.begin(), cL.end());

		for (auto x : cL) {
			if (std::isdigit(x)) {
				lastDigit = x - '0';
				break;
			}
		}
		
		std::cout << '\n';
		std::cout << firstDigit << ' ' << lastDigit << '\n';

		sum += firstDigit*10 + lastDigit;
	}

	std::cout << "Sum is: " << sum;
	return 0;
	
}
