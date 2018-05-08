package hamidrezas.practice.algorithm;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import java.util.List;
import java.util.Arrays;

public class PermutationTest extends TestCase {
    public PermutationTest(String testName) {
	super(testName);
    }

    public static Test suite() {
	return new TestSuite(PermutationTest.class);
    }

    public void testPermutation() {

	List<String> expectedResult = Arrays.asList(new String[]{"abc", "acb", "bac",
								 "bca", "cab", "cba"});


	List<String> result = Permutation.run("abc");
	
	assertTrue(expectedResult.equals(result));
	assertEquals(expectedResult.size(), result.size());
    }
}
