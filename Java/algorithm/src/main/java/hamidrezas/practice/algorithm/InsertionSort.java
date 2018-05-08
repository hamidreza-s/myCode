package hamidrezas.practice.algorithm;

// run-time: O(n^2)

public class InsertionSort {
    public static void run(int[] input) {
        int n = input.length;
        for (int i=1; i<n; ++i)
        {
            int key = input[i];
            int j = i-1;

            while (j >= 0 && input[j] > key)
            {
                input[j+1] = input[j];
                j = j-1;
            }
            input[j+1] = key;
        }
    }
}
