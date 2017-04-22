using Common;
using System;
using System.Collections.Generic;
using DataStructures;


namespace Algorithms.Sorting
{

	public class QuickSort : ISortingAlgorithm
	{

		public void Execute<T>(IDataStructure<T> data)
		{
			if (data.Count > 1)
				QSort(0, data.Count, data);
		}


		private void QSort<T>(int beg, int end, IDataStructure<T> data)
		{
			if ((end - beg) > 1) {
				int r = Partitionate(beg, end, data);
				QSort(r + 1, end, data);
				QSort(beg, r, data);
			}
		}


		private int Partitionate<T>(int beg, int end, IDataStructure<T> data)
		{
			var comparer = Comparer<T>.Default;
			int l = beg + 1;
			int r = end - 1;

			for (;;) {
				while (l < r && comparer.Compare(data[l], data[beg]) < 0)
					l += 1;
				while (r >= l && comparer.Compare(data[r], data[beg]) > 0)
					r -= 1;

				if (l >= r)
					break;

				T tmp = data[r];
				data[r] = data[l];
				data[l] = tmp;

				l += 1;
				r -= 1;
			}


			T aux = data[r];
			data[r] = data[beg];
			data[beg] = aux;
			return r;
		}


		public static int Main(string[] args)
		{
			return Tests.Sort(args, new QuickSort());
		}

	}
}
