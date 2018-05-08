package hamidrezas.practice.algorithm;

// run-time: O(n^2 * n!)

import java.util.List;
import java.util.ArrayList;

public class Permutation {

        public static List<String> run(String string) {
        List<String> result = new ArrayList<String>();
        String prefix = "";

        permutation(string, prefix, result);

        return result;
    };

    public static void permutation(String string, String prefix, List<String> result) {
	
        if(string.length() == 0) result.add(prefix);
        else {

            for(int i = 0; i < string.length(); i++) {

                String newString = exclude(i, string);
                String newPrefix = prefix + string.charAt(i);

                permutation(newString, newPrefix, result);

            }
        }
    }
    
    public static String exclude(int index, String str) {
        return str.substring(0, index) + str.substring(index + 1);
    }

}
