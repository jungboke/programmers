/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    long long answer = 0;
    for(int i=0;i<n;i++)
    {
        int num = a[i] - i;
        if(num>=0) answer += num;
    }
    cout << answer << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end(),greater<>());
//     long long sum = 0;
//     for(int i=0;i<a.size();i++)
//     {
//         if(a[i]-i<0) break;
//         else sum += a[i]-i;
//     }
//     cout << sum << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end(),greater<>());
  long long sum = 0;
  for(int i=0;i<n;i++) {
    if(a[i]-i>=0) sum += a[i]-i;
    else break;
  }
  
  cout << sum << '\n';

  return 0; 
}