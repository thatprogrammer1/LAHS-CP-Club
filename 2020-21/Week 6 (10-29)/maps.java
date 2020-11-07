import java.io.*;
import java.util.*;
public class maps {
	public static void main(String[] args) throws IOException {
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		map.put(100, 1);
		map.put(1, 10);
		map.put(10000, 3);
		map.put(1, 11);

		for(int i : map.keySet()){
			System.out.print(i);
			System.out.print(", ");
			System.out.println(map.get(i));
		}

		TreeMap<String, Integer> map2 = new TreeMap<String, Integer>();

		map2.put("asdf", 2);
		System.out.println(map2.get("asdf"));


	}
}