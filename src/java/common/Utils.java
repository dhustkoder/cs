package src.java.common;
import java.util.*;


public class Utils {


	public static ArrayList<Integer> makeIntArrayFromStrings(final String strs[])
	{
		ArrayList<Integer> r = new ArrayList<Integer>();

		for (String str : strs)
			r.add(Integer.parseInt(str));

		return r;
	}


	public static <T> void printData(final Collection<T> data)
	{
		Integer i = 0;
		for (T x : data) {
			System.out.println("[" + i + "]" + " = " + x);
			i += 1;
		}
	}

	
}
