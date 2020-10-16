// Official solution to Painting the Barn
import java.io.*;
import java.util.*;
public class paintMath2 {
	public static void main(String[] args) throws IOException {
		// initialize file I/O
		BufferedReader br = new BufferedReader(new FileReader("paint.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));

		// read in the first line, store a and b
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		// read in the second line, store c and d
		st = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());

		// for convenience, have segment [a, b] come before segment [c, d], so we want a <= c
		// if c < a, then we need to swap the two segments
		if(c < a) {
			// swap a and c
			int temp = a;
			a = c;
			c = temp;
			// then swap b and d
			temp = b;
			b = d;
			d = temp;
		}
		
		int amountPainted = 0;
		// if c >= b, then the two segments do not overlap.
		if(c >= b) {
			amountPainted = (b-a) + (d-c);
		}
		// otherwise, the two segments partially overlap, and we need to check if d > b
		else {
			if(d > b) {
				amountPainted = d - a;
			}
			else {
				amountPainted = b - a;
			}
		}
		
		// print the answer!
		pw.println(amountPainted);

		// close output stream
		pw.close();
	}
}