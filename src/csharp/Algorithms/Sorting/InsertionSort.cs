using System;
using System.Collections.Generic;
using DataStructures;
using Common;



namespace Algorithms.Sorting
{
	public class InsertionSort : ISortingAlgorithm
	{

		public void Execute<T>(IDataStructure<T> data, Func<T, T, bool> cmp)
		{
			for (int i = 0; i < data.Count; ++i) {
				for (int j = i; j > 0 && cmp(data[j], data[j - 1]); --j) {
					T tmp = data[j - 1];
					data[j - 1] = data[j];
					data[j] = tmp;
				}
			}
		}


		public static int Main(string[] args)
		{
			return Tests.Sort(args, new InsertionSort());
		}

	}
}


