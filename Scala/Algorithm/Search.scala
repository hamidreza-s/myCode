object Search {

  def binarySearch(a: List[Int], target: Int): Int = binarySearch(a, target, 0, a.size - 1)
  def binarySearch(a: List[Int], target: Int, lo: Int, hi: Int): Int = {

    if (hi < lo) return -1

    val mid = (hi - lo) / 2 + lo

    target match {
      case t if t < a(mid) => binarySearch(a, target, lo, mid - 1)
      case t if t > a(mid) => binarySearch(a, target, mid + 1, hi)
      case t if t == a(mid) => mid
    }
  }

}
