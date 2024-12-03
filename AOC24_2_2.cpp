#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

bool isascending(vector<int> nums){
    for (int i=1; i<nums.size(); i++){
        if ((nums[i-1] > nums[i]) || ((nums[i]-nums[i-1]) < 1) || ((nums[i]-nums[i-1]) > 3)){
            return false;
        }
    }
    return true;
}

bool isdescending(vector<int> nums){
    for (int i=1; i<nums.size(); i++){
        if ((nums[i-1] < nums[i]) || ((nums[i-1]-nums[i]) < 1) || ((nums[i-1]-nums[i]) > 3)){
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile){
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }
    string line;
    int fin = 0;
    while (getline(inputFile, line)){
        istringstream iss(line);
        int x;
        vector<int> nums;
        while (iss >> x){
            nums.push_back(x);
        }
        if ((isascending(nums)) || (isdescending(nums))){
            ++fin;
        }
        else{
            vector<int> tempnums;
            for (int i=0; i<nums.size(); i++){
                tempnums.clear();
                for (int j=0; j<nums.size(); j++){
                    if (j != i){
                        tempnums.push_back(nums[j]);
                    }
                }
                if (isascending(tempnums) || isdescending(tempnums)){
                    ++fin;
                    tempnums.clear();
                    break;
                }
            }
            tempnums.clear();
        }
    }
    printf("fin = %d \n", fin);
    inputFile.close();
    return 0;
}
