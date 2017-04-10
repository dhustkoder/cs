package src.java.common;
import src.java.common.Utils;
import src.java.algorithms.sorting.SortingAlgorithm;
import java.util.*;

public class Tests {

	public static void sort(final String args[], final SortingAlgorithm sortAlgo)
	{
		ArrayList<Integer> array = Utils.makeIntArrayFromStrings(args);

		if (array.size() < 2) {
			System.err.println("Usage: " + sortAlgo.getClass().getName() + " [list]");
			System.exit(-1);
		}

		System.out.println("UNSORTED:");
		Utils.printData(array);

		sortAlgo.execute(array);

		System.out.println("SORTED:");
		Utils.printData(array);
	}
}

