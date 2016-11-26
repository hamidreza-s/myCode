package algorithm.unionfind;

import algorithm.Utils;
import org.junit.Assert;
import org.junit.Test;

public class QuickUnion {

    private int[] id;

    public QuickUnion(int N) {
        id = new int[N];
        for (int i = 0; i < N; i++) id[i] = i;
    }

    private int root(int i) {
        while (i != id[i]) i = id[i];
        return i;
    }

    public boolean connected(int p, int q) {
        return root(p) == root(q);
    }

    public void union(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

    @Test
    public static void test() throws AssertionError {

        QuickUnion quickUnion = new QuickUnion(10);

        quickUnion.union(4, 3);
        quickUnion.union(3, 8);
        quickUnion.union(6, 5);
        quickUnion.union(9, 4);
        quickUnion.union(2, 1);

        try {

            Assert.assertTrue(quickUnion.connected(8, 9));
            Assert.assertFalse(quickUnion.connected(0, 7));
            Utils.print(QuickUnion.class.getName() + " passed!");

        } catch (AssertionError exception) {

            Utils.print(QuickUnion.class.getName() + " failed: " + exception.toString());

        }

    }

}
