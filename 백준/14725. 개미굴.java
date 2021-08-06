import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        TreeMap<String, TreeMap> root = new TreeMap<>();

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            TreeMap cursor = root;
            for(int j = 0; j < k; j++){
                String temp = st.nextToken();
                if(cursor.get(temp) == null){
                    cursor.put(temp, new TreeMap<>());
                }
                cursor = (TreeMap) cursor.get(temp);
            }
        }
        printAnswer(root, 0);
    }

    static void printAnswer(TreeMap map, int depth){
        for (Object o : map.keySet()) {
            for(int i = 0; i < depth; i++)
                System.out.print("--");
            System.out.println(o);
            printAnswer((TreeMap) map.get(o), depth+1);
        }
    }
}