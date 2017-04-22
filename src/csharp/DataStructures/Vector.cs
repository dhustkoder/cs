

namespace DataStructures
{

	public class Vector<T> : IDataStructure<T>
	{
		private const int kInitialCap = 10;


		private int Cap { get; set; } = kInitialCap;
		private T[] _data = new T[kInitialCap];


		public int Count { get; internal set; } = 0;


		public T this[int index]
		{
			get
			{
				return Get(index);
			}
			set
			{
				Set(index, value);
			}
		}


		public T Get(int index)
		{
			return _data[index];
		}


		public void Set(int index, T elem)
		{
			_data[index] = elem;
		}


		public void PushBack(T elem)
		{
			if (Count >= Cap)
				Reserve(Count + (Count / 2));

			_data[Count] = elem;
			Count = Count + 1;
		}


		public T PopBack()
		{
			Count = Count - 1;
			T r = _data[Count];
			return r;
		}


		public void Reserve(int need)
		{
			if (need <= Cap)
				return;

			T[] tmp = new T[need];

			for (int i = 0; i < Count; ++i)
				tmp[i] = _data[i];

			_data = tmp;
			Cap = need;
		}

	}


}



