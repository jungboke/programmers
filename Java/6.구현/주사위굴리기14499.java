//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.HashMap;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int[] dx = {0,0,-1,1};
//	static int[] dy = {1,-1,0,0};
//	static int[][] board = new int[21][21];
//	static int[] dice = new int[6];
//	static HashMap<Integer,Integer> map1 = new HashMap<>();
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//	
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		int nx = Integer.parseInt(st.nextToken());
//		int ny = Integer.parseInt(st.nextToken());
//		int k = Integer.parseInt(st.nextToken());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<m;j++) {
//				board[i][j] = Integer.parseInt(st.nextToken());
//			}
//		}
//		st = new StringTokenizer(br.readLine());
//		for(int i=0;i<k;i++) {
//			int[] tmp_dice = dice.clone();
//			int x = Integer.parseInt(st.nextToken())-1;
//			nx+=dx[x]; ny+=dy[x];
//			if(nx>=0&&nx<n&&ny>=0&&ny<m) {
//				if(x==0) {
//					dice[1] = tmp_dice[5];
//					dice[2] = tmp_dice[1];
//					dice[3] = tmp_dice[2];
//					dice[5] = tmp_dice[3];
//				} else if(x==1) {
//					dice[1] = tmp_dice[2];
//					dice[2] = tmp_dice[3];
//					dice[3] = tmp_dice[5];
//					dice[5] = tmp_dice[1];
//				} else if(x==2) {
//					dice[0] = tmp_dice[2];
//					dice[2] = tmp_dice[4];
//					dice[4] = tmp_dice[5];
//					dice[5] = tmp_dice[0];
//				} else {
//					dice[0] = tmp_dice[5];
//					dice[2] = tmp_dice[0];
//					dice[4] = tmp_dice[2];
//					dice[5] = tmp_dice[4];
//				}
//				if(board[nx][ny]==0) {
//					board[nx][ny] = dice[5];
//				} else {
//					dice[5] = board[nx][ny];
//					board[nx][ny] = 0;
//				}
//				sb.append(dice[2]+"\n");
//			} else {
//				nx-=dx[x]; ny-=dy[x];
//			}
//		}
//		System.out.println(sb);
//	} 
//}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	static int[] dx = {0,0,-1,1};
	static int[] dy = {1,-1,0,0};
	static int[][] board = new int[21][21];
	static int[] dice = new int[6];
	
	static void move(int dir) {
		int[] tmp_dice = new int[6];
		tmp_dice = dice.clone();
		if(dir==1) {
			tmp_dice[3] = dice[0];
			tmp_dice[0] = dice[2];
			tmp_dice[2] = dice[5];
			tmp_dice[5] = dice[3];
		} else if(dir==2) {
			tmp_dice[3] = dice[5];
			tmp_dice[0] = dice[3];
			tmp_dice[2] = dice[0];
			tmp_dice[5] = dice[2];
		} else if(dir==3) {
			tmp_dice[1] = dice[5];
			tmp_dice[0] = dice[1];
			tmp_dice[4] = dice[0];
			tmp_dice[5] = dice[4];
		} else if(dir==4) {
			tmp_dice[1] = dice[0];
			tmp_dice[0] = dice[4];
			tmp_dice[4] = dice[5];
			tmp_dice[5] = dice[1];
		}
		dice = tmp_dice.clone();
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int sx = Integer.parseInt(st.nextToken());
		int sy = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<k;i++) {
			int x = Integer.parseInt(st.nextToken());
			sx+=dx[x-1]; sy+=dy[x-1];
			if(!(sx>=0&&sx<n&&sy>=0&&sy<m)) {
				sx-=dx[x-1];
				sy-=dy[x-1];
				continue;
			}
			move(x);
			if(board[sx][sy]==0) {
				board[sx][sy] = dice[0];
			} else {
				dice[0] = board[sx][sy];
				board[sx][sy] = 0;
			}
			sb.append(dice[5]+"\n");
		}
		System.out.println(sb);
	}
}