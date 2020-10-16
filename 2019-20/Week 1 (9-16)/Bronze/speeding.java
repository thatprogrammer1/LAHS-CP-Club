import java.io.*;
import java.util.StringTokenizer;

public class speeding {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("speeding.in"));
        PrintWriter pw = new PrintWriter(new File("speeding.out"));

        StringTokenizer x = new StringTokenizer(br.readLine());

        int n, m;
        n = Integer.parseInt(x.nextToken());
        m = Integer.parseInt(x.nextToken());

        int[] limit = new int[101]; // limit[i] is speed limit at mile i
        int[] speed = new int[101]; // speed[i] is Bessie's speed at mile i

        int ni = 1; // current index of limit[]
        for (int i = 0; i < n; i++) { // go through every line
            int l, s; // length of segment, speed limit of segment
            x = new StringTokenizer(br.readLine());
            l = Integer.parseInt(x.nextToken());
            s = Integer.parseInt(x.nextToken());

            for (int j = 0; j < l; j++) { // set the next l units to have the speed limit s
                limit[ni + j] = s;
            }

            ni += l; // move the index counter past this segment
        }

        int si = 1; // current index of speed[]
        for (int i = 0; i < m; i++) { // go through every line
            int l, s; // length of segment, speed at segment
            x = new StringTokenizer(br.readLine());
            l = Integer.parseInt(x.nextToken());
            s = Integer.parseInt(x.nextToken());

            for (int j = 0; j < l; j++) { // set the next l units to have the speed of s
                speed[si + j] = s;
            }

            si += l; // move the index counter past this segment
        }

        int over = 0; // represents the maximum amount Bessie went over the speed limit (default 0)
        for (int i = 1; i < 101; i++) { // goes from mile 1 => 100 (including 100)
            over = Math.max(over, speed[i] - limit[i]);
            // if over is the bigger than what we calculated, still use over
            // if the new value is bigger, replace over with the new value
        }

        pw.println(over); // output result

        pw.close();
        br.close();
    }
}