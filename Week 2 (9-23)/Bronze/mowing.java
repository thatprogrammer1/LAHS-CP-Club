/*

This problem has low constraints so it's easy to simulate the process.
To do so, create a large enough array, make the farmer start in the middle, and do each command.
	- the array should be initialized to numbers <= 0 so you know which parts of grass haven't been mowed
When going through each part of grass during each command, if the grass has already been mowed (aka. the value
of the array index is not the default), then find the time difference and compare that to the previously smallest difference.
If the patch of grass has not been mowed yet, then set that patch to the current time.

After the entire process, print out the smallest difference in time (or -1 if no patch was mowed multiple times).

*/

import java.io.*;
import java.util.StringTokenizer;

public class mowing {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("mowing.in"));
        PrintWriter pw = new PrintWriter(new File("mowing.out"));

        StringTokenizer str = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(str.nextToken());

        int[][] board = new int[2000][2000];

        int x = 1000;
        int y = 1000;

        int time = 0;

        int minDiff = 10000000;

        for (int i = 0; i < n; i++) {
            str = new StringTokenizer(br.readLine());
            char dir = str.nextToken().charAt(0);
            int steps = Integer.parseInt(str.nextToken());

            for (int j = 1; j <= steps; j++) {
                time += 1;
                if (dir == 'N') y -= 1;
                if (dir == 'S') y += 1;
                if (dir == 'W') x -= 1;
                if (dir == 'E') x += 1;

                if (board[x][y] != 0) { // already mowed
                    minDiff = Math.min(minDiff, time-board[x][y]);
                    board[x][y] = time;
                } else {
                    board[x][y] = time;
                }
            }
        }

        if (minDiff == 10000000) minDiff = -1;

        pw.println(minDiff);

        pw.close();
        br.close();
    }
}