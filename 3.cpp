#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

int main() {
    int numberOfElements;
    std::cin >> numberOfElements;
    std::cin.ignore();

    std::string inputLine;
    std::getline(std::cin, inputLine);
    
    std::istringstream inputStream(inputLine);
    std::vector<int> arrayElements;
    int element;
    
    while (inputStream >> element) {
        arrayElements.push_back(element);
        if (arrayElements.size() >= numberOfElements * 2) {
            break;
        }
    }

    if (arrayElements.size() > numberOfElements * 2) {
        arrayElements.pop_back();
    }

    int totalSum = 0;
    for (const int& num : arrayElements) {
        totalSum += num;
    }

    int length = static_cast<int>(totalSum / static_cast<double>(arrayElements.size()) * 2);
    std::cout << length << std::endl;

    std::unordered_set<int> addedElements;
    
    for (size_t i = 0; i < arrayElements.size(); ++i) {
        for (size_t j = 0; j < arrayElements.size(); ++j) {
            if (i != j && arrayElements[i] + arrayElements[j] == length) {
                if (addedElements.find(arrayElements[i]) == addedElements.end() &&
                    addedElements.find(arrayElements[j]) == addedElements.end()) {
                    std::cout << i + 1 << " " << j + 1 << std::endl;
                    addedElements.insert(arrayElements[i]);
                    addedElements.insert(arrayElements[j]);
                    break;
                }
            }
        }
    }

    return 0;
}
