package hamidrezas.practice.algorithm;

// run-time:

public class SumDigits {
    public static int run(int n) {
	int sum = 0;
	while(n > 0) {
	    sum += n % 10;
	    n /= 10;
	    System.out.println(n);
	}
	return sum;
    }
}
