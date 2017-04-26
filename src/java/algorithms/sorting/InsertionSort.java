package src.java.algorithms.sorting;
import src.java.data_structures.*;
import src.java.algorithms.sorting.SortingAlgorithm;
import src.java.common.Tests;
import java.util.*;


public class InsertionSort implements SortingAlgorithm
{

	public <T extends Comparable<T>> void execute(DataStructure<T> data, final Comparator<T> cmp)
	{
		for (int i = 1; i < data.size(); ++i) {
			for (int j = i; j > 0 && cmp.compare(data.get(j), data.get(j - 1)) < 0; --j) {
				final T tmp = data.get(j);
				data.set(j, data.get(j - 1));
				data.set(j - 1, tmp);
			}
		}
	}

	
	public static void main(String[] args)
	{
		Tests.sort(args, new InsertionSort());
	}
	
}
