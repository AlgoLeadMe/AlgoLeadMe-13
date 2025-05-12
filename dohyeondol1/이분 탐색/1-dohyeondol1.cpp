#include <iostream>
using namespace std;

int N, M, L;
int cutPositions[1000];
int targetPieceCount[1000];

void findMaxMinCutLength() {
    for (int testCase = 0; testCase < N; testCase++) {
        int left = 0;
        int right = L;

        while (left <= right) {
            int mid = (left + right) / 2;
            int prevCutPosition = 0;
            int pieceCount = 0;

            for (int i = 0; i < M; i++) {
                if (cutPositions[i] - prevCutPosition >= mid) {
                    prevCutPosition = cutPositions[i];
                    pieceCount++;
                }
            }

            if (targetPieceCount[testCase] == pieceCount && L - prevCutPosition < mid) {
                pieceCount = targetPieceCount[testCase] - 1;
            }

            if (pieceCount < targetPieceCount[testCase]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << right << "\n";
    }
}

int main(){
    cin >> N >> M >> L;
    for(int i = 0; i < M; i++) cin >> cutPositions[i];
    for(int i = 0; i < N; i++) cin >> targetPieceCount[i];
    
    findMaxMinCutLength();
    
    return 0;
}