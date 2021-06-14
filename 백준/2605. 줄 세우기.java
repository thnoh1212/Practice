package algo_0923;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main2605 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String[] temp = br.readLine().split(" ");
		ArrayList<Integer> test = new ArrayList<>();
		for(Integer i = 0; i < N; i++) {
			Integer num = Integer.parseInt(temp[i]);
			num = i - num;
			test.add(num, i+1);
		}
		
		for(int i = 0; i < test.size(); i++)
			System.out.print(test.get(i) + " ");
			
		
	}
}
