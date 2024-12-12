#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile){
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }
    string line;
    int a, b;
    int fin = 0;
    while (getline(inputFile, line)){
        for (int i=0; line[i]!='\0'; i++){
            if (line.substr(i, 4) == "mul("){
                i += 4;
                if (isdigit(line[i]) && (line[i+1]==',')){
                    a = line[i]-'0';
                    i += 2;
                    if (isdigit(line[i]) && (line[i+1]==')')){
                        b = line[i]-'0';
                        fin += (a*b);
                    }
                    else if (isdigit(line[i]) && isdigit(line[i+1]) && (line[i+2]==')')){
                        b = (line[i]-'0')*10 + (line[i+1]-'0');
                        fin += (a*b);
                    }
                    else if (isdigit(line[i]) && isdigit(line[i+1]) && isdigit(line[i+2]) && (line[i+3]==')')){
                        b = (line[i]-'0')*100 + (line[i+1]-'0')*10 + (line[i+2]-'0');
                        fin += (a*b);
                    }
                }
                else if (isdigit(line[i]) && isdigit(line[i+1]) && (line[i+2]==',')){
                    a = (line[i]-'0')*10 + (line[i+1]-'0');
                    i += 3;
                    if (isdigit(line[i]) && (line[i+1]==')')){
                        b = line[i]-'0';
                        fin += (a*b);
                    }
                    else if (isdigit(line[i]) && isdigit(line[i+1]) && (line[i+2]==')')){
                        b = (line[i]-'0')*10 + (line[i+1]-'0');
                        fin += (a*b);
                    }
                    else if (isdigit(line[i]) && isdigit(line[i+1]) && isdigit(line[i+2]) && (line[i+3]==')')){
                        b = (line[i]-'0')*100 + (line[i+1]-'0')*10 + (line[i+2]-'0');
                        fin += (a*b);
                    }
                }
                else if (isdigit(line[i]) && isdigit(line[i+1]) && isdigit(line[i+2]) && (line[i+3]==',')){
                    a = (line[i]-'0')*100 + (line[i+1]-'0')*10 + (line[i+2]-'0');;
                    i += 4;
                    if (isdigit(line[i]) && (line[i+1]==')')){
                        b = line[i]-'0';
                        fin += (a*b);
                    }
                    else if (isdigit(line[i]) && isdigit(line[i+1]) && (line[i+2]==')')){
                        b = (line[i]-'0')*10 + (line[i+1]-'0');
                        fin += (a*b);
                    }
                    else if (isdigit(line[i]) && isdigit(line[i+1]) && isdigit(line[i+2]) && (line[i+3]==')')){
                        b = (line[i]-'0')*100 + (line[i+1]-'0')*10 + (line[i+2]-'0');
                        fin += (a*b);
                    }
                }
            }
        }
        printf("fin = %d \n", fin);
    }
    inputFile.close();
    return 0;
}
