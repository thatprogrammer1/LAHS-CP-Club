
/*
In this problem, one can just loop through all cows x coordinates 
to place the north-south fence, and loop through all cows y coordinates
to place the east-west fence. Given these fences, one can loop throught the cows
to see which region they are in. 

Code taken from usaco.org
*/
import java.io.*;
import java.util.*;

public class balancing {
    public static void main(String[] args) throws IOException {
        // initialize file I/O
        BufferedReader br = new BufferedReader(new FileReader("balancing.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("balancing.out")));

        // read in N, we can safely ignore B so we don't actually read the value
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        // create arrays to store locations of cows
        // cow i is at point (xLoc[i], yLoc[i])
        int[] xLoc = new int[n];
        int[] yLoc = new int[n];
        for (int i = 0; i < n; i++) {
            // read in location of cow i
            st = new StringTokenizer(br.readLine());
            xLoc[i] = Integer.parseInt(st.nextToken());
            yLoc[i] = Integer.parseInt(st.nextToken());
        }
        // in the absolute worst case, N cows will be in one quadrant
        int ans = n;
        for (int xIndex = 0; xIndex < n; xIndex++) {
            for (int yIndex = 0; yIndex < n; yIndex++) {
                // identify the fence location
                // vertical fence at x=xDiv
                // horizontal fence at y=yDiv
                int xDiv = xLoc[xIndex] + 1;
                int yDiv = yLoc[yIndex] + 1;
                int upperLeft = 0;
                int upperRight = 0;
                int lowerLeft = 0;
                int lowerRight = 0;
                // identify which quadrant each cows lands in
                for (int i = 0; i < n; i++) {
                    if (xLoc[i] < xDiv && yLoc[i] < yDiv) {
                        lowerLeft++;
                    }
                    if (xLoc[i] < xDiv && yLoc[i] > yDiv) {
                        upperLeft++;
                    }
                    if (xLoc[i] > xDiv && yLoc[i] < yDiv) {
                        lowerRight++;
                    }
                    if (xLoc[i] > xDiv && yLoc[i] > yDiv) {
                        upperRight++;
                    }
                }
                // figure out which region has the most cows
                int worstRegion = 0;
                if (upperLeft > worstRegion) {
                    worstRegion = upperLeft;
                }
                if (upperRight > worstRegion) {
                    worstRegion = upperRight;
                }
                if (lowerLeft > worstRegion) {
                    worstRegion = lowerLeft;
                }
                if (lowerRight > worstRegion) {
                    worstRegion = lowerRight;
                }
                // determine if we have found a better pair of fences
                if (worstRegion < ans) {
                    ans = worstRegion;
                }
            }
        }
        // print the answer
        pw.println(ans);
        // close output stream
        pw.close();
    }
}