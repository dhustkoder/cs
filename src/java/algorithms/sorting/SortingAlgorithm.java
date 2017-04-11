package src.java.algorithms.sorting;
import java.util.*;


public interface SortingAlgorithm {
	public <T extends Comparable<T>> void execute(List<T> data);
}
