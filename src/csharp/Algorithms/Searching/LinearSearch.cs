using Common;
using System;
using System.Collections.Generic;
using DataStructures;


namespace Algorithms.Searching
{

	public class LinearSearch : ISearchingAlgorithm
	{

		public int Execute<T>(IDataStructure<T> data, T target)
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


