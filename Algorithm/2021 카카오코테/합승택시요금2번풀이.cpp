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
    int minimum;
    int idx = 0;
    int arr[n+1];
    fill_n(arr,n,100001);
    
    if(edge[from][to] != 100001) return edge[from][to];
    if(!cnt) return 100003;
    
    for(int i = 1; i <= n; i++){
        if(i == from) continue;
        
        arr[i] = findWay(i,to,n,cnt-1) + edge[from][i];
    }
    return *min_element(arr,arr+(n+1));
}
