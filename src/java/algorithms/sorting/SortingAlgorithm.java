package src.java.algorithms.sorting;
import src.java.data_structures.*;
import java.util.*;


public interface SortingAlgorithm 
{
	public <T extends Comparable<T>> void execute(DataStructure<T> data);
}
