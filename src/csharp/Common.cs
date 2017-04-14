//using Algorithms.Sorting.ISortingAlgoritm;
using System;
using System.Collections.Generic;

namespace Common {

	public class Tests {

		public static void sort(string[] args)
		{
			var data = new List<int>();
			foreach (var str in args)
				data.Add(int.Parse(str));

			foreach (var i in data)
				System.Console.WriteLine(i);
		}



		public static void Main(string[] args)
		{
			//System.Console.WriteLine("Hello World " + args[0]);
			sort(args);
		}






	}



}





