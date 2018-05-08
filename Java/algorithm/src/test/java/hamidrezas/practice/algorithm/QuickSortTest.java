package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import java.util.Arrays;

public class QuickSortTest extends TestCase {
    public QuickSortTest(String testName) {
	super(testName);
    }

    public static Test suite() {
	return new TestSuite(QuickSortTest.class);
    }

    public void testInsertionSort() {
        int[] array = {2, 3, 1, 5, 2, 5};
        int[] expected = {1, 2, 2, 3, 5, 5};
        QuickSort.run(array);
        assertTrue(Arrays.equals(array, expected));
    }
}
