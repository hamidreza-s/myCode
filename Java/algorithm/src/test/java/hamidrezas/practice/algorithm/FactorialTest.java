package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

public class FactorialTest extends TestCase {
    public FactorialTest(String testName) {
        super(testName);
    }

    public static Test suite() {
	return new TestSuite(FactorialTest.class);
    }

    public void testFactorial() {

	assertEquals(Factorial.run(-1), -1);
	assertEquals(Factorial.run(0), 1);
	assertEquals(Factorial.run(1), 1);
	assertEquals(Factorial.run(2), 2);
	
    }
}
