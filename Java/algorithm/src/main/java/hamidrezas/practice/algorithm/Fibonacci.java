package hamidrezas.practice.algorithm;

// run-time: O(2^n)

public class Fibonacci {
    public static int run(int n) {
	if(n <= 0) return 0;
	if(n == 1) return 1;
	return run(n - 1) + run(n - 2);
    }
}
