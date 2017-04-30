using System;
using System.Collections.Generic;
using DataStructures;
using Common;


namespace Algorithms.Sorting
{

	public class SelectionSort : ISortingAlgorithm
	{
		public void Execute<T>(IDataStructure<T> data, Func<T, T, bool> cmp)
		{
			for (int i = 0; i < data.Count; ++i) {
				int min = i;
				for (int j = min; j < data.Count; ++j)
					if (cmp(data[j], data[min]))
						min = j;
				if (min != i) {
					T tmp = data[min];
					data[min] = data[i];
					data[i] = tmp;
				}
			}
		}

		public static void Main(string[] args)
		{
			Tests.Sort(args, new SelectionSort());
		}
	}

}

