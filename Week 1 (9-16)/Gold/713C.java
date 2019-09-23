import java.io.*;
import java.util.*;

public class ClassName {
    static int n;
    static int a[] = new int[10000], a_s[] = new int[10000], dp[][] = new int[10001][10000];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());

        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(tk.nextToken());
            a_s[i] = a[i];
        }
        Arrays.sort(a_s, 0, n);
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + Math.abs(a_s[0] - a[i - 1]);
            for (int j = 1; j < n; j++) {
                dp[i][j] = Math.min(Math.abs(a_s[j] - a[i - 1]) + dp[i - 1][j], dp[i][j - 1]);
            }
        }
        System.out.println(dp[n][n - 1]);
    }
}
