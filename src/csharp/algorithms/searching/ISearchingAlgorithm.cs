using System.Collections.Generic;


namespace Algorithms.Searching
{

	public interface ISearchingAlgorithm
	{
		int Execute<T>(List<T> data, T target);
	}
}
