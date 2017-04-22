using System.Collections.Generic;
using DataStructures;


namespace Algorithms.Searching
{

	public interface ISearchingAlgorithm
	{
		int Execute<T>(IDataStructure<T> data, T target);
	}
}
