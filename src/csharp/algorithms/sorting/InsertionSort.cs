using System;
using System.Collections.Generic;
using Common;



namespace Algorithms.Sorting
{
	public class InsertionSort : ISortingAlgorithm
	{

		public void Execute<T>(List<T> data)
		{
			var comparer = Comparer<T>.Default;
			for (int i = 0; i < data.Count; ++i) {
				for (int j = i; j > 0 && comparer.Compare(data[j - 1], data[j]) > 0; --j) {
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


