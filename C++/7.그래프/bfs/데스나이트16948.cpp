// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<queue>
// #include<cstring>
// using namespace std;
// int dx[] = {-2,-2,0,0,2,2};
// int dy[] = {-1,1,-2,2,-1,1};
// int dist[300][300];


// int main(){

//     memset(dist,-1,sizeof(dist));
//     int n;
//     cin >> n;

//     int x1,y1;
//     cin >> x1 >> y1;
//     int x2,y2;
//     cin >> x2 >> y2;
//     queue<pair<int,int>> q;
//     q.push(make_pair(x1,y1));
//     dist[x1][y1] = 0;
//     while(!q.empty())
//     {
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();
//         for(int i=0;i<6;i++)
//         {
//             int nx = x+dx[i];
//             int ny = y+dy[i];
//             if(nx>=0&&nx<n&&ny>=0&&ny<n)
//             {
//                 if(dist[nx][ny] == -1)
//                 {
//                     q.push(make_pair(nx,ny));
//                     dist[nx][ny] = dist[x][y] + 1;
//                 }
//             }
//         }
//     }
//     cout << dist[x2][y2] << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int dx[] = {-2,-2,0,0,2,2};
int dy[] = {-1,1,-2,2,-1,1};
int dist[201][201];
int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  int sx,sy,ex,ey;
  cin >> sx >> sy >> ex >> ey;
  for(int i=0;i<=200;i++) {
    for(int j=0;j<=200;j++) {
      dist[i][j] = INF;
    }
  }
  queue<pair<int,int>> q;
  q.push(make_pair(sx,sy));
  dist[sx][sy] = 0;
  while(!q.empty()) {
    int x,y;
    tie(x,y) = q.front();
    q.pop();
    for(int i=0;i<6;i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0&&nx<n&&ny>=0&&ny<n) {
        if(dist[nx][ny]>dist[x][y]+1) {
          q.push(make_pair(nx,ny));
          dist[nx][ny] = dist[x][y]+1;
        }
      }
    }
  }
  if(dist[ex][ey]==INF) cout << -1 << '\n';
  else cout << dist[ex][ey] << '\n';
  return 0;
}