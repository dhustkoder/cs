package common;
import java.util.*;

public class Tests {

	public static void sort(final String args[], final common.SortFun sortfun)
	{
		ArrayList<Integer> array = common.Utils.makeIntArrayFromStrings(args);
		if (array.size() < 2) {
			System.err.println("Usage: " + sortfun.getClass().getName() + " [list]");
			System.exit(-1);
		}

		System.out.println("UNSORTED:");
		common.Utils.printData(array);

		sortfun.sort(array);

		System.out.println("SORTED:");
		common.Utils.printData(array);
	}
}

