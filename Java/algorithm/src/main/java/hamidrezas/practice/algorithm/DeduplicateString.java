package hamidrezas.practice.algorithm;

// run-time: O(n)

import java.util.HashSet;

public class DeduplicateString {
    public static String run(String input) {

        HashSet<Character> usedCharacters = new HashSet<Character>();
		String output = "";

		for(char c : input.toCharArray()) {
            if(!usedCharacters.contains(c)) {
                output += c;
                usedCharacters.add(c);
            }
		}

		return output;
	}
}
