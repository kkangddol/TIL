#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < 2*N-1 ; i++){
        for(int j = 0 ; j < abs(N*(i/N)-(N-(i%N)-1)) ; j++) cout << ' ';
        for(int j = 0 ; j < abs((N-2)*(i/N)-(i%N))*2 + 1 ; j++) cout << '*';
        cout << '\n';
    }
}
