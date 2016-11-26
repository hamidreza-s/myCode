package algorithm.unionfind;

        import algorithm.Utils;
        import org.junit.Assert;
        import org.junit.Test;

public class WeightedQuickUnion {

    private int[] id;
    private int[] sz;

    public WeightedQuickUnion(int N) {
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++) id[i] = i;
        for (int i = 0; i < N; i++) sz[i] = 1;
    }

    private int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]]; // Path Compression
            i = id[i];
        }
        return i;
    }

    public boolean connected(int p, int q) {
        return root(p) == root(q);
    }

    public void union(int p, int q) {
        int i = root(p);
        int j = root(q);

        if (i == j) return;

        if (sz[i] < sz[j]) {

            id[i] = j;
            sz[j] += sz[i];

        } else {

            id[j] = i;
            sz[i] += sz[j];

        }
    }

    @Test
    public static void test() throws AssertionError {

        WeightedQuickUnion weightedQuickUnion = new WeightedQuickUnion(10);

        weightedQuickUnion.union(4, 3);
        weightedQuickUnion.union(3, 8);
        weightedQuickUnion.union(6, 5);
        weightedQuickUnion.union(9, 4);
        weightedQuickUnion.union(2, 1);

        try {

            Assert.assertTrue(weightedQuickUnion.connected(8, 9));
            Assert.assertFalse(weightedQuickUnion.connected(0, 7));
            Utils.print(WeightedQuickUnion.class.getName() + " passed!");

        } catch (AssertionError exception) {

            Utils.print(WeightedQuickUnion.class.getName() + " failed: " + exception.toString());

        }

    }

}
