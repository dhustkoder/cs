package src.java.data_structures;
import java.lang.reflect.Array;


public class Vector<T> implements DataStructure<T>
{
	public Vector(final Class<T> clazz, int size)
	{
		mClazz = clazz;

		if (size <= 0)
			size = 10;
		
		reserve(size);
	}


	public int size()
	{
		return mSize;
	}


	public void reserve(final Integer need)
	{
		@SuppressWarnings("unchecked")
		T[] tmp = (T[]) Array.newInstance(mClazz, need);

		for (int i = 0; i < size(); ++i)
			tmp[i] = mData[i];

		mData = tmp;
	}


	public void pushBack(T value)
	{
		if (size() >= mData.length)
			reserve(size() + (size() / 2));

		mData[size()] = value;
		mSize += 1;
	}


	public T popBack()
	{
		mSize -= 1;
		T elem = mData[size()];
		return elem;
	}


	public T get(final int index)
	{
		return mData[index];
	}


	public void set(final int index, T value)
	{
		mData[index] = value;
	}


	private T[] mData = null;
	private Class<T> mClazz = null;
	private int mSize = 0;

}




