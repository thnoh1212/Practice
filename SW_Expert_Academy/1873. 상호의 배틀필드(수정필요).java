import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int H = sc.nextInt();
            int W = sc.nextInt();
            char[][] map = new char[H][W];
            int cur_i = 0;
            int cur_j = 0;
            char cur_dir = ' ';
            for(int i = 0; i < H; i++){
                String temp = sc.next();
            	for(int j = 0; j < W; j++){
                	map[i][j] = temp.charAt(j);
                    if(map[i][j] == '<' || map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '>'){
                    	cur_dir = map[i][j];
                        cur_i = i;
                        cur_j = j;
                    }
                }            
            }
            int moves = sc.nextInt();
            String acts = sc.next();
            for(int i = 0; i < moves; i++){
            	char act = acts.charAt(i);
                if(act == 'U'){
                    cur_dir = '^';
                    if(cur_i - 1 >= 0){
                    	if(map[cur_i - 1][cur_j] == '.'){
                        	map[cur_i][cur_j] = '.';
                            cur_i -= 1;
                            map[cur_i][cur_j] = cur_dir;
                        }
                    	else
                    		map[cur_i][cur_j] = cur_dir;
                    }
                    else
                        map[cur_i][cur_j] = cur_dir;
                }
                else if(act == 'D'){
                	
                    cur_dir = 'v';
                	 if(cur_i + 1 < H){
                    	if(map[cur_i + 1][cur_j] == '.'){
                        	map[cur_i][cur_j] = '.';
                            cur_i += 1;
                            map[cur_i][cur_j] = cur_dir;
                        }
                    	else
                    		map[cur_i][cur_j] = cur_dir;
                    }
                    else {
                        map[cur_i][cur_j] = cur_dir;
                        
                    }
                }
                else if(act == 'L'){
                    cur_dir = '<';
                	if(cur_j - 1 >= 0){
                    	if(map[cur_i][cur_j - 1] == '.'){
                        	map[cur_i][cur_j] = '.';
                            cur_j -= 1;
                            map[cur_i][cur_j] = cur_dir;
                        }
                    	else
                    		map[cur_i][cur_j] = cur_dir;
                    }
                    else
                        map[cur_i][cur_j] = cur_dir;
                }
                else if(act == 'R'){
                    cur_dir = '>';
                	if(cur_j + 1 < W){
                    	if(map[cur_i][cur_j + 1] == '.'){
                        	map[cur_i][cur_j] = '.';
                            cur_j += 1;
                            map[cur_i][cur_j] = cur_dir;
                        }
                    	else
                    		map[cur_i][cur_j] = cur_dir;
                    }
                    else
                        map[cur_i][cur_j] = cur_dir;
                }
                else{// act == 'S'
                	int shoot_i = cur_i;
                    int shoot_j = cur_j;
                    if(cur_dir == '^'){  
                        while(true){
                        	shoot_i -= 1;
                            if(shoot_i < 0) break;
                            else{
                            	if(map[shoot_i][shoot_j] == '*'){
                                	map[shoot_i][shoot_j] = '.';
                                    break;
                                }
                                else if(map[shoot_i][shoot_j] == '#') break;
                            }
                        }
                    }
                    else if(cur_dir == 'v'){
                         while(true){
                        	shoot_i += 1;
                            if(shoot_i >= H) break;
                            else{
                            	if(map[shoot_i][shoot_j] == '*'){
                                	map[shoot_i][shoot_j] = '.';
                                    break;
                                }
                                else if(map[shoot_i][shoot_j] == '#') break;
                            }
                        }
                    }
                    else if(cur_dir == '<'){
                    	 while(true){
                        	shoot_j -= 1;
                            if(shoot_j < 0) break;
                            else{
                            	if(map[shoot_i][shoot_j] == '*'){
                                	map[shoot_i][shoot_j] = '.';
                                    break;
                                }
                                else if(map[shoot_i][shoot_j] == '#') break;
                            }
                        }
                    }  
                    else{// cur_dir == '>'
                         while(true){
                        	shoot_j += 1;
                            if(shoot_j >= W) break;
                            else{
                            	if(map[shoot_i][shoot_j] == '*'){
                                	map[shoot_i][shoot_j] = '.';
                                    break;
                                }
                                else if(map[shoot_i][shoot_j] == '#') break;
                            }
                        }
                    }
                }
            }
            System.out.print("#" + test_case + " ");
            for(int i = 0; i < H; i++){
            	for(int j = 0; j < W; j++){
                	System.out.print(map[i][j]);
                }
                System.out.println();
            }
		}
        sc.close();
	}
}
