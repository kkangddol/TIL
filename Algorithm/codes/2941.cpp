#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<string> croatian = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    for(int i=0 ; i<croatian.size(); i++){
        while(1){
            int idx = s.find(croatian[i]);
            if(idx == string::npos) break;
            s.replace(idx,croatian[i].length(),"0");
        }
    }
    cout << s.length();

    return 0;
}
