using System;
using System.Collections.Generic;
using DataStructures;
using Common;


namespace Algorithms.Sorting
{

	public class BubbleSort : ISortingAlgorithm
	{
		public void Execute<T>(IDataStructure<T> data, Func<T, T, bool> cmp)
		{
			for (int i = 0; i < data.Count; ++i) {
				for (int j = 0; j < (data.Count - 1) - i; ++j) {
					if (cmp(data[j + 1], data[j])) {
						T tmp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = tmp;
					}
				}
			}
		}


		public static int Main(string[] args)
		{
			return Tests.Sort(args, new BubbleSort());
		}
	}
	
}

