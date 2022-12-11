#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream infile("data/day1.txt");
    std::vector<int> cals;
    std::string line;
    int cal = 0;
    
    while(std::getline(infile, line)) {
        if (!line.empty()) {
            cal += std::stoi(line);
        }
        else {
            cals.push_back(cal);
            cal = 0;
        }
    }

    std::sort(cals.begin(), cals.end(), std::greater<int>());

    std::cout << "Max calories: " << std::endl;
    std::cout << "Top 1: " << cals[0] << std::endl;
    std::cout << "Top 2: " << cals[1] << std::endl;
    std::cout << "Top 3: " << cals[2] << std::endl;
    std::cout << "Sum top 3: " << cals[0] + cals[1] + cals[2] << std::endl;

    return 0;
}