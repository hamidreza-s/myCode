package hamidrezas.practice.algorithm;

// run-time: O(n^2)

import java.util.NavigableMap;
import java.util.TreeMap;

public class LaserMatrix {
    public static String run(int n, boolean[][] input) {

        NavigableMap<Integer, String> map = new TreeMap<Integer, String>();

        for(int i = 0; i < n; i++) {
            int horizontalCount = 0;
            int verticalCount = 0;
            for(int j = 0; j < n; j++) {
                if(input[i][j]) horizontalCount++;
                if(input[j][i]) verticalCount++;
            }
            map.put(horizontalCount, "h" + i);
            map.put(verticalCount, "v" + i);
        }

        return map.lastEntry().getValue();
    }
}
