#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Student_Score {
    private:
        int scores[5];
    public:
        void input(int arr[]){
            for(int i = 0; i < 5; i++){
                scores[i] = arr[i];
            }
        }
        
        int calculateTotalScore(){
            size_t n = sizeof(scores) / sizeof(scores[0]);
            int totalScores = 0;
            for(int i = 0; i < n; i++){
                totalScores += scores[i];
            }
            
            return totalScores;
        }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    Student_Score std;
    int kristenScore = 0;
    int currScore = 0;
    int largerScores = 0;
    int scores[5];
    int n = 0;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        size_t scoresIndex = 0;
        string line;
        getline(cin, line);
        stringstream ss(line);
        string exam;
        while(ss >> exam){
            scores[scoresIndex] = stoi(exam);
            scoresIndex++;
        }
        if(i == 0){
            std.input(scores);
            kristenScore = std.calculateTotalScore();
        }else{
            std.input(scores);
            currScore = std.calculateTotalScore();
        }
        if(currScore > kristenScore){
            largerScores++;
        }
    }
      cout << largerScores << endl;
    return 0;
}
