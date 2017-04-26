using Common;
using System;
using System.Collections.Generic;
using DataStructures;


namespace Algorithms.Sorting
{

	public class QuickSort : ISortingAlgorithm
	{

		public void Execute<T>(IDataStructure<T> data, Func<T, T, bool> cmp)
		{
			if (data.Count > 1)
				QSort(0, data.Count, data, cmp);
		}


		private void QSort<T>(int beg, int end, IDataStructure<T> data, Func<T, T, bool> cmp)
		{
			if ((end - beg) > 1) {
				int r = Partitionate(beg, end, data, cmp);
				QSort(r + 1, end, data, cmp);
				QSort(beg, r, data, cmp);
			}
		}


		private int Partitionate<T>(int beg, int end, IDataStructure<T> data, Func<T, T, bool> cmp)
		{
			int l = beg + 1;
			int r = end - 1;

			for (;;) {
				while (l < r && cmp(data[l], data[beg]))
					l += 1;
				while (r >= l && cmp(data[beg], data[r]))
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
