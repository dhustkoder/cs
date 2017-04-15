using System;
using System.Collections.Generic;
using Common;

namespace Algorithms.Sorting
{

	public class BubbleSort : ISortingAlgorithm
	{
		
		public void Execute<T>(List<T> data)
		{
			for (int i = 0; i < data.Count; ++i) {
				for (int j = 0; j < (data.Count - 1) - i; ++j) {
					if (Comparer<T>.Default.Compare(data[j], data[j + 1]) > 0) {
						T tmp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = tmp;
					}
				}
			}
		}


		public static void Main(string[] args)
		{
			Tests.Sort(args, new BubbleSort());	
		}
	}


}

