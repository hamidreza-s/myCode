package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import java.util.List;
import java.util.Arrays;

public class FibonacciTest extends TestCase {
    public FibonacciTest(String testName) {
	super(testName);
    }

    public static Test suite() {
	return new TestSuite(FibonacciTest.class);
    }

    public void testFibonacci() {
	assertEquals(Fibonacci.run(1), 1);
	assertEquals(Fibonacci.run(2), 1);
	assertEquals(Fibonacci.run(3), 2);
	assertEquals(Fibonacci.run(4), 3);
	assertEquals(Fibonacci.run(5), 5);
	assertEquals(Fibonacci.run(6), 8);
    }
}
