// 투포인터 컨벤션 완성.
// 보석쇼핑의 다른 버전.
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    map<int,int> map1;
    int start = 0;
    int end = 0;
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(map1[a[i]]+1>m) break;
        else
        {
            map1[a[i]]++;
            end = i;
        }
    }
    maxi = end-start+1;
    while(end<n)
    {
        map1[a[start]]--;
        start++;
        end++;
        while(end<n)
        {
            if(map1[a[end]]+1<=m)
            {
                map1[a[end]]++;
                if(end-start+1>maxi) maxi = end-start+1;
                end++;
            }
            else
            {
                end--;
                break;
            }
        }
    }
    cout << maxi << '\n';
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    map<int,int> map1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int start = 0;
    int end = 0;
    for(int i=0;i<n;i++)
    {
        if(map1[a[i]]+1>m) break;
        map1[a[i]]++;
        end = i;
    }
    int maxi = end-start+1;
    while(start<=end&&end<n)
    {
        map1[a[start]]--;
        start++;
        end++;
        while(end<n)
        {
            if(map1[a[end]]+1>m)
            {
                end--;
                break;
            }
            map1[a[end]]++;
            if(maxi<end-start+1) maxi = end-start+1;
            end++;
        }
    }
    cout << maxi << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<int> a(n);
//     unordered_map<int,int> map1;
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     int start = 0;
//     int end = 0;
//     int maxi = 0;
//     for(int i=0;i<n;i++)
//     {
//         if(map1[a[i]]+1>m) break;
//         map1[a[i]]++;
//         end = i;
//     }
//     maxi = end-start+1;
//     while(start<=end&&end<n)
//     {
//         map1[a[start]]--;
//         start++;
//         end++;
//         while(end<n)
//         {
//             if(map1[a[end]]+1>m)
//             {
//                 end--;
//                 break;
//             }
//             else
//             {
//                 map1[a[end]]++;
//                 if(maxi<end-start+1) maxi = end-start+1;
//                 end++;
//             }
//         }
//     }
//     cout << maxi << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  unordered_map<int,int> map1;
  int begin = 0;
  int end = 0;
  for(int i=0;i<n;i++) {
    if(map1[a[i]]+1>m) break;
    else {
      map1[a[i]]++;
      end=i;
    }
  }
  int maxi = end-begin+1;
  while(begin<=end&&end<n) {
    map1[a[begin++]]--;
    map1[a[++end]]++;
    while(end<n) {
      if(map1[a[end]]>m) {
        map1[a[end--]]--;
        break;
      } else {
        int length = end-begin+1;
        maxi = max(maxi,length);
        map1[a[++end]]++;
      }
    }
  }

  cout << maxi << '\n';
  return 0; 
}





















