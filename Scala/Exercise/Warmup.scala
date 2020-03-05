object SockMerchant {

  def count(n: Int, ar: Array[Int]): Int = {

    val map = ar.foldLeft(Map.empty[Int, Int]) {
      case (acc: Map[Int, Int], item: Int) => {
        val count = acc.getOrElse(item, 0) + 1
        acc + (item -> count)
      }
    }

    val result = map.foldLeft(0) {
      case (acc: Int, (key: Int, value: Int)) => acc + (value / 2)
    }

    result
  }

}

object CountingValleys {

  def count(n: Int, s: String): Int = {

    var inValley = false
    var valleys  = 0
    var alltitude = 0

    s.foreach { i =>
      if (i == 'U') { alltitude += 1 }
      if (i == 'D') { alltitude -= 1 }

      if (alltitude == 0 && inValley == true) { inValley = false; valleys += 1 }
      if (alltitude == -1) { inValley = true }
    }

    valleys
  }

}

object JumbingOnClouds {

  def jumpingOnClouds(c: Array[Int]): Int = {

    var jumbs = 0
    var pos = 0

    while (pos < c.size) {
      if ((pos + 2) < c.size && c(pos + 2) == 0) { jumbs += 1; pos += 2 }
      else if ((pos + 1) < c.size && c(pos + 1) == 0) { jumbs += 1; pos += 1 }
      else { pos += 1 }
    }

    jumbs
  }

}

object RepeatedString {

  def countA(s: String, n: Long): Long = {
    val fullSize = n
    val eachSize = s.size
    val tailSize = n % s.size
    val headSize = n - tailSize

    val countInEach = countA(s)
    val countInTail = countA(s.take(tailSize.toInt))
    val countInFull = (countInEach * (headSize / eachSize)) + (countInTail)

    countInFull
  }

  def countA(s: String): Int = s.foldLeft(0) {
    case (acc, 'a') => acc + 1
    case (acc, _)   => acc
  }

}



object MaxDiff {
  case class TreeNode(value: Int, left: Option[TreeNode], right: Option[TreeNode])

  def maxDiff(root: TreeNode): Int = maxDiff(Some(root), root.value, root.value)
  def maxDiff(root: Option[TreeNode], min: Int, max: Int): Int = {

    root match {
      case None => max - min
      case Some(current) =>

        val newMin = current.value.min(min)
        val newMax = current.value.max(max)

        val left = maxDiff(current.left, newMin, newMax)
        val right = maxDiff(current.right, newMin, newMax)

        left.max(right)
    }
  }
}
