package algorithm.unionfind;

import algorithm.Utils;
import org.junit.Assert;
import org.junit.Test;

public class QuickFind {

    private int[] id;

    public QuickFind(int N) {
        id = new int[N];
        for (int i = 0; i < N; i++) id[i] = i;
    }

    public boolean connected(int p, int q) {
        return id[p] == id[q];
    }

    public void union(int p, int q) {
        int pid = id[p];
        int qid = id[q];
        for (int i = 0; i < id.length; i++)
            if (id[i] == pid) id[i] = qid;
    }

    @Test
    public static void test() throws AssertionError {

        QuickFind quickFind = new QuickFind(10);

        quickFind.union(4, 3);
        quickFind.union(3, 8);
        quickFind.union(6, 5);
        quickFind.union(9, 4);
        quickFind.union(2, 1);

        try {

            Assert.assertTrue(quickFind.connected(8, 9));
            Assert.assertFalse(quickFind.connected(0, 7));
            Utils.print(QuickFind.class.getName() + " passed!");

        } catch (AssertionError exception) {

            Utils.print(QuickFind.class.getName() + " failed: " + exception.toString());

        }
    }

}