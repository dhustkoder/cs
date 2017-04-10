package src.java.common;
import src.java.algorithms.*;
import java.util.*;

public class Tests {

	public static void sort(final String args[], final src.java.algorithms.sorting.SortingAlgorithm sortAlgo)
	{
		ArrayList<Integer> array = src.java.common.Utils.makeIntArrayFromStrings(args);

		if (array.size() < 2) {
			System.err.println("Usage: " + sortAlgo.getClass().getName() + " [list]");
			System.exit(-1);
		}

		System.out.println("UNSORTED:");
		src.java.common.Utils.printData(array);

		sortAlgo.execute(array);

		System.out.println("SORTED:");
		src.java.common.Utils.printData(array);
	}
}

