
// Code taken from usaco.org
// The crux of this problem is to be able to calculate
// the number of haybales between two ranges quickly.
// Say the positions of haybales were sorted.
// Then, if we knew the index of the first haybale after 
// each endpoint of the query, we could subtract the two
// indices because we know that every haybale in between
// the indices must be within the query. 
// The problem is now reduced to quickly finding 
// the index of the first haybale after some value 
// within a sorted list, which we can solve using binary search.
import java.io.*;
import java.util.*;

public class haybales {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("haybales.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("haybales.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        int[] list = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            list[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(list);
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            pw.println(countLEQ(list, b) - countLEQ(list, a - 1));
        }
        pw.close();
    }

    public static int countLEQ(int[] list, int limit) {
        if (list[0] > limit) {
            return 0;
        }
        int min = 0;
        int max = list.length - 1;
        // list[min] is guaranteed to be <= limit
        while (min != max) {
            int mid = (min + max + 1) / 2;
            if (list[mid] <= limit) {
                min = mid;
            } else {
                max = mid - 1;
            }
        }
        return min + 1;
    }
}