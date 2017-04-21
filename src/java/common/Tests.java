package src.java.common;
import src.java.common.Utils;
import src.java.algorithms.sorting.*;
import src.java.algorithms.searching.*;
import src.java.data_structures.*;


public class Tests 
{
	static final boolean CSDEBUG = false;

	public static void sort(final String[] args, final SortingAlgorithm sortAlgo)
	{
		Vector<Integer> array = Utils.makeIntArrayFromStrings(args);

		if (array.size() < 2) {
			System.err.println("Usage: " + sortAlgo.getClass().getName() + " [list]");
			System.exit(-1);
		}

		if (CSDEBUG) {
			System.out.println("UNSORTED:");
			Utils.printData(array);
		}

		sortAlgo.execute(array);

		if (CSDEBUG) {
			System.out.println("SORTED:");
			Utils.printData(array);
		}
	}


	public static void search(final String[] args, final SearchingAlgorithm searchAlgo)
	{
		Vector<Integer> array = Utils.makeIntArrayFromStrings(args);
		final Integer target = array.popBack();

		if (array.size() < 3) {
			System.err.println("Usage: " + searchAlgo.getClass().getName() + " [list] [target]");
			System.exit(-1);
		}

		if (CSDEBUG) {
			System.out.println("ARRAY:");
			Utils.printData(array);
		}

		final Integer index = searchAlgo.execute(array, target);

		if (index != array.size())
			System.out.println(target + " FOUND AT INDEX " + index);
		else
			System.out.println(target + " NOT FOUND");
	}


}

