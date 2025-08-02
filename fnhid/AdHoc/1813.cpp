#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, t;
    cin >> n;
    vector <int> a(51, 0);
    for(int i=0;i<n;i++){
        cin >> t;
        a[t]++;
    }
     
    for(int i=50;i>0;i--){
        if(a[i]==i) {
            cout << i;
            return 0;
        }
    }    
    
    if(a[0]==0) cout << 0;
    else cout << -1;
    
    return 0;
        

}