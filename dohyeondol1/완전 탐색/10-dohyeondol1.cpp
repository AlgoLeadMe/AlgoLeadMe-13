#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> numberSet;
    
    sort(numbers.begin(), numbers.end());
    do {
        for(int i = 1; i <= numbers.length(); i++) {
            int n = stoi(numbers.substr(0, i));
            numberSet.insert(n);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    for(int num : numberSet)
        if(isPrime(num)) answer++;
    
    return answer;
}