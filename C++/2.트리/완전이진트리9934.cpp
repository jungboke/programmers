/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> answer[11];
vector<int> a;
void go(int start,int end,int level)
{
    if(start==end)
    {
        answer[level].push_back(a[start]);
        return;
    }
    int mid = (start+end)/2;
    answer[level].push_back(a[mid]);
    go(start,mid-1,level+1);
    go(mid+1,end,level+1);
}
int main()
{
    int n;
    cin >> n;
    int m = pow(2,n) - 1;

    for(int i=0;i<m;i++)
    {
        int k;
        cin >> k;
        a.push_back(k);
    }
    go(0,m-1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<answer[i].size();j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// using namespace std;
// vector<int> result[10];
// void go(int start,int end,int level,vector<int> a)
// {
//     if(start==end)
//     {
//         result[level].push_back(a[start]);
//         return;
//     }
//     int mid = (start+end)/2;
//     result[level].push_back(a[mid]);
//     go(start,mid-1,level+1,a);
//     go(mid+1,end,level+1,a);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int m = pow(2,n)-1;
//     vector<int> a(m);
//     for(int i=0;i<m;i++)
//     {
//         cin >> a[i];
//     }
//     go(0,m-1,0,a);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<result[i].size();j++)
//         {
//             cout << result[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> result[11];
vector<int> a;
void go(int start, int end, int level) {
  if(start==end) {
    result[level].push_back(a[start]);
    return;
  }
  int mid = (start+end) / 2;
  go(start,mid-1,level+1);
  result[level].push_back(a[mid]);
  go(mid+1,end,level+1);
}

int main()
{
  int n;
  cin >> n;
  int m = pow(2,n)-1;
  for(int i=0;i<m;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  go(0,m-1,0);
  for(int i=0;i<n;i++) {
    for(int j=0;j<result[i].size();j++) {
      cout << result[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}





















