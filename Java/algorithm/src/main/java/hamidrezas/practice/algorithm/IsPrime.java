package hamidrezas.practice.algorithm;

// run-time: O(√n)

public class IsPrime {
    public static boolean run(int n) {
	if(n < 2) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;

	for(int i = 3; i <= Math.sqrt(n); i++) {
	    if(n % i == 0)
		return false;
	}

	return true;
    }
}
