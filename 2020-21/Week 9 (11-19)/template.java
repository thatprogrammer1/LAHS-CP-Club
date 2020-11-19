import java.io.*;
import java.util.*;

public class template {
	private static BufferedReader br;
	private static StringTokenizer tr;
	
	private static String nextString() throws IOException{
		if (tr == null || !tr.hasMoreTokens())tr = new StringTokenizer(br.readLine());
		return tr.nextToken();
	}
	private static int nextInt() throws IOException{
		return Integer.parseInt(nextString());
	}
	private static long nextLong() throws IOException{
		return Long.parseLong(nextString());
	}
	private static Double nextDouble() throws IOException{
		return Double.parseDouble(nextString());
	}
	//these 4 functions return the next string,int,long,double in the file respectively
	
	public static void main(String[] args) throws IOException {
        // For file IO (replace these 2 lines with respective files)
        // br = new BufferedReader(new FileReader("x.in"));
		// PrintWriter pw = new PrintWriter(new PrintWriter("x.out"));
        
        // For console IO
        // br = new BufferedReader(new InputStreamReader(System.in));
        // PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
        // Write your solution below...
        
		pw.println("answer");
		pw.close();
	}
}


