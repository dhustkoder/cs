package src.java.algorithms.searching;
import src.java.data_structures.*;
import src.java.common.Tests;
import java.util.*;


public class LinearSearch implements SearchingAlgorithm 
{

	public <T extends Comparable<T>> int execute(final DataStructure<T> data, final T target)
	{
		for (int i = 0; i < data.size(); ++i)
			if (data.get(i).compareTo(target) == 0)
				return i;

		return data.size();
	}

	public static void main(String[] args)
	{
		Tests.search(args, new LinearSearch());
	}
	
}


