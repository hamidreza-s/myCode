package hamidrezas.practice.algorithm;

// run-time: O(n log n)

public class QuickSort {
    public static void run(int[] input) {
        int low = 0;
        int high = input.length-1;
        sort(input, low, high);
    }

    public static void sort(int[] input, int low, int high) {
        if(low < high) {
            int pi = partition(input, low, high);

            sort(input, low, pi-1);
            sort(input, pi+1, high);
        }
    }

    public static int partition(int[] input, int low, int high) {

        int pivot = input[high];
        int i = low-1;
        for(int j = low; j < high; j++) {
            if(input[j] <= pivot) {
                i++;

                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }

        int temp = input[i+1];
        input[i+1] = input[high];
        input[high] = temp;

        return i+1;

    }
}
