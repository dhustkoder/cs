package src.java.common;
import java.util.Collection;
import src.java.data_structures.DataStructure;
import src.java.data_structures.Vector;


public class Utils 
{

	public static Vector<Integer> makeIntArrayFromStrings(final String strs[])
	{
		Vector<Integer> r = new Vector<Integer>(Integer.class, strs.length);

		for (final String str : strs)
			r.pushBack(Integer.parseInt(str));

		return r;
	}


	public static <T> void printData(final DataStructure<T> data)
	{
		for (int i = 0; i < data.size(); ++i)
			System.out.println("[" + i + "]" + " = " + data.get(i));
	}

}
