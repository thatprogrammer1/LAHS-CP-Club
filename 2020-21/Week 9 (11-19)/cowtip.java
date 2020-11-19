import java.io.*;
import java.util.*;

public class cowtip {
    private static BufferedReader br;
    private static StringTokenizer tr;

    private static String nextString() throws IOException{
        if (tr == null || !tr.hasMoreTokens())tr = new StringTokenizer(br.readLine());
        return tr.nextToken();
    }
    private static int nextInt() throws IOException{
        return Integer.parseInt(nextString());
    }
    private static long nextLong() throws IOException{
        return Long.parseLong(nextString());
    }
    private static Double nextDouble() throws IOException{
        return Double.parseDouble(nextString());
    }
    //these 4 functions return the next string,int,long,double in the file respectively
    public static void flip(int r, int c, char[][] mat){
        for(int i = 0; i<=r; i++){
            for(int j = 0; j<= c; j++){
                if(mat[i][j]=='1') mat[i][j] = '0';
                else mat[i][j] = '1';
            }
        }
    }
    public static void main(String[] args) throws IOException {
        // For file IO (replace these 2 lines with respective files)
        br = new BufferedReader(new FileReader("cowtip.in"));
        PrintWriter pw = new PrintWriter(new PrintWriter("cowtip.out"));
        
        // For console IO
        // br = new BufferedReader(new InputStreamReader(System.in));
        // PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
        
        // Write your solution below...
        int n = nextInt();
        char[][] mat = new char[n][n];
        for(int i = 0; i < n; i++){
            String s = nextString();
            for(int j = 0; j < n; j++) {
                mat[i][j] = s.charAt(j);
            }
        }

        int ans = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(mat[i][j]=='1'){
                    flip(i, j, mat);
                    ans++;
                }
            }
        }
        pw.println(ans);

        pw.close();
    }
}


