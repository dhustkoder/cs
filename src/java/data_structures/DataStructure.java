package src.java.data_structures;

public interface DataStructure<T>
{
	public int size();
	public T get(final int index);
	public void set(final int index, T value);
}
