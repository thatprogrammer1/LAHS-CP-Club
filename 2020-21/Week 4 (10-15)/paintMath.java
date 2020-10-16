// Solution to Painting the Barn using simple math
import java.io.*;
import java.util.*;
public class paintMath {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("paint.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());

		int ans = 0;
		if (d >= a && b >= c) {
			//overlap 
			ans = Math.max(b, d) - Math.min(a, c);
		} else {
			//no overlap
			ans = (b-a) + (d-c);
		}
		pw.println(ans);
        
		br.close();
		pw.close();
	}
}