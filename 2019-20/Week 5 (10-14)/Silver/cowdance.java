
/*
 * Let's consider the easier problem of determining whether a value of K is
 * under the bound of T_max. We can just simulate K cows always being on the
 * stage and calculating T using a priority queue for the end times of the cows.
 * This has a complexity of O(N log K). We next to determine the minimum such K
 * that works, which we can binary search for.
 * 
 * Code from usaco.org
 */
import java.io.*;
import java.util.*;

public class cowdance {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("cowdance.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cowdance.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int maxT = Integer.parseInt(st.nextToken());
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(br.readLine());
        }
        int min = 1;
        int max = n;
        while (min != max) {
            int mid = (min + max) / 2;
            if (possible(l, mid, maxT)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        pw.println(min);
        pw.close();
    }

    public static boolean possible(int[] l, int k, int t) {
        int lastTime = 0;
        PriorityQueue<Integer> q = new PriorityQueue<Integer>();
        for (int i = 0; i < l.length; i++) {
            if (q.size() == k) {
                lastTime = q.poll();
            }
            if (lastTime + l[i] > t) {
                return false;
            }
            q.add(lastTime + l[i]);
        }
        return true;
    }

}