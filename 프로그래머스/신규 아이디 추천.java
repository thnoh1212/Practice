class Solution {
    public String solution(String new_id) {
        String answer = "";
        new_id = new_id.toLowerCase();
        char temp = ' ';
        for(int i = 0; i < new_id.length(); i++){
            if(temp == '.' && new_id.charAt(i) == '.') continue;
            if((new_id.charAt(i) >= 'a' && new_id.charAt(i) <= 'z') || (new_id.charAt(i) >= '0' && new_id.charAt(i) <= '9') ||
                    new_id.charAt(i) == '-' || new_id.charAt(i) == '_' || new_id.charAt(i) == '.'){
                answer += new_id.charAt(i);
                temp = new_id.charAt(i);
            }
        }

        if(answer.length() > 0 && answer.charAt(0) == '.'){
            answer = answer.substring(1, answer.length());
        }
        if(answer.length() > 0 && answer.charAt(answer.length() - 1) == '.'){
            answer = answer.substring(0, answer.length() - 1);
        }
        if(answer.length() == 0) answer += 'a';

        if(answer.length() >= 16){
            answer = answer.substring(0, 15);
        }
        if(answer.length() > 0 && answer.charAt(0) == '.'){
            answer = answer.substring(1, answer.length());
        }
        if(answer.length() > 0 && answer.charAt(answer.length() - 1) == '.'){
            answer = answer.substring(0, answer.length() - 1);
        }

        if(answer.length() <= 2){
            int idx = answer.length();
            while(answer.length() != 3){
                answer += answer.charAt(idx - 1);
            }
        }
        return answer;
    }
}