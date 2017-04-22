using System;
using System.Collections.Generic;
using DataStructures;
using Common;


namespace Algorithms.Searching
{
	
	public class BinarySearch : ISearchingAlgorithm
	{

		public int Execute<T>(IDataStructure<T> data, T target)
		{
			int min = 0;
			int max = data.Count;

			while (min <= max) {

				int guess = (min + max) / 2;

				var comparison = Comparer<T>.Default.Compare(data[guess], target);

				if (comparison < 0)
					min = guess + 1;
				else if (comparison > 0)
					max = guess - 1;
				else
					return guess;

			}

			return data.Count;
		}


		public static int Main(string[] args)
		{
			return Tests.Search(args, new BinarySearch());
		}

	}

}

