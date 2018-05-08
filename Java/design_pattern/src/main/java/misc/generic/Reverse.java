class Reverse {
    public static <T> T[] apply(T[] data) {

	int lowerIndex = 0;
	int higherIndex = data.length - 1;

	while (lowerIndex < higherIndex) {
	    T tmpValue = data[lowerIndex];
	    data[lowerIndex] = data[higherIndex];
	    data[higherIndex] = tmpValue;

	    lowerIndex++;
	    higherIndex--;
	}

	return data;
    }
}
