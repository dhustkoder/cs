using Common;
using System;
using System.Collections.Generic;


namespace Algorithms.Searching
{

	public class LinearSearch : ISearchingAlgorithm
	{

		public int Execute<T>(List<T> data, T target)
		{
			for (int i = 0; i < data.Count; ++i)
				if (Comparer<T>.Default.Compare(data[i], target) == 0)
					return i;

			return data.Count;
		}


		public static int Main(string[] args)
		{
			return Tests.Search(args, new LinearSearch());
		}

	}

}


