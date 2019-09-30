/*

After analyzing the problem, it turns out that the optimal way to flip the board is the following:
- traverse from the bottom-right corner towards the top-left corner
- if the value is 1, flip the board in the way the problem states

If you do that process and keep track of how many times you flip, you will reach the answer.

*/
import java.io.*;
import java.util.StringTokenizer;

public class cowtip {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("cowtip.in"));
        PrintWriter pw = new PrintWriter(new File("cowtip.out"));

        StringTokenizer x = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(x.nextToken());

        int[][] board = new int[20][20];
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                board[i][j] = line.charAt(j) - '0';
                // convert char into int ('1' => 1 or '0' => 0)
            }
        }

        int numFlips = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 1) {
                    numFlips += 1;

                    // flipping code:
                    for (int a = 0; a <= i; a++) {
                        for (int b = 0; b <= j; b++) {
                            if (board[a][b] == 0) board[a][b] = 1;
                            else board[a][b] = 0;
                        }
                    }
                }
            }
        }

        pw.println(numFlips);

        pw.close();
        br.close();
    }
}