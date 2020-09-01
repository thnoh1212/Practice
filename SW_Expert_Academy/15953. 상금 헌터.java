package algo_0901;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int answer = 0;
		for(int i = 0; i < N; i++) {
			String[] temp = br.readLine().split(" ");
			int a = Integer.parseInt(temp[0]);
			int b = Integer.parseInt(temp[1]);
			
			answer = (firstFestival(a) + secondFestival(b));
			System.out.println(answer);
		}
	}
	static int firstFestival(int Rank){
	    if(Rank == 0){
	        return 0;
	    }
	    else if(Rank <= 1){
	        return 5000000;
	    }
	    else if(Rank <= 3){
	        return 3000000;
	    }
	    else if(Rank <= 6){
	        return 2000000;
	    }
	    else if(Rank <= 10){
	        return 500000;
	    }
	    else if(Rank <= 15){
	        return 300000;
	    }
	    else if(Rank <= 21){
	        return 100000;
	    }
	    else{
	        return 0;
	    }
	}

	static int secondFestival(int Rank){
	    if(Rank == 0){
	        return 0;
	    }
	    else if(Rank <= 1){
	        return 5120000;
	    }
	    else if(Rank <= 3){
	        return 2560000;
	    }
	    else if(Rank <= 7){
	        return 1280000;
	    }
	    else if(Rank <= 15){
	        return 640000;
	    }
	    else if(Rank <= 31){
	        return 320000;
	    }
	    else{
	        return 0;
	    }
	}
}
