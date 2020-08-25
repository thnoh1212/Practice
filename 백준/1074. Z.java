import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int i = sc.nextInt();
		int j = sc.nextInt();
		int chk = (int) Math.pow(2, N - 1);
		int plus = (int) Math.pow(4, N - 1);
		int answer = 0;
		int[][] res = {{0, 1},{2,3}};
		while (chk != 1) {
			if (i >= chk && j < chk) {
				answer += plus * 2;
				i -= chk;
			} else if (i < chk && j >= chk) {
				answer += plus;
				j -= chk;
			} else if (i >= chk && j >= chk) {
				answer += plus * 3;
				i -= chk;
				j -= chk;
			}
			chk /= 2;
			plus /= 4;
		}
		answer += res[i][j];
		System.out.println(answer);
		sc.close();
	}

}
