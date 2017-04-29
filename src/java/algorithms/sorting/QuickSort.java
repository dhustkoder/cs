package src.java.algorithms.sorting;
import src.java.data_structures.*;
import src.java.common.Tests;
import java.util.*;


public class QuickSort implements SortingAlgorithm
{

	public <T extends Comparable<T>> void execute(DataStructure<T> data, final Comparator<T> cmp)
	{
		if (data.size() > 1)
			sort(0, data.size(), data, cmp);
	}


	private <T extends Comparable<T>> void sort(final int begin, final int end, DataStructure<T> data, final Comparator<T> cmp)
	{
		if ((end - begin) > 1) {
			final int p = partitionate(begin, end, data, cmp);
			sort(begin, p, data, cmp);
			sort(p + 1, end, data, cmp);
		}
	}


	private <T extends Comparable<T>> int partitionate(int l, int r, DataStructure<T> data, final Comparator<T> cmp)
	{
		final int p = l;
		++l;
		--r;

	
		for (;;) {
			while (l < r && cmp.compare(data.get(l), data.get(p)) < 0)
				++l;
			while (r >= l && cmp.compare(data.get(p), data.get(r)) < 0)
				--r;

			if (l >= r)
				break;

			final T tmp = data.get(r);
			data.set(r, data.get(l));
			data.set(l, tmp);

			++l;
			--r;
		}


		final T tmp = data.get(r);
		data.set(r, data.get(p));
		data.set(p, tmp);
		return r;
	}


	public static void main(String[] args)
	{
		Tests.sort(args, new QuickSort());
	}
	
}
