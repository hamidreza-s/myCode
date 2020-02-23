object VeryBigSum {
  def calculate(ar: Array[Long]): Long = {

    ar.foldLeft(BigDecimal(0)) {
      case (acc, item) => acc + BigDecimal(item)
    }.toLong

  }
}

object LeftRotation {
  def rotate(a: Array[Int], d: Int): Array[Int] = {
    a.takeRight(a.size - d) ++ a.take(d)
  }
}

object PdfViewer {
  def calculate(h: Array[Int], word: String): Int = {

    val hights: Map[Char, Int] = ('a' to 'z').toList.zip(h.toList).toMap

    val (hight, width) = word.foldLeft((0, 0)) {
      case ((hight, width), char) => {
        val newHight = if (hight > hights(char)) hight else hights(char)
        val newWidth = width + 1

        (newHight, newWidth)
      }
    }

    hight * width
  }
}
