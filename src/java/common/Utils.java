package common;
import java.util.*;

public class Utils {

	public static ArrayList<Integer> makeIntArrayFromStrings(final String strs[])
	{
		ArrayList<Integer> r = new ArrayList<Integer>();

		for (int i = 0; i < strs.length; ++i)
			r.add(Integer.parseInt(strs[i]));

		return r;
	}


	public static <T> void printData(final Collection<T> data)
	{
		for (T x : data)
			System.out.println(x);
	}
}
