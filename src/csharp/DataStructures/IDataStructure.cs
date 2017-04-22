

namespace DataStructures
{
	
	public interface IDataStructure<T>
	{
		int Count { get; }
		T this[int index] { get; set; }

		T Get(int index);
		void Set(int index, T elem);

		void PushBack(T elem);
		T PopBack();

	}

}

