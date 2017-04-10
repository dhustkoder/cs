import java.util.*;

public class Common {

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


	public static void sortTest(final String args[], final SortFun sortfun)
	{
		ArrayList<Integer> array = makeIntArrayFromStrings(args);
		if (array.size() < 2) {
			System.err.println("Usage: " + sortfun.getClass().getName() + " [list]");
			System.exit(-1);
		}

		System.out.println("UNSORTED:");
		printData(array);

		sortfun.sort(array);

		System.out.println("SORTED:");
		printData(array);
	}
}
