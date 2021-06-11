#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edge[201][201];


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2e9;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i==j) edge[i][j] = 0;
            else edge[i][j] = 100001;
        }    
    }
      
    for(int i = 0; i < fares.size(); i++){
        edge[fares[i][0]][fares[i][1]] = fares[i][2];
        edge[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int via = 1; via <= n; via++)
        for(int from = 1; from <= n; from++)
            for(int to = 1; to <= n; to++)
                edge[from][to] = min(edge[from][to], edge[from][via] + edge[via][to]);
    
    for(int i = 1; i <= n; i++)
        answer = min(answer, edge[s][i] + edge[i][a] + edge[i][b]);
    
    return answer;
}
