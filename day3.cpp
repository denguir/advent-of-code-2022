#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <map>


std::tuple<std::string, std::string> split_bag(std::string bag) {
    size_t pos = bag.size() / 2;
    std::string bag1 = bag.substr(0, pos);
    std::string bag2 = bag.substr(pos, std::string::npos);
    return std::make_tuple(bag1, bag2);
}

std::string find_common(std::string bag1, std::string bag2) {
    std::string common = "";
    for (size_t i = 0; i < bag1.size(); ++i) {
        if (bag2.find(bag1[i]) != std::string::npos) {
            common += bag1[i];
        }
    }
    return common;
}

char find_common(std::vector<std::string> bags) {
    std::string common;
    if (bags.empty()) {
        common = "";
    } else {
        common = bags[0];
        for (size_t i = 0; i < bags.size() - 1; ++i) {
            common = find_common(common, bags[i+1]);
        }
    }
    return common[0];
}

int main() {
    std::ifstream infile("data/day3.txt");
    std::map<char, int> priority_map;
    std::vector<std::string> bags;
    std::string line;
    char c;
    int i = 1;
    int priority = 0;

    for (int i = 0; i < 26; ++i) {
        priority_map['a' + i] = 1 + i;
        priority_map['A' + i] = 27 + i;
    }

    while (std::getline(infile, line)) {
        bags.push_back(line);
        if (i % 3 == 0) {
            c = find_common(bags);
            priority += priority_map[c];
            bags.clear();
        }
        ++i;
    }
    std::cout << "Total priority: " << priority << std::endl;
    return 0;
}