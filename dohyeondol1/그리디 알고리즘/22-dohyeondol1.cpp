#include <iostream>
using namespace std;

int totalCompetiton;

int main() {
    int easy, easyMedium, medium, mediumHigh, high;
    cin >> easy >> easyMedium >> medium >> mediumHigh >> high;
    
    while(true) {
        bool easySubmitted = false;
        bool mediumSubmitted = false;
        bool highSubmitted = false;
        
        if(easy) {
            easy--;
            easySubmitted = true;
        }
        else {
            if(easyMedium) {
                easyMedium--;
                easySubmitted = true;
            }
        }
        
        if(medium) {
            medium--;
            mediumSubmitted = true;
        }
        else {
            if(easyMedium || mediumHigh) {
                if(easyMedium >= mediumHigh)
                    easyMedium--;
                else
                    mediumHigh--;
                mediumSubmitted = true;
            }
        }
        
        if(high) {
            high--;
            highSubmitted = true;
        }
        else {
            if(mediumHigh) {
                mediumHigh--;
                highSubmitted = true;
            }
        }
        
        if(!easySubmitted || !mediumSubmitted || !highSubmitted)
            break;
        
        ++totalCompetiton;
    }
        
    cout << totalCompetiton << '\n';
    return 0;
}