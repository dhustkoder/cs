using Algorithms.Sorting;
using System;
using System.Collections.Generic;


namespace Common
{


	public class Tests
	{
		public static int Sort(string[] args, ISortingAlgorithm sort)
		{
			var data = new List<int>();

			foreach (var str in args)
				data.Add(int.Parse(str));

			if (data.Count < 2) {
				System.Console.Error.WriteLine("Usage: " + System.AppDomain.CurrentDomain.FriendlyName + " [list]");
				return -1;
			}

			Action printData = ()=> {
				foreach (int a in data)
					System.Console.WriteLine(a);
			};

			#if CSDEBUG
			System.Console.WriteLine("UNSORTED:");
			printData();
			#endif


			sort.Execute(data);

			#if CSDEBUG
			System.Console.WriteLine("SORTED:");
			printData();
			#endif

			return 0;
		}

	}


}

