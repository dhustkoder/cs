using Algorithms.Sorting;
using System.Collections.Generic;


namespace Common
{

	public class Tests
	{

		public static void Sort(string[] args, ISortingAlgorithm sort)
		{
			var data = new List<int>();

			foreach (var str in args)
				data.Add(int.Parse(str));

			sort.Execute(data);
		}

	}


}

