/*
Since the bounds on x, y, and k are quite small, we can loop through all
possible combinations of pail amounts, the first pail being any amount from
0...x and the second pail being any amount from 0...y.

To do this, we can create a two dimensional array a, where a[i][j] stores the
amount of moves required to achieve i units of milk in the first pail and j
units of milk in the second pail. If a[xi][yi] = v, then all possible
combinations (new_xi, new_yi) that can be achieved in the next move are:

(xi, 0) by emptying the second pail
(0, yi) by emptying the first pail
(x, yi) by filling the first pail
(xi, y) by filling the second pail
(min(x, xi+yi), max(0, xi+yi-x)) by pouring the second pail into the first pail
(max(0, xi+yi-y), min(y, xi+yi)) by pouring the first pail into the second pail

To find the answer, we simply keep track of the smallest instance of |m-(xi+yi)|
through all moves k.
*/

// Java implementation

import java.io.*;
import java.util.*;

public class milk_pails {
    static int x, y, k, m, ans;
    static int valid[][] = new int[101][101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("pails.in"));
        PrintWriter pw = new PrintWriter(new File("pails.out"));

        StringTokenizer tk = new StringTokenizer(br.readLine());
        x = Integer.parseInt(tk.nextToken());
        y = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        ans = m;
        valid[0][0] = 1;
        for (int i = 1; i <= k + 1; i++) {
            for (int xi = 0; xi <= x; xi++) {
                for (int yi = 0; yi <= y; yi++) {
                    if (valid[xi][yi] != i)
                        continue;
                    if (valid[x][yi] == 0)
                        valid[x][yi] = i + 1;
                    if (valid[xi][y] == 0)
                        valid[xi][y] = i + 1;
                    if (valid[xi][0] == 0)
                        valid[xi][0] = i + 1;
                    if (valid[0][yi] == 0)
                        valid[0][yi] = i + 1;
                    if (valid[Math.min(x, xi + yi)][Math.max(0, xi + yi - x)] == 0)
                        valid[Math.min(x, xi + yi)][Math.max(0, xi + yi - x)] = i + 1;
                    if (valid[Math.max(0, xi + yi - y)][Math.min(y, xi + yi)] == 0)
                        valid[Math.max(0, xi + yi - y)][Math.min(y, xi + yi)] = i + 1;
                    ans = Math.min(ans, Math.abs(m - xi - yi));
                }
            }
        }
        pw.println(ans);

        pw.close();
        br.close();
    }
}
