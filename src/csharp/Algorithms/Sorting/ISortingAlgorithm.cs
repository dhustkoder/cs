using System;
using System.Collections.Generic;
using DataStructures;


namespace Algorithms.Sorting
{
	public interface ISortingAlgorithm
	{
		void Execute<T>(IDataStructure<T> data, Func<T, T, bool> cmp);
	}
}

