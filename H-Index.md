1
```
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    int max = *max_element(citations.begin(),citations.end());
    for(int i=0;i<max;i++)
    {
        int count = 0;
        for(int j=0;j<citations.size();j++)
        {
            if(citations[j] >= i) count++;
        }
        if(count >= i && citations.size()-count <= i)
        {
            answer = i;
        }
    }
    
    return answer;
}
```
2
```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> answers;
    sort(citations.begin(),citations.end());
    int max = citations[citations.size()-1];
    for(int i=0;i<citations.size();i++)
    {
        for(int j=0;j<=max;j++)
        {
            int idx = lower_bound(citations.begin(),citations.end(),j) - citations.begin();
            if(citations.size()-idx >= j) answers.push_back(j);
        }
    }
    answer = *max_element(answers.begin(),answers.end());
    return answer;
}
```
+ lower_bound를 사용한 문제해결, lower_bound는 지정값보다 같거나 큰 원소의 주소값을 반환