#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edge[201][201];

int findWay(int from, int to, int n, int cnt);

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2000000000;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            edge[i][j] = 100001;
    
    for(int i = 1; i <= n; i++)
        edge[i][i] = 0;
    
    for(int i = 0; i < fares.size(); i++){
        edge[fares[i][0]][fares[i][1]] = fares[i][2];
        edge[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int i = 1; i <= n; i++)
        answer = min(answer, findWay(s,i,n,n) + findWay(i,a,n,n) + findWay(i,b,n,n));
    
    
    return answer;
}

int findWay(int from, int to, int n, int cnt){
    int sum = 0;
    int minimum = 100001;
    int idx,temp;
    if(cnt == 0) return 100002;
    else{
        for(int i = 1; i <= n; i++){
            temp = findWay(from,i,n,cnt-1);
            if(minimum != min(minimum,temp)){
                minimum = min(minimum,temp);
                idx = i;
            }
        }
        return findWay(idx,to,n,cnt-1) + minimum;
    }
}
