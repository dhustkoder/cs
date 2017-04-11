package src.java.algorithms.sorting;
import src.java.common.Tests;
import java.util.*;


public class QuickSort implements SortingAlgorithm {


	public <T extends Comparable<T>> void execute(List<T> data)
	{
		if (data.size() > 1)
			sort(0, data.size(), data);
	}


	private <T extends Comparable<T>> void sort(final int begin, final int end, List<T> data)
	{
		if ((end - begin) > 1) {
			final int p = partitionate(begin, end, data);
			sort(begin, p, data);
			sort(p + 1, end, data);
		}
	}


	private <T extends Comparable<T>> int partitionate(int l, int r, List<T> data)
	{
		final int p = l;
		++l;
		--r;

	
		for (;;) {


			while (l < r && data.get(l).compareTo(data.get(p)) < 0)
				++l;
			while (r >= l && data.get(r).compareTo(data.get(p)) > 0)
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
