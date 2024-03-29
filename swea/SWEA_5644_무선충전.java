//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.Comparator;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Solution {
//
//	static int[] dx = {0,-1,0,1,0};
//	static int[] dy = {0,0,1,0,-1};
//	static List<Integer> a = new ArrayList<>();
//	static List<Integer> b = new ArrayList<>();
//	static List<int[]>[][] board = new ArrayList[11][11];
//	
//	static int move() {
//		int result = 0;
//		int sx=0,sy=0;
//		int ex=9,ey=9;
//		result+=board[sx][sy].get(0)[0];
//		result+=board[ex][ey].get(0)[0];
//		for(int i=0;i<a.size();i++) {
//			sx+=dx[a.get(i)];
//			sy+=dy[a.get(i)];
//			ex+=dx[b.get(i)];
//			ey+=dy[b.get(i)];
//			if(board[sx][sy].get(0)[1]==board[ex][ey].get(0)[1]) {
//				if(board[sx][sy].get(0)[1]==-1) continue;
//				int x = board[sx][sy].get(1)[0]+board[ex][ey].get(0)[0];
//				int y = board[sx][sy].get(0)[0]+board[ex][ey].get(1)[0];
//				int maxi = Math.max(x, y);
//				result+=maxi;
//			} else {
//				result+=board[sx][sy].get(0)[0];
//				result+=board[ex][ey].get(0)[0];
//			}
//		}
//		return result;
//	}
//	
//	static void spark(int x, int y, int c, int p, int cnt) {
//		for(int i=0;i<10;i++) {
//			for(int j=0;j<10;j++) {
//				int dist = Math.abs(x-i)+Math.abs(y-j);
//				if(dist<=c) {
//					board[i][j].add(new int[] {p,cnt});
//				}
//			}
//		}
//	}
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		System.setIn(new FileInputStream("data/5644.txt"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			for(int i=0;i<10;i++) {
//				for(int j=0;j<10;j++) {
//					board[i][j] = new ArrayList<>();
//					board[i][j].add(new int[] {0,-1});
//				}
//			}
//			st = new StringTokenizer(br.readLine());
//			int n = Integer.parseInt(st.nextToken());
//			int m = Integer.parseInt(st.nextToken());
//			st = new StringTokenizer(br.readLine());
//			for(int i=0;i<n;i++) {
//				int x = Integer.parseInt(st.nextToken());
//				a.add(x);
//			}
//			st = new StringTokenizer(br.readLine());
//			for(int i=0;i<n;i++) {
//				int x = Integer.parseInt(st.nextToken());
//				b.add(x);
//			}
//			int cnt = 0;
//			for(int i=0;i<m;i++) {
//				st = new StringTokenizer(br.readLine());
//				int y = Integer.parseInt(st.nextToken())-1;
//				int x = Integer.parseInt(st.nextToken())-1;
//				int c = Integer.parseInt(st.nextToken());
//				int p = Integer.parseInt(st.nextToken());
//				spark(x,y,c,p,cnt++);
//			}
//			for(int i=0;i<10;i++) {
//				for(int j=0;j<10;j++) {
//					Collections.sort(board[i][j], new Comparator<int[]>() {
//						public int compare(int[] x, int[] y) {
//							return Integer.compare(x[0], y[0])*-1;
//						}
//					});
//				}
//			}
//			int answer = move();
//			sb.append("#"+(ot-t)+" "+answer+"\n");
//			a.clear();
//			b.clear();
//			for(int i=0;i<10;i++) {
//				for(int j=0;j<10;j++) {
//					board[i][j].clear();
//				}
//			}
//		}
//		System.out.println(sb);
//	}
//}
// import java.io.*;
// import java.util.*;

// public class Solution {
	
// 	static int[] dx = {0,-1,0,1,0};
// 	static int[] dy = {0,0,1,0,-1};
// 	static List<Integer>[][] board = new ArrayList[10][10];
// 	static List<Integer> a = new ArrayList<>();
// 	static List<Integer> b = new ArrayList<>();
// 	static List<Integer> power = new ArrayList<>();
	
// 	static void spread(int x, int y, int c, int idx) {
// 		for(int i=0;i<c+1;i++) {
// 			int nx = x-c+i;
// 			int ny = y-i;
// 			for(int j=0;j<2*(i+1)-1;j++) {
// 				if(nx>=0&&nx<10&&ny+j>=0&&ny+j<10) {
// 					board[nx][ny+j].add(idx);					
// 				}
// 			}
// 		}
// 		for(int i=0;i<c;i++) {
// 			int nx = x+c-i;
// 			int ny = y-i;
// 			for(int j=0;j<2*(i+1)-1;j++) {
// 				if(nx>=0&&nx<10&&ny+j>=0&&ny+j<10) {
// 					board[nx][ny+j].add(idx);					
// 				}
// 			}
// 		}
// 	}
	
// 	static int cal(int sx, int sy, int ex, int ey) {
// 		int result = -1;
// 		if(board[sx][sy].isEmpty()&&board[ex][ey].isEmpty()) {
// 			result = 0;
// 		} else if(board[sx][sy].isEmpty()) {
// 			for(int i=0;i<board[ex][ey].size();i++) {
// 				int bidx = board[ex][ey].get(i);
// 				result = Math.max(result, power.get(bidx));
// 			}
// 		} else if(board[ex][ey].isEmpty()) {
// 			for(int i=0;i<board[sx][sy].size();i++) {
// 				int aidx = board[sx][sy].get(i);
// 				result = Math.max(result, power.get(aidx));
// 			}
// 		} else {
// 			for(int i=0;i<board[sx][sy].size();i++) {
// 				for(int j=0;j<board[ex][ey].size();j++) {
// 					int aidx = board[sx][sy].get(i);
// 					int bidx = board[ex][ey].get(j);
// 					if(aidx!=bidx) {
// 						int sum = power.get(aidx)+power.get(bidx);
// 						result = Math.max(result, sum);
// 					} else {
// 						int sum = power.get(aidx);
// 						result = Math.max(result, sum);
// 					}
// 				}
// 			}			
// 		}
// 		return result;
// 	}
	
//     public static void main(String[] args) throws IOException {
//     	System.setIn(new FileInputStream("data/5644.txt"));
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         StringBuilder sb = new StringBuilder();
//         StringTokenizer st;

//         int t = Integer.parseInt(br.readLine());
//         int ot = t;
//         while(t-->0) {
//         	for(int i=0;i<10;i++) {
//         		for(int j=0;j<10;j++) board[i][j] = new ArrayList<>();
//         	}
//         	st = new StringTokenizer(br.readLine());
//         	int n = Integer.parseInt(st.nextToken());
//         	int k = Integer.parseInt(st.nextToken());
//         	st = new StringTokenizer(br.readLine());
//         	for(int i=0;i<n;i++) {
//         		int x = Integer.parseInt(st.nextToken());
//         		a.add(x);
//         	}
//         	st = new StringTokenizer(br.readLine());
//         	for(int i=0;i<n;i++) {
//         		int x = Integer.parseInt(st.nextToken());
//         		b.add(x);
//         	}
//         	for(int i=0;i<k;i++) {
//         		st = new StringTokenizer(br.readLine());
//         		int y = Integer.parseInt(st.nextToken())-1;
//         		int x = Integer.parseInt(st.nextToken())-1;
//         		int c = Integer.parseInt(st.nextToken());
//         		int p = Integer.parseInt(st.nextToken());
//         		spread(x,y,c,i);
//         		power.add(p);
//         	}
//         	int answer = 0;
//         	int sx=0,sy=0;
//         	int ex=9,ey=9;
//         	answer += cal(sx,sy,ex,ey);
//         	for(int i=0;i<n;i++) {
//         		sx+=dx[a.get(i)]; sy+=dy[a.get(i)];
//         		ex+=dx[b.get(i)]; ey+=dy[b.get(i)];
//         		int sum = cal(sx,sy,ex,ey);
//         		answer+=sum;
//         	}
//         	sb.append("#"+(ot-t)+" "+answer+"\n");
//         	a.clear();
//         	b.clear();
//         	power.clear();
//         }
//         System.out.println(sb);
// 	}
// }
import java.util.*;
import java.io.*;

public class Solution {
	
	static int[] dx = {0,-1,0,1,0};
	static int[] dy = {0,0,1,0,-1};
	static List<Integer> a = new ArrayList<>();
	static List<Integer> b = new ArrayList<>();
	static List<int[]> c = new ArrayList<>();
	static int answer = 0;
	static int N;
	
	static boolean check(int sx, int sy, int idx) {
		int ex = c.get(idx)[0]; int ey = c.get(idx)[1]; int d = c.get(idx)[2];
		if(Math.abs(ex-sx)+Math.abs(ey-sy)<=d) return true;
		else return false;
	}
	
	static int choice(List<Integer> tempA, List<Integer> tempB) {
		int result = 0;
		if(tempA.size()==0&&tempB.size()==0) return 0;
		else if(tempA.size()==0) {
			int temp = 0;
			for(int i=0;i<tempB.size();i++) {
				int x = tempB.get(i);
				temp = Math.max(temp, c.get(x)[3]);
			}
			return temp;
		} else if(tempB.size()==0) {
			int temp = 0;
			for(int i=0;i<tempA.size();i++) {
				int x = tempA.get(i);
				temp = Math.max(temp, c.get(x)[3]);
			}
			return temp;
		}
		for(int i=0;i<tempA.size();i++) {
			for(int j=0;j<tempB.size();j++) {
				int temp = 0;
				int x = tempA.get(i); int y = tempB.get(j);
				if(x!=y) temp = c.get(x)[3]+c.get(y)[3];
				else temp = c.get(x)[3];
				result = Math.max(result, temp);
			}
		}
		return result;
	}
	
	static int move(int ax, int ay, int bx, int by) {
		int result = 0;
		for(int i=0;i<=N;i++) {
			List<Integer> tempA = new ArrayList<>();
			List<Integer> tempB = new ArrayList<>();
			for(int j=0;j<c.size();j++) {
				if(check(ax,ay,j)) tempA.add(j);
				if(check(bx,by,j)) tempB.add(j);
			}
			result += choice(tempA,tempB);
			if(i==N) break;
			ax+=dx[a.get(i)]; ay+=dy[a.get(i)];
			bx+=dx[b.get(i)]; by+=dy[b.get(i)];
		}
		return result;
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/5644.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			N=n;
			int m = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				int x = Integer.parseInt(st.nextToken());
				a.add(x);
			}
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				int x = Integer.parseInt(st.nextToken());
				b.add(x);
			}
			for(int i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken())-1;
				int x = Integer.parseInt(st.nextToken())-1;
				int e = Integer.parseInt(st.nextToken());
				int r = Integer.parseInt(st.nextToken());
				c.add(new int[] {x,y,e,r});
			}
			answer = move(0,0,9,9);
			sb.append("#"+(ot-t)+" "+answer+"\n");
			a.clear(); b.clear(); c.clear();
		}
		System.out.println(sb);
	}
}
