package hamidrezas.practice.algorithm;

// run-time: O(log n)

public class BinarySearch {
    public static int run(int[] input, int query) {
        int left = 0;
        int right = input.length-1;
        return search(input, left, right, query);
    }

    public static int search(int input[], int left, int right, int query)
    {
        if (right >= left)
        {
            int mid = left + (right - left)/2;

            if (input[mid] == query)
                return mid;

            if (input[mid] > query)
                return search(input, left, mid-1, query);

            return search(input, mid+1, right, query);
        }

        return -1;
    }
}
