package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import java.util.Arrays;

public class BinarySearchTest extends TestCase {
    public BinarySearchTest(String testName) {
	super(testName);
    }

    public static Test suite() {
	return new TestSuite(BinarySearchTest.class);
    }

    public void testInsertionSort() {
        int[] array = {1, 2, 4, 6, 8, 10, 14, 20, 32};
        assertEquals(0, BinarySearch.run(array, 1));
        assertEquals(1, BinarySearch.run(array, 2));
        assertEquals(2, BinarySearch.run(array, 4));
        assertEquals(3, BinarySearch.run(array, 6));
        assertEquals(4, BinarySearch.run(array, 8));
    }
}
