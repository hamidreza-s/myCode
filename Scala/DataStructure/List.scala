abstract sealed class List[+A] {
  def head: A
  def tail: List[A]
  def isEmpty: Boolean

  def prepend[B >: A](x: B): List[B] = Cons(x, this)

  def append[B >: A](x: B): List[B] =
    if (isEmpty) Cons(x)
    else Cons(head, tail.append(x))

  def apply(n: Int): A =
    if (isEmpty) throw new Exception("Index out of range")
    else if (n == 0) head
    else tail(n - 1)
}

case object Nil extends List[Nothing] {
  def head: Nothing = throw new Exception("empty list")
  def tail: Nothing = throw new Exception("empty list")
  def isEmpty: Boolean = true
}

case class Cons[A](head: A, tail: List[A] = Nil) extends List[A] {
  def isEmpty: Boolean = false
}

case object List {
  def empty[A]: List[A] = Nil
  def apply[A](xs: A*): List[A] = create(xs.reverse, empty)

  @scala.annotation.tailrec
  private def create[A](xs: Seq[A], acc: List[A]): List[A] = xs match {
    case head +: tail => create(tail, acc.prepend(head))
    case Seq() => acc
  }
}
