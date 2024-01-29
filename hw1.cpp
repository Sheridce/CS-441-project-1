#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <map>


int main (int argc, char *argv[]){
    std::ifstream file;
    int statesNum;
    int initialState;
    int currentState;
    char currentChar;
    std::string dummy;
    std::vector <int> finalStates;
    std::vector <int>::iterator it;
    std::string alphabet;
    std::vector <std::vector<int>> transitions;
    std::vector <int> tempVec;
    std::string testStr;
    bool isEOF = false;
    bool isValid;
    file.open(argv[1]);
    assert(file.is_open());
    file >> statesNum;
    file >> initialState;
    int currentInt;
    while (file >> currentInt){
        finalStates.push_back(currentInt);
        if (file.peek() == '\n'){
            break;
        }
    }
    getline(file, dummy);
    file >> alphabet;
    for (int i = 0; i < statesNum; i++){
        while (file >> currentInt){
            tempVec.push_back(currentInt);
            if (file.peek() == '\n'){
                break;
            }
        }
        getline(file, dummy);
        transitions.push_back(tempVec);
        tempVec.clear();
    }
    while (!isEOF){
        isValid = false;
        std::getline(file, testStr);
        if (file.peek(), file.eof()){
            isEOF = true;
        }
        currentState = initialState-1;
        for (int i = 0; i < testStr.length(); i++){
            currentChar = testStr[i];
            currentInt = alphabet.find(currentChar);
            currentState = transitions[currentState][currentInt]-1;
            if (currentState < 0){
                break;
            }

        }

        for (int i = 0; i < finalStates.size(); i++){
            if ((currentState+1) == finalStates[i]){
                isValid = true;
                break;
            }
        }
        if (isValid){
            if (testStr.empty()){
                std::cout<<"good <empty>"<<std::endl;
            }
            else{
                std::cout<<"good "<<testStr<<std::endl;
            }
        }
        else{
            if (testStr.empty()){
                std::cout<<"bad  <empty>"<<std::endl;
            }
            else{
            std::cout<<"bad  "<<testStr<<std::endl;
            }
        }

    }
}
