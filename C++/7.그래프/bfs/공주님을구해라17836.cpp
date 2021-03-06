/*
    칼을 발견하는 경우와 발견안하고 가는경우 두가지를 생각해서 따로따로 값을 구함.
    칼에 도달못하는 경우와 공주에 도달못하는 경우도 예외케이스로 둬야함.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <tuple>
// #include <string.h>
// using namespace std;
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
// int dist[101][101];
// int bfs(vector<vector<int>> a,int x,int y)
// {
//     memset(dist,0,sizeof(dist));
//     int n = a.size();
//     int m = a[0].size();
//     queue<pair<int,int>> q;
//     q.push(make_pair(0,0));
//     dist[0][0] = 1;
//     while(!q.empty())
//     {
//         int x,y;
//         tie(x,y) = q.front();
//         q.pop();
//         for(int i=0;i<4;i++)
//         {
//             int nx = x+dx[i];
//             int ny = y+dy[i];
//             if(nx>=0&&nx<n&&ny>=0&&ny<m&&dist[nx][ny]==0)
//             {
//                 if(a[nx][ny]!=1)
//                 {
//                     q.push(make_pair(nx,ny));
//                     dist[nx][ny] = dist[x][y] + 1;
//                 }
//             }
//         }
//     }
//     return dist[x][y]-1;
// }
// int main()
// {
//     int n,m,t;
//     cin >> n >> m >> t;
//     int sx,sy;
//     vector<vector<int>> a(n,vector<int>(m,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> a[i][j];
//             if(a[i][j]==2)
//             {
//                 sx = i;
//                 sy = j;
//             }
//         }
//     }
//     int case1 = bfs(a,n-1,m-1);
//     if(case1==-1) case1 = 9999999;
//     int case2 = bfs(a,sx,sy) + abs(n-1-sx) + abs(m-1-sy);
//     if(bfs(a,sx,sy)==-1) case2 = 9999999;
//     int answer = min(case1,case2);
//     if(answer>t||answer==9999999) cout << "Fail" << '\n';
//     else cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[101][101];
int dist[101][101];
int N,M;

int bfs(int sx, int sy, int ex, int ey, int t) {
  memset(dist,-1,sizeof(dist));
  queue<pair<int,int>> q;
  q.push(make_pair(sx,sy));
  dist[sx][sy] = 0;
  while(!q.empty()) {
    int x,y;
    tie(x,y) = q.front();
    q.pop();
    for(int i=0;i<4;i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1) {
        if(a[nx][ny]==0||a[nx][ny]==2) {
          q.push(make_pair(nx,ny));
          dist[nx][ny] = dist[x][y]+1;
        }
      }
    }
  }
  if(dist[ex][ey]!=-1) return dist[ex][ey];
  else return INF;
}

int main(int argc, char const *argv[])
{
  int n,m,t;
  cin >> n >> m >> t;
  N=n;M=m;
  int gx,gy;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
      if(a[i][j]==2) {
        gx = i;
        gy = j;
      }
    }
  }
  int x,y;
  x = bfs(0,0,n-1,m-1,t);
  y = bfs(0,0,gx,gy,t) + abs(n-1-gx) + abs(m-1-gy);
  if(x>t&&y>t) cout << "Fail" << '\n';
  else cout << min(x,y) << '\n';
  return 0;
}