package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

public class LaserMatrixTest extends TestCase {
    public LaserMatrixTest(String testName) {
	super(testName);
    }

    public static Test suite() {
	return new TestSuite(LaserMatrixTest.class);
    }

    public void test() {

        boolean[][] input = {
                {false, false, true, false},
                {false, false, false, true},
                {true, false, true, false},
                {false, true, true, false}
        };
        assertTrue(LaserMatrix.run(4, input).equals("v2"));

    }
}
