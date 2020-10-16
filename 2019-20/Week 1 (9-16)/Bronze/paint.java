import java.io.*;
import java.util.StringTokenizer;

public class paint {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("paint.in"));
        PrintWriter pw = new PrintWriter(new File("paint.out"));

        StringTokenizer x = new StringTokenizer(br.readLine());

        int a, b, c, d;
        a = Integer.parseInt(x.nextToken()); // read 2 numbers on the first line
        b = Integer.parseInt(x.nextToken());

        x = new StringTokenizer(br.readLine()); // read the next line in the same fashion
        c = Integer.parseInt(x.nextToken());
        d = Integer.parseInt(x.nextToken());
        // parse the input

        int smallest = Math.min(a, c);
        int biggest = Math.max(b, d);
        // find the smallest and largest values to be used later

        int[] wall = new int[101];
        // stores if the unit of the wall is painted (0-blank, 1-paint)
        // by default, array is filled with 0's (default in Java)

        for (int i = smallest; i <= biggest; i++) {
            if (i > a && i <= b) { // check if painted by Farmer John
                wall[i] = 1;
            }
            if (i > c && i <= d) { // check if painted by Bessie
                wall[i] = 1;
            }
        }

        int counter = 0; // used to count how many 1's (how many units were painted)
        for (int unit : wall) {
            if (unit == 1)
                counter += 1;
        }

        pw.println(counter); // print to file

        pw.close();
        br.close();
    }
}