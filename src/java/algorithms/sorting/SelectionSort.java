package src.java.algorithms.sorting;
import src.java.data_structures.*;
import src.java.common.Tests;
import java.util.*;


public class SelectionSort implements SortingAlgorithm
{
	public <T extends Comparable<T>> void execute(DataStructure<T> data, final Comparator<T> cmp)
	{
		for (int i = 0; i < data.size(); ++i) {
			int min = i;

			for (int j = min; j < data.size(); ++j)
				if (cmp.compare(data.get(j), data.get(min)) < 0)
					min = j;

			if (min != i) {
				final T tmp = data.get(min);
				data.set(min, data.get(i));
				data.set(i, tmp);
			}
		}
	}

	public static void main(String[] args)
	{
		Tests.sort(args, new SelectionSort());
	}
}


