import java.util.*;
import java.io.*;

public class NotLast {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("notlast.in"));
        PrintWriter pw = new PrintWriter(new File("notlast.out"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        String[] names = new String[] { "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta" };
        int[] cows = new int[7];
        for (int i = 0; i < 7; i++)
            cows[i] = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int val = Integer.parseInt(st.nextToken()), index = 0;
            switch (name) {
            case "Bessie":
                index = 0;
                break;
            case "Elsie":
                index = 1;
                break;
            case "Daisy":
                index = 2;
                break;
            case "Gertie":
                index = 3;
                break;
            case "Annabelle":
                index = 4;
                break;
            case "Maggie":
                index = 5;
                break;
            case "Henrietta":
                index = 6;
                break;
            }
            cows[index] += val;
        }
        int minimum = 1000000000;
        for (int i = 0; i < 7; i++) {
            if (cows[i] < minimum) {
                minimum = cows[i];
            }
        }
        int minimum2 = 1000000000, index = 0;
        for (int i = 0; i < 7; i++) {
            if (cows[i] < minimum2 && cows[i] != minimum) {
                index = i;
                minimum2 = cows[i];
            }
        }
        int count = 0;
        for (int i = 0; i < 7; i++) {
            if (cows[i] == minimum2)
                count++;
        }
        pw.println(count == 1 ? names[index] : "Tie");

        br.close();
        pw.close();
    }
}
