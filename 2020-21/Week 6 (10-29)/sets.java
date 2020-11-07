import java.io.*;
import java.util.*;
public class sets {
	public static void main(String[] args) throws IOException {

		TreeSet<Integer> set = new TreeSet<Integer>();

		set.add(1);
		set.add(3);
		set.add(2);

		// {1}
		// {1, 3}
		// {1, 2, 3}
		for(int i : set){
			System.out.println(i);
		}

		set.remove(2);
		set.remove(4);

		System.out.println();
		for(int i : set){
			System.out.println(i);
		}

		System.out.println(set.contains(1));

	}
}