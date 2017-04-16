using Algorithms.Sorting;
using Algorithms.Searching;
using System;
using System.Collections.Generic;


namespace Common
{
	public class Utils
	{
		public static List<int> MakeIntListFromStrings(string[] strs)
		{
			var list = new List<int>();

			foreach (var str in strs)
				list.Add(int.Parse(str));

			return list;
		}


		public static void PrintData<T>(List<T> data)
		{
			for (int i = 0; i < data.Count; ++i)
				Console.WriteLine("[" + i + "] = " + data[i]);
		}
	}

	
	public class Tests
	{
		public static int Sort(string[] args, ISortingAlgorithm sort)
		{
			var data = Utils.MakeIntListFromStrings(args);

			if (data.Count < 2) {
				Console.Error.WriteLine("Usage: " + AppDomain.CurrentDomain.FriendlyName + " [list]");
				return -1;
			}

			#if CSDEBUG
			Console.WriteLine("UNSORTED:");
			Utils.PrintData(data);
			#endif

			sort.Execute(data);

			#if CSDEBUG
			Console.WriteLine("SORTED:");
			Utils.PrintData(data);
			#endif

			return 0;
		}


		public static int Search(string[] args, ISearchingAlgorithm search)
		{
			var data = Utils.MakeIntListFromStrings(args);
			if (data.Count < 3) {
				Console.Error.WriteLine("Usage: " + AppDomain.CurrentDomain.FriendlyName + " [list] [target]");
				return -1;
			}	

			int target = data[data.Count - 1];
			data.RemoveAt(data.Count - 1);


			int idx = search.Execute(data, target);

			#if CSDEBUG
			Console.WriteLine("ARRAY:");
			Utils.PrintData(data);
			#endif

			if (idx != data.Count)
				Console.WriteLine(target + " FOUND AT INDEX " + idx);
			else
				Console.WriteLine(target + " NOT FOUND");


			return 0;
		}

	}


}

