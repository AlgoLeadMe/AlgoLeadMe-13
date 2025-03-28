#include <iostream>
#include <vector>
using namespace std;

int main() {
    int computer, connection;
    cin >> computer >> connection;
    vector<bool> isInfected(computer);
    isInfected[0] = true;
    
    int count = 0;
    vector<int> firstCom(connection), secondCom(connection);
    for(int i = 0; i < connection; i++) {
        cin >> firstCom[i] >> secondCom[i];
    }
    
    int temp = -1;
    while(count != temp) {
        temp = count;
        for(int i = 0; i < connection; i++) {
            if(isInfected[firstCom[i]-1] == true && isInfected[secondCom[i]-1] == true) continue;
            else {
                if(isInfected[firstCom[i]-1] == true || isInfected[secondCom[i]-1] == true) {
                    isInfected[firstCom[i]-1] = true;
                    isInfected[secondCom[i]-1] = true;
                    count++;
                }
                else continue;
            }
        }
    }
    
    cout << count;

    return 0;
}