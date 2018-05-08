package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

public class DeduplicateStringTest extends TestCase {
    public DeduplicateStringTest(String testName) {
        super(testName);
    }

    public static Test suite() {
	return new TestSuite(DeduplicateStringTest.class);
    }

    public void test() {

        assertTrue(DeduplicateString.run("aabbcccddddd").equals("abcd"));
        assertTrue(DeduplicateString.run("abcdabcdabcd").equals("abcd"));
        assertTrue(DeduplicateString.run("hamidreza").equals("hamidrez"));

    }
}
