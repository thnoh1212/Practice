import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		double min = Double.MAX_VALUE;

		String[] temp = br.readLine().split(" ");
		int N = Integer.parseInt(temp[0]);
		int K = Integer.parseInt(temp[1]);
		int[] arr = new int[N];

		temp = br.readLine().split(" ");
		for(int i = 0; i < N; i++) 
			arr[i] = Integer.parseInt(temp[i]);

		for(int i = 0; i <= N - K; i++) {
			int t_k = K + i;
			while(t_k <= N) {
				double avg = 0;
				double variance = 0;
				double deviation = 0;
				
				for(int j = i; j < t_k; j++)
					avg += arr[j];
				avg /= (t_k - i);
				
				for(int j = i; j < t_k; j++) 
					variance += Math.pow((avg - arr[j]), 2);
				variance /= (t_k - i);
				deviation = Math.sqrt(variance);
				min = Math.min(min, deviation);
				t_k++;
			}
		}
		min = Double.parseDouble(String.format("%.11f", min));
		System.out.println(min);
	}
}
