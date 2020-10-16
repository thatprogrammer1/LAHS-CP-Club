import java.io.*;
// Solution to Painting the Barn using arrays
import java.util.*;
public class paintArray {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("paint.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		
		boolean[] arr = new boolean[100];

		for(int i = a; i < b; i++) {
			arr[i] = true;
		}

		for(int i = c; i < d; i++) {
			arr[i] = true;
		}

		int ans = 0;
		for(int i = 0; i < 100; i++) {
			if(arr[i] == true) {
				ans = ans + 1;
			}
		}

		pw.print(ans);

        br.close();
		pw.close();
	}
}