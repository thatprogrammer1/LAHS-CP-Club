import java.util.*;
import java.io.*;

public class Teleportation {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("teleport.in"));
        PrintWriter pw = new PrintWriter(new File("teleport.out"));

        StringTokenizer tk = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(tk.nextToken()), b = Integer.parseInt(tk.nextToken());
        int x = Integer.parseInt(tk.nextToken()), y = Integer.parseInt(tk.nextToken());
        pw.println(Math.min(Math.min(Math.abs(a - x) + Math.abs(b - y), Math.abs(a - y) + Math.abs(b - x)),
                Math.abs(a - b)));

        br.close();
        pw.close();
    }
}
