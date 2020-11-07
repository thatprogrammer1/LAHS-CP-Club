import java.io.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws IOException {
		// Odd + Odd = Even
		// Odd + Even = Odd
		// Even + Even = Even
		// Treasure: 2 odd, 3 even
		// Keys: 1 odd, 3 even
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int treasureOdd = 0;
		int treasureEven = 0;
		for(int i = 0; i<n; i++) {
			int x =  Integer.parseInt(st.nextToken());
			if(x%2==0) treasureEven++;
			else treasureOdd++;
		}

		st = new StringTokenizer(br.readLine());
		int keyOdd = 0;
		int keyEven = 0;
		for(int i = 0; i<m; i++) {
			int x =  Integer.parseInt(st.nextToken());
			if(x%2==0) keyEven++;
			else keyOdd++;
		}

		System.out.println(Math.min(treasureEven, keyOdd) + Math.min(treasureOdd, keyEven));


	}
}