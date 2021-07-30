import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    /**
     * 짝수 자릿수를 갖는 모든 대칭수는 반드시 11을 약수로 갖고 있다.
     * -> 11을 제외하고는 짝수 자리수의 소수 펠린드롬 수가 나오지 않음
     * 처리 진행 후 계산
     */
    static int moves[][] = {{1,0},{0,1},{-1,0},{0,-1}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] temp = br.readLine().split(" ");
        int a = Integer.parseInt(temp[0]);
        int b = Integer.parseInt(temp[1]);
        String check = Integer.toString(b);
        if((check.length() % 2 == 0 && check.length() != 2))
            b = (int)Math.pow(10, check.length() - 1);
        else if(check.length() % 2 == 1 && b == (int)Math.pow(10, check.length() - 1))
            b = (int)Math.pow(10, check.length() - 2);

        boolean[] array = new boolean[b+1];
        // b의 제곱근보다 작은 수에서 배수판정을 진행하고 남은 수는 전부 소수이다.
        for(int i = 2; i <= Math.sqrt(b); i++) {
            if(array[i]) continue;
            long k = (long)i;
            for(long j = k*k; j <= b; j += k) {
                array[(int) j] = true;
            }
        }
        for(int i = a; i <= b; i++) {
            if(!array[i]) {
                String num = Integer.toString(i);
                boolean chk = true;
                for(int j = 0; j < (int)num.length()/2; j++) {
                    if(num.charAt(j) != num.charAt(num.length() - j - 1)) {
                        chk = false;
                        break;
                    }
                }
                if(chk) System.out.println(i);
            }
        }
        System.out.println(-1);
    }
}
