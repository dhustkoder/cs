package src.java.algorithms.searching;
import java.util.*;


public interface SearchingAlgorithm {
	public <T extends Comparable<T>> T execute(final List<T> data, final T target);
}
