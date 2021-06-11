#include <string>
#include <vector>
#include <sstream>

using namespace std;

class applicantinfo {
public:
    applicantinfo(string lang, string jobGroup, string career, string soulFood, int score) {
        this->lang = lang;
        this->jobGroup = jobGroup;
        this->career = career;
        this->soulFood = soulFood;
        this->score = score;
    }
    string lang;
    string jobGroup;
    string career;
    string soulFood;
    int score;
};

vector<applicantinfo> applicants;
vector<applicantinfo> seperated_query;

void init(vector<string> info, vector<string> query);

#define QUERYLEN = 5;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    init(info, query);
    
    for(auto sq:seperated_query){
        int cnt = 0;
        for(auto ap:applicants){
            if(((ap.lang == sq.lang) || (sq.lang == "-"))
              && (ap.jobGroup == sq.jobGroup || sq.jobGroup == "-")
              && (ap.career == sq.career || sq.career == "-")
              && (ap.soulFood == sq.soulFood || sq.soulFood == "-")
              && ap.score >= sq.score)
                cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}

void init(vector<string> info, vector<string> query){
    for(auto i:info){
        vector<string> arr;
        istringstream ss(i);
        string stringBuffer;
        while (getline(ss, stringBuffer, ' ')){
            arr.push_back(stringBuffer);
        }
        int temp;
        stringstream ssInt(arr[4]);
        ssInt >> temp;
        applicants.push_back(applicantinfo(arr[0], arr[1], arr[2], arr[3], temp));
    }
    
    for(auto q:query){
        istringstream ss(q);
        string stringBuffer;
        vector<string> arr;
        while(getline(ss, stringBuffer, ' ')){
            if(stringBuffer == "and") continue;
            arr.push_back(stringBuffer);
        }
        int temp;
        stringstream ssInt(arr[4]);
        ssInt >> temp;
        seperated_query.push_back(applicantinfo(arr[0], arr[1], arr[2], arr[3], temp));
    }
}

