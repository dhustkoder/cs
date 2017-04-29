package src.java.algorithms.searching;
import src.java.data_structures.*;
import src.java.common.Tests;
import java.util.*;


public class BinarySearch implements SearchingAlgorithm 
{

	public <T extends Comparable<T>> int execute(final DataStructure<T> data, final T target)
	{
		int l = 0;
		int r = data.size() - 1;

		while (r >= l) {
			final int guess = (l + r) / 2;
			final int cmp = data.get(guess).compareTo(target);

			if (cmp < 0)
				l = guess + 1;
			else if (cmp > 0)
				r = guess - 1;
			else
				return guess;
		}

		return data.size();
	}

	
	public static void main(String[] args)
	{
		Tests.search(args, new BinarySearch());
	}

}

