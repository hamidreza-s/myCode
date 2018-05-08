package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

public class SumDigitsTest extends TestCase {
    public SumDigitsTest(String testName) {
	super(testName);
    }

    public static Test suite() {
	return new TestSuite(SumDigitsTest.class);
    }

    public void testSumDigits() {
	assertEquals(SumDigits.run(100), 1);
	assertEquals(SumDigits.run(111), 3);
	assertEquals(SumDigits.run(333), 9);
    }
}
