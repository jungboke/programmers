- 유클리드 호제법을 응용

1

```
#include <string>
#include <vector>
using namespace std;
int go(int a,int b)
{
    int mul = a % b;
    while(mul!=0)
    {
        a = b;
        b = mul;
        mul = a % b;
    }
    return b;
}

int solution(vector<int> arr) {
    int answer = 0;
    for(int i=0;i<arr.size()-1;i++)
    {
        int a = arr[i];
        int b = arr[i+1];
        int yak = go(a,b);
        int mul = a * b;
        int x = mul / yak;
        arr[i] = x;
        arr.erase(arr.begin()+i+1);
        i--;
    }
    answer = arr[0];
    return answer;
}
```

2

```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int change(int a,int b)
{
    int mul = a%b;
    while(mul!=0)
    {
        a = b;
        b = mul;
        mul = a%b;
    }
    return b;
}
int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(),arr.end());
    while(arr.size()!=1)
    {
        int sum = arr[0] * arr[1];
        int inter = change(arr[0],arr[1]);
        arr.erase(arr.begin());
        arr[0] = sum / inter;
    }
    answer = arr[0];
    return answer;
}
```

3

```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int uclid(int a, int b) {
    int temp = a%b;
    while(temp!=0) {
        a = b;
        b = temp;
        temp = a%b;
    }
    return b;
}

int solution(vector<int> arr) {
    int answer = 0;
    while(arr.size()!=1) {
        int mul = arr[0]*arr[1];
        int inter = uclid(arr[0],arr[1]);
        arr.erase(arr.begin());
        arr[0] = mul/inter;
    }
    answer = arr[0];
    return answer;
}
```
