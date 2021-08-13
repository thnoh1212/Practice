class Solution {
    static int[][] dir = {{1,0},{0,1}};
    static int[][] diagonal = {{1,1}, {-1,1}};
    static int[][][] diaCheck= {
            {{1,0}, {0,1}},
            {{-1,0},{0,1}}
    };
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        for(int i = 0; i < places.length; i++){
            boolean chk = false;
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    if(places[i][j].charAt(k) == 'P'){
                        for(int l = 0; l < 2; l++){ // 직선 맨해튼 거리 1
                            int nJ = j + dir[l][0];
                            int nK = k + dir[l][1];
                            if(nJ < 0 || nJ >= 5 || nK < 0 || nK >= 5 ) continue;
                            if(places[i][nJ].charAt(nK) == 'P'){
                                chk = true;
                                break;
                            }
                        }
                        for(int l = 0; l < 2; l++){ // 직선 맨해튼 거리 2
                            int nJ = j + dir[l][0] * 2;
                            int nK = k + dir[l][1] * 2;
                            if(nJ < 0 || nJ >= 5 || nK < 0 || nK >= 5 ) continue;
                            if(places[i][nJ].charAt(nK) == 'P' &&
                                    places[i][nJ - dir[l][0]].charAt(nK - dir[l][1]) != 'X'){
                                chk = true;
                                break;
                            }
                        }
                        for(int l = 0; l < 2; l++){ // 대각선 맨해튼 거리 2
                            int nJ = j + diagonal[l][0];
                            int nK = k + diagonal[l][1];
                            if(nJ < 0 || nJ >= 5 || nK < 0 || nK >= 5 ) continue;
                            if(places[i][nJ].charAt(nK) == 'P'){
                                for(int m = 0; m < 2; m++){
                                    int cJ = j + diaCheck[l][m][0];
                                    int cK = k + diaCheck[l][m][1];
                                    if(places[i][cJ].charAt(cK) != 'X'){
                                        chk = true;
                                        break;
                                    }
                                }
                            }
                            if(chk)
                                break;
                        }
                    }
                    if(chk)
                        break;

                }
                if(chk)
                    break;
            }
            if(chk)
                answer[i] = 0;
            else
                answer[i] = 1;
        }
        return answer;
    }
}