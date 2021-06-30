class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        String []tempAnswer = new String[m+1];

        for(int i =1; i <= m; i++)
            tempAnswer[i] = "";

        int num = 0;
        int idx = 1;
        while(true){
            String temp = "";
            int tempNum = num;
            do{
                int saveNum = tempNum % n;
                tempNum /= n;
                if(saveNum < 10)
                    temp += Integer.toString(saveNum);
                else{
                    if(saveNum == 10) temp += 'A';
                    else if(saveNum == 11) temp += 'B';
                    else if(saveNum == 12) temp += 'C';
                    else if(saveNum == 13) temp += 'D';
                    else if(saveNum == 14) temp += 'E';
                    else temp += 'F';
                }
            }while(tempNum != 0);

            for(int i = temp.length() - 1; i >= 0; i--){
                tempAnswer[idx++] += temp.charAt(i);
                if(tempAnswer[p].length() == t) break;
                if(idx > m)
                    idx = 1;
            }
            if(tempAnswer[p].length() == t) break;
            num += 1;
        }
        answer = tempAnswer[p];
        return answer;
    }
}