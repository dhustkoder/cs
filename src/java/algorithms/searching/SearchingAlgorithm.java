package src.java.algorithms.searching;
import src.java.data_structures.*;
import java.util.*;


public interface SearchingAlgorithm 
{
	public <T extends Comparable<T>> int execute(final DataStructure<T> data, final T target);
}
