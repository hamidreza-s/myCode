package functional.data.structure

import scala.annotation.tailrec

abstract sealed class List[+A] {
  def head: A
  def tail: List[A]
  def isEmpty: Boolean

  /**
   * Time: O(1)
   * Space: O(1)
   */
  def prepend[B >: A](x: B): List[B] = Cons(x, this)

  /**
   * Time: O(n)
   * Space: O(n)
   */
  def append[B >: A](x: B): List[B] =
    if (isEmpty) Cons(x)
    else Cons(head, tail.append(x))

  /**
   * Time: O(n)
   * Space: O(n)
   */
  def apply(n: Int): A =
    if (isEmpty) throw new NoSuchElementException("Index out of range")
    else if (n == 0) head
    else tail(n - 1)

  /**
   * Time: O(n)
   * Space: O(n)
   */
  def concat[B >: A](xs: List[B]): List[B] =
    if (isEmpty) xs
    else tail.concat(xs).prepend(head)

  /**
   * Time: O(n)
   * Space: O(n)
   */
  def reverse: List[A] = {
    @tailrec
    def loop(s: List[A], d: List[A]): List[A] =
      if (s.isEmpty) d
      else loop(s.tail, d.prepend(s.head))
    loop(this, Nil)
  }

}

case object Nil extends List[Nothing] {
  def head: Nothing = throw new NoSuchElementException("Empty list")
  def tail: Nothing = throw new NoSuchElementException("Empty list")
  def isEmpty: Boolean = true
}

case class Cons[A](head: A, tail: List[A] = Nil) extends List[A] {
  def isEmpty: Boolean = false
}

case object List {
  def empty[A]: List[A] = Nil
  def apply[A](xs: A*): List[A] = create(xs.reverse, empty)

  @tailrec
  private def create[A](xs: Seq[A], acc: List[A]): List[A] = xs match {
    case hd +: tl => create(tl, acc.prepend(hd))
    case Seq() => acc
  }
}
