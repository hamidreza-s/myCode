package hamidrezas.practice.algorithm;

// run-time: O(n^2)


import java.util.*;

public class LongestSubstring {
    public static String run(String input) {
        String output = "";
        List<String> substrings = new ArrayList<String>();

        // triangular numbers:
        // n + (n-1) + (n-2) + ... + 1 = 1 + 2 + 3 + ... + n
        // run-time: O(n * (n+1)/2) = O(n^2)
        for(int i = 0; i <= input.length(); i++) {
            for(int j = i + 1; j <= input.length(); j++) {
                String substring = input.substring(i, j);
                substrings.add(substring);
            }
        }

        // run-time: O(n)
        for(String s : substrings) {
            if(!hasDuplicate(s))
                if(s.length() > output.length())
                    output = s;
        }

        return output;
	}

	public static boolean hasDuplicate(String input) {
        HashSet<Character> usedCharacters = new HashSet<Character>();
        boolean result = false;

        // run-time: O(n)
        for(char c : input.toCharArray()) {
            if(usedCharacters.contains(c)) {
                result = true;
                break;
            } else {
                usedCharacters.add(c);
            }
        }

        return result;
    }
}
