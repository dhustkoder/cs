import java.util.*;

public class BubbleSort implements SortFun {

	public <T extends Comparable<T>> void sort(List<T> data)
	{

		for (int i = 0; i < data.size(); ++i) {
			for (int j = 0; j < (data.size() - 1) - i; ++j) {
				if (data.get(j + 1).compareTo(data.get(j)) < 0) {
					final T tmp = data.get(j);
					data.set(j, data.get(j + 1));
					data.set(j + 1, tmp);
				}
			}
		}
	}


	static public void main(String[] args)
	{
		Common.sortTest(args, new BubbleSort());
	}
}

