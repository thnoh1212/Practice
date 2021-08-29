import java.util.Stack;

class Solution {
    public int solution(String s) {
        int answer = 0;
        for(int i = 0; i < s.length(); i++){
            boolean find = true;
            Stack<Character> stack = new Stack<>();
            for(int j = 0; j < s.length(); j++){
                char temp = s.charAt(j);
                if(stack.isEmpty()){
                    stack.add(temp);
                }
                else{
                    if(temp == '(' || temp == '{' || temp == '[')
                        stack.add(temp);
                    else if(temp == ')'){
                        if(stack.peek() != '('){
                            find = false;
                            break;
                        }
                        else
                            stack.pop();
                    }
                    else if(temp == '}'){
                        if(stack.peek() != '{'){
                            find = false;
                            break;
                        }
                        else
                            stack.pop();
                    }
                    else{
                        if(stack.peek() != '['){
                            find = false;
                            break;
                        }
                        else
                            stack.pop();
                    }
                }
            }
            if(find && stack.isEmpty())
                answer += 1;
            s = s.substring(1) + s.charAt(0);
        }
        return answer;
    }
}