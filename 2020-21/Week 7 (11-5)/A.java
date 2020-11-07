import java.io.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	

		int t = Integer.parseInt(br.readLine());
		for(int tc = 0; tc < t; tc++){
			int n = Integer.parseInt(br.readLine());
			ArrayList<Integer> ans = new ArrayList<Integer>();
			int place = 1;
			while(n>0){
				if((n%10)!=0)
					ans.add((n%10)*place);
				n = n/10;
				place *= 10;
			}

			System.out.println(ans.size());
			for(int i : ans) {
				System.out.print(i);
				System.out.print(" ");
			}
			System.out.println();
		}	

	}
}