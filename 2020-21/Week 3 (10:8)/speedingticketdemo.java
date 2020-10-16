import java.util.*;
import java.io.*;

public class speedingticketdemo {
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(new FileReader("speeding.in"));
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] road = new int[100];
		int pointer = 0;
		for(int i = 0; i < n; i++) {
			int segmentLength = sc.nextInt();
			int speedLimit = sc.nextInt();
			for(int j = 0; j < segmentLength; j++) {
				road[pointer] = speedLimit;
				pointer++;
			}
		}
		int[] bessieSpeed = new int[100];
		pointer = 0;
		for(int i = 0; i < m; i++) {
			int segmentLength = sc.nextInt();
			int speed = sc.nextInt();
			for(int j = 0; j < segmentLength; j++) {
				bessieSpeed[pointer] = speed;
				pointer++;
			}
		}
		int max = 0;
		for(int i = 0; i < 100; i++) {
			int difference = bessieSpeed[i] - road[i];
			/*if (difference > max) {
				max = difference;
			}*/
			max = Math.max(max, difference);
		}
		PrintWriter pw = new PrintWriter(new File("speeding.out"));
		pw.print(max);
		pw.close();
	}
}
