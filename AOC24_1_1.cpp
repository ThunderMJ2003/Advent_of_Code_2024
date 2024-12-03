#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::vector<int> a;
    std::vector<int> b;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int first, second;
        if (iss >> first >> second) {
            a.push_back(first);
            b.push_back(second);
        }
    }

    inputFile.close();

    // Output the contents of the vectors to verify
    // std::cout << "First Numbers: ";
    // for (const auto& num : a) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Second Numbers: ";
    // for (const auto& num : b) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int fin = 0;
    for (int i=0; i<a.size(); i++){
        fin += abs(a[i]-b[i]);
    }
    printf("fin = %d \n", fin);

    return 0;
}
