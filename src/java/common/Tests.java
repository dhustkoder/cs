package src.java.common;
import src.java.common.Utils;
import src.java.algorithms.sorting.*;
import src.java.algorithms.searching.*;
import java.util.*;


public class Tests {


	public static void sort(final String[] args, final SortingAlgorithm sortAlgo)
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


	public static void search(final String[] args, final SearchingAlgorithm searchAlgo)
	{
		final Integer target = Integer.parseInt(args[args.length - 1]);
		ArrayList<Integer> array = Utils.makeIntArrayFromStrings(Arrays.copyOf(args, args.length - 1));

		if (array.size() < 3) {
			System.err.println("Usage: " + searchAlgo.getClass().getName() + " [list] [target]");
			System.exit(-1);
		}


		if (searchAlgo instanceof BinarySearch) {
			QuickSort qsort = new QuickSort();
			qsort.execute(array);
		}


		System.out.println("ARRAY:");
		Utils.printData(array);

		final Integer found = searchAlgo.execute(array, target);

		if (found != null)
			System.out.println(found + " FOUND AT " + array.indexOf(found));
		else
			System.out.println(target + " NOT FOUND");
	}


}

