package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

public class LongestSubstringTest extends TestCase {
    public LongestSubstringTest(String testName) {
        super(testName);
    }

    public static Test suite() {
	return new TestSuite(LongestSubstringTest.class);
    }

    public void test() {
        assertTrue(LongestSubstring.run("aabcccdef").equals("cdef"));
        assertTrue(LongestSubstring.run("abcdabcdabcdabcde").equals("abcde"));
        assertTrue(LongestSubstring.run("fffffacdgggg").equals("facdg"));
        assertTrue(LongestSubstring.run("hamidreza").equals("hamidrez"));
    }
}
