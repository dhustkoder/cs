package src.java.algorithms.searching;
import src.java.common.Tests;
import java.util.*;


public class LinearSearch implements SearchingAlgorithm {


	public <T extends Comparable<T>> T execute(final List<T> data, final T target)
	{
		for (int i = 0; i < data.size(); ++i)
			if (data.get(i).compareTo(target) == 0)
				return data.get(i);

		return null;
	}

	public static void main(String[] args)
	{
		Tests.search(args, new LinearSearch());
	}


}


