#include<iostream>
#include<vector>
 
using namespace std;
 
int main(void){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;
    int res = 0, div = 0;
    
    cin >> A >> B >> V;

    res = (V - B) / (A - B);
    div = (V - B) % (A - B);

    if (div != 0) {
        res++;
    }

    cout << res;
 
    return 0;
}