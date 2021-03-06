// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <tuple>
// #include <queue>
// #include <string.h>
// using namespace std;
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
// bool check[10][10];
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>> a(n,vector<int>(m,0));
//     vector<pair<int,int>> result;
//     vector<int> perm;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> a[i][j];
//             if(a[i][j]==0) result.push_back(make_pair(i,j));
//         }
//     }
//     for(int i=0;i<3;i++) perm.push_back(1);
//     for(int i=0;i<result.size()-3;i++) perm.push_back(0);
//     sort(perm.begin(),perm.end());
//     int maxi = 0;
//     do
//     {
//         memset(check,false,sizeof(check));
//         vector<vector<int>> tmp_a = a;
//         for(int i=0;i<perm.size();i++)
//         {
//             if(perm[i]==1)
//             {
//                 int x,y;
//                 tie(x,y) = result[i];
//                 tmp_a[x][y] = 1;
//             }
//         }
//         queue<pair<int,int>> q;
//         for(int i=0;i<a.size();i++)
//         {
//             for(int j=0;j<a[0].size();j++)
//             {
//                 if(tmp_a[i][j]==2)
//                 {
//                     q.push(make_pair(i,j));
//                     check[i][j] = true;
//                 }
//             }
//         }
//         while(!q.empty())
//         {
//             int x,y;
//             tie(x,y) = q.front();
//             q.pop();
//             for(int i=0;i<4;i++)
//             {
//                 int nx = x+dx[i];
//                 int ny = y+dy[i];
//                 if(nx>=0&&nx<n&&ny>=0&&ny<m&&check[nx][ny]==false)
//                 {
//                     if(tmp_a[nx][ny]==0)
//                     {
//                         tmp_a[nx][ny] = 2;
//                         q.push(make_pair(nx,ny));
//                         check[nx][ny] = true;
//                     }
//                 }
//             }
//         }
//         int cnt = 0;
//         for(int i=0;i<a.size();i++)
//         {
//             for(int j=0;j<a[0].size();j++)
//             {
//                 if(tmp_a[i][j]==0) cnt++;
//             }
//         }
//         if(maxi<cnt) maxi = cnt;
//     }while(next_permutation(perm.begin(),perm.end()));
    
//     cout << maxi << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[10][10];
bool check[10][10];
vector<pair<int,int>> zero;
int N,M;
int maxi = -1;

void bfs(vector<pair<int,int>> temp) {
  memset(check,false,sizeof(check));
  queue<pair<int,int>> q;
  int tmp_a[10][10];
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      tmp_a[i][j] = a[i][j];
      if(a[i][j]==2) q.push(make_pair(i,j));
    }
  }
  for(int i=0;i<temp.size();i++) {
    tmp_a[temp[i].first][temp[i].second] = 1;
  }
  while(!q.empty()) {
    int x,y;
    tie(x,y) = q.front();
    q.pop();
    for(int i=0;i<4;i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
        if(tmp_a[nx][ny]==0) {
          q.push(make_pair(nx,ny));
          check[nx][ny] = true;
        }
      }
    }
  }
  int cnt = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(tmp_a[i][j]==0&&check[i][j]==false) cnt+=1;
    }
  }
  maxi = max(maxi,cnt);
}

void dfs(vector<pair<int,int>> temp, int start) {
  if(temp.size()==3) {
    bfs(temp);
    return;
  }
  for(int i=start;i<zero.size();i++) {
    temp.push_back(zero[i]);
    dfs(temp,i+1);
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  N=n;M=m;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
      if(a[i][j]==0) zero.push_back(make_pair(i,j));
    }
  }
  vector<pair<int,int>> temp;
  dfs(temp,0);
  cout << maxi << '\n';
  return 0;
}