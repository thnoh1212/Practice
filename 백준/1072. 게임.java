import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long X = sc.nextInt();
        long Y = sc.nextInt();

        long winRate =  (Y * 100) / X;
        if(winRate >= 99){
            System.out.println(-1);
        }
        else{
            int start = 0, end = 1000000000;
            int res = 0;
            while(start <= end){
                int mid = (start + end) / 2;
                long NWinRate = (100 * (mid + Y)) / (X + mid);
                if(winRate >= NWinRate){
                    res = mid + 1;
                    start = mid + 1;
                }
                else end = mid - 1;
            }
            System.out.println(res);
        }
    }
}
