using Algorithms.Sorting;
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
			var data = new List<int>();

			foreach (var str in args)
				data.Add(int.Parse(str));

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

	}


}

