import scala.annotation.tailrec
import scala.collection.mutable
import scala.collection.mutable.{Map => MutableMap}

object Main {
  case class TreeNode(value: Int = 0, left: TreeNode = null, right: TreeNode = null)

  def main(args: Array[String]): Unit = {
    val input = TreeNode(
      value = 1,
      left = TreeNode(
        value = 2
      ),
      right = TreeNode(
        value = 3,
        left = TreeNode(
          value = 4
        ),
        right = TreeNode(
          value = 5
        )
      )
    )
    val q1 = mutable.Queue[Int]()
    dfsPreOrder(input, q1)
    println(q1)

    val q2 = mutable.Queue[Int]()
    dfsPostOrder(input, q2)
    println(q2)

    val q3 = mutable.Queue[Int]()
    dfsInOrder(input, q3)
    println(q3)
  }

  def dfsPreOrder(root: TreeNode, q: mutable.Queue[Int]): Unit = {
    if (root == null) return
    q.enqueue(root.value)
    dfsPreOrder(root.left, q)
    dfsPreOrder(root.right, q)
  }

  def dfsPostOrder(root: TreeNode, q: mutable.Queue[Int]): Unit = {
    if (root == null) return
    dfsPostOrder(root.left, q)
    dfsPostOrder(root.right, q)
    q.enqueue(root.value)
  }

  def dfsInOrder(root: TreeNode, q: mutable.Queue[Int]): Unit = {
    if (root == null) return
    dfsInOrder(root.left, q)
    q.enqueue(root.value)
    dfsInOrder(root.right, q)
  }


  def reverse(l: List[Int]): List[Int] = reverse(l, List())

  @tailrec
  def reverse(l: List[Int], state: List[Int]): List[Int] = l match {
    case head :: tail => reverse(tail, head :: state)
    case Nil => state
  }

  def leftRotation(l: List[Int], d: Int): List[Int] = {
    val (left, right) = l.splitAt(d)
    right ::: left
  }

  def quickSort(l: List[Int]): List[Int] = l match {
    case Nil => Nil
    case head :: tail =>
      val (lessThan, moreThan) = tail.partition(_ < head)
      quickSort(lessThan) ::: List(head) ::: quickSort(moreThan)
  }

  def search(array: Array[Int], query: Int): Boolean =
    search(array, query, 0, array.length - 1)

  @tailrec
  def search(array: Array[Int], query: Int, low: Int, high: Int): Boolean = {
    if (low > high) return false

    val middle = low + (high - low) / 2
    val value = array(middle)

    if (value == query) true
    else if (value > query) search(array, query, low, middle - 1)
    else search(array, query, middle + 1, high)
  }

  def sortedMerge(a: List[Int], b: List[Int]): List[Int] = (a, b) match {
    case (Nil, Nil) => Nil
    case (_ :: _, Nil) => a
    case (Nil, _ :: _) => b
    case (x :: xs, y :: ys) =>
      if (x <= y)
        x :: sortedMerge(xs, y :: ys)
      else
        y :: sortedMerge(x :: xs, ys)
  }


  def sortedMerge2(a: Array[Int], b: Array[Int]): Array[Int] = {
    val result = mutable.ListBuffer[Int]()
    var i = 0
    var j = 0
    while (i < a.length) {
      if (a(i) < b(j)) {
        result.addOne(a(i))
        i += 1
      } else if (a(i) > b(j)) {
        result.addOne(b(j))
        j += 1
      } else {
        result.addOne(a(i))
        result.addOne(b(j))
        i += 1
        j += 1
      }
    }

    while (j < b.length) {
      result.addOne(b(j))
      j += 1
    }

    result.toArray
  }

  @tailrec
  def removeDuplicates(l: List[Int], s: List[Int] = List()): List[Int] = l match {
    case h1 :: h2 :: t if h1 == h2 => removeDuplicates(h2 :: t, s)
    case h :: t => removeDuplicates(t, h :: s)
    case Nil => s.reverse
  }

  def mutableCountFrequency(l: List[Int]): MutableMap[Int, Int] = {
    val map = MutableMap.empty[Int, Int]
    l.foreach(x =>
      map.update(x, map.getOrElse(x, 0) + 1)
    )
    map
  }

  def immutableCountFrequency(l: List[Int]): Map[Int, Int] = {
    l.foldLeft(Map.empty[Int, Int])((acc, x) => {
      acc ++ Map(x -> (acc.getOrElse(x, 0) + 1))
    })
  }

  def twoSums(l: List[Int], target: Int): (Int, Int) = {
    (for {
      (x, xi) <- l.zipWithIndex
      (y, yi) <- l.zipWithIndex
      if (x + y) == target && (xi != yi)
    } yield (xi, yi)).head
  }

  def twoSumsOptimized(array: Array[Int], target: Int): Boolean = {
    val set = scala.collection.mutable.HashSet[Int]()
    var i = 0
    while (i < array.length) {
      val value = array(i)
      if (set(target - value)) return true
      set.add(value)
      i += 1
    }
    false
  }

  def maxMin(l: List[Int]): (Int, Int) = maxMin(l, 0, l.length - 1)

  def maxMin(l: List[Int], left: Int, right: Int): (Int, Int) = {

    if (left == right) return (l(left), l(right))
    if (left == right + 1) {
      if (l(left) > l(right)) return (l(left), l(right))
      else return (l(right), l(left))
    }

    val middle = left + ((right - left) / 2)
    val (leftMax, leftMin) = maxMin(l, left, middle)
    val (rightMax, rightMin) = maxMin(l, middle + 1, right)

    val max = if (leftMax > rightMax) leftMax else rightMax
    val min = if (leftMin < rightMin) leftMin else rightMin

    (max, min)
  }

  def findMissingNumber(l: List[Int]): Int = {
    (1 to l.length + 1).sum - l.sum
  }
}
