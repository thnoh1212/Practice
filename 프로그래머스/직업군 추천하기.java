class Solution {
    public String solution(String[] table, String[] languages, int[] preference) {
        String answer = "";
        int[] scores = new int[5];
        int max = 0;
        String[] answerList = {
                "SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME"
        };
        for(int i = 0; i < 5; i++){
            String[] temp = table[i].split(" ");
            for(int j = 1; j < temp.length; j++){
                for(int k = 0; k < languages.length; k++){
                    if(temp[j].equals(languages[k])){
                        scores[i] += (6 - j) * preference[k];
                    }
                }
            }
            max = Math.max(max, scores[i]);
        }
        for(int i = 0; i < 5; i++){
            if(max == scores[i]){
                if(answer == "")
                    answer = answerList[i];
                else{
                    if(answer.compareTo(answerList[i]) >= 1)
                        answer = answerList[i];
                }

            }
        }
        return answer;
    }
}