/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    double answer = a[n-1];
    for(int i=0;i<n-1;i++)
    {
        answer += (a[i]/2);
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
//     vector<double> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end());
//     double answer = a[n-1];
//     for(int i=0;i<n-1;i++)
//     {
//         answer += a[i]/2;
//     }
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  multiset<double> ms;
  for(int i=0;i<n;i++) {
    double x;
    cin >> x;
    ms.insert(x);
  }
  while(ms.size()!=1) {
    auto it = ms.end();
    it--;
    double x = *it;
    ms.erase(it);
    double y = *ms.begin();
    ms.erase(ms.begin());
    ms.insert(x+(y/2));
  }

  cout << *ms.begin() << '\n';
  return 0; 
}