package hamidrezas.practice.algorithm;

// run-time: O(n)

public class Factorial {
    public static int run(int n) {
	if(n < 0) return -1;
	if(n == 0) return 1;
	return n * run(n - 1);
    }
}
