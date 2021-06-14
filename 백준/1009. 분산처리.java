import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for(int tc = 1; tc <= T; tc++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int temp = 1;
            boolean flag = false;
            for(int i = 0; i < b; i++) {
                temp *= a;
                temp %= 10;
            }
            if(temp == 0) temp = 10;
            System.out.println(temp);

        }

    }
}
