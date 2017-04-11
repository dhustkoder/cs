package src.java.algorithms.sorting;
import src.java.common.Tests;
import java.util.*;


public class BubbleSort implements SortingAlgorithm {

	
	public <T extends Comparable<T>> void execute(List<T> data)
	{

		for (int i = 0; i < data.size(); ++i) {
			for (int j = 0; j < (data.size() - 1) - i; ++j) {
				if (data.get(j + 1).compareTo(data.get(j)) < 0) {
					final T tmp = data.get(j);
					data.set(j, data.get(j + 1));
					data.set(j + 1, tmp);
				}
			}
		}
	}


	public static void main(String[] args)
	{
		Tests.sort(args, new BubbleSort());
	}
}
