#include <iostream>
#include <fstream>


int get_shape_score(char play) {
    int score = 0;
    if (play == 'A' || play == 'X') {
        score = 1;        
    } else if (play == 'B' || play == 'Y') 
    {
        score = 2;
    } else if (play == 'C' || play == 'Z')
    {
        score = 3;
    }
    return score;
}

int get_score(char pA, char pB) {
    int score = 0;
    char shape;
    if (pB == 'X') {
        shape = (pA == 'A') ? 'C' : pA - 1;
    } else if (pB == 'Y') {
        score += 3;
        shape = pA;
    } else if (pB == 'Z') {
        score += 6;
        shape = (pA == 'C') ? 'A' : pA + 1;
    }
    score += get_shape_score(shape);
    return score;
}


int main() {
    std::ifstream infile("data/day2.txt");
    std::string line;
    char pA, pB;
    int score = 0;

    while(infile >> pA >> pB) {
        score += get_score(pA, pB);
    }

    std::cout << "Total score: " << score << std::endl;
}