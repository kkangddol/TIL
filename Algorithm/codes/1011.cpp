#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t,x,y;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> x >> y;
        double dist = y-x;
        double sqrt_dist = sqrt(dist);
        int round_dist = round(sqrt_dist);
        
        if(sqrt_dist <= round_dist) cout << 2*round_dist-1 << endl;
        else cout << 2*round_dist << endl;
    }

}
