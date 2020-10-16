
// Code taken from usaco.org
// Every square that encompasses the the two rectangles
// must span the smallest and largest x coordinates as well as
// the smallest and largest y coordinates.
// Thus, we can just take the maximum of the difference
// between the smallest and largest x coordinates and y coordinates
// and square that value. 
import java.io.*;
import java.util.*;

public class square {
    public static void main(String[] args) throws IOException {
        // initialize file I/O
        BufferedReader br = new BufferedReader(new FileReader("square.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("square.out")));

        // track the bottom, top, left, and rightmost points that need to be covered
        int smallestX = 10;
        int largestX = 0;
        int smallestY = 10;
        int largestY = 0;

        // read in two lines, store corners of the pastures
        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int xLow = Integer.parseInt(st.nextToken());
            int yLow = Integer.parseInt(st.nextToken());
            int xHigh = Integer.parseInt(st.nextToken());
            int yHigh = Integer.parseInt(st.nextToken());

            if (xLow < smallestX) {
                smallestX = xLow;
            }
            if (xHigh > largestX) {
                largestX = xHigh;
            }
            if (yLow < smallestY) {
                smallestY = yLow;
            }
            if (yHigh > largestY) {
                largestY = yHigh;
            }
        }

        // compute the desired side length of the square
        int desiredSideLength = largestX - smallestX;
        if (largestY - smallestY > largestX - smallestX) {
            desiredSideLength = largestY - smallestY;
        }

        // print the answer
        pw.println(desiredSideLength * desiredSideLength);
        pw.close();
    }
}