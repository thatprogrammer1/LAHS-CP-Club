import java.io.*;
import java.util.*;
public class C {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
		
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for(int i = 0; i<n; i++){
			arr[i] = Integer.parseInt(st.nextToken()) - 1;
		}	

		boolean found = false;
		for(int i = 0; i<n; i++){
			if(arr[arr[arr[i]]] == i) {
				found = true;
			}
		}
		if(found) System.out.println("YES");
		else System.out.println("NO");


	}
}