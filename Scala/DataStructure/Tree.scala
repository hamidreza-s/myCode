package functional.data.structure

import scala.annotation.tailrec

abstract sealed class Tree[+A <% Ordered[A]] {
  def value: A
  def left: Tree[A]
  def right: Tree[A]
  def isEmpty: Boolean

  /**
   * Time: O(log n)
   * Space: O(log n)
   */
  def add[B >: A <% Ordered[B]](x: B): Tree[B] =
    if (isEmpty) Branch(x)
    else if (x < value) Branch(value, left.add(x), right)
    else if (x > value) Branch(value, left, right.add(x))
    else this

  /**
   * Time: O(log n)
   * Space: O(log n)
   */
  def remove[B >: A <% Ordered[B]](x: B): Tree[B] =
    if (isEmpty) throw new NoSuchElementException("Empty tree")
    else if (x < value) Branch(value, left.remove(x), right)
    else if (x > value) Branch(value, left, right.remove(x))
    else {
      if (left.isEmpty && right.isEmpty) Leaf
      else if (left.isEmpty) right
      else if (right.isEmpty) left
      else {
        val successor = right.min
        Branch(successor, left, right.remove(successor))
      }
    }

  /**
   * Time: O(log n)
   * Space: O(log n)
   */
  def max: A = {
    @tailrec
    def loop(t: Tree[A], v: A): A =
      if (t.isEmpty) v
      else loop(t.right, t.value)

    if (isEmpty) throw new NoSuchElementException("Empty tree")
    else loop(right, value)
  }

  /**
   * Time: O(log n)
   * Space: O(log n)
   */
  def min: A = {
    @tailrec
    def loop(t: Tree[A], v: A): A =
      if (t.isEmpty) v
      else loop(t.left, t.value)

    if (isEmpty) throw new NoSuchElementException("Empty tree")
    else loop(left, value)
  }
}

case object Leaf extends Tree[Nothing] {
  def value: Nothing = throw new NoSuchElementException("Empty tree")
  def left: Tree[Nothing] = throw new NoSuchElementException("Empty tree")
  def right: Tree[Nothing] = throw new NoSuchElementException("Empty tree")
  def isEmpty: Boolean = true
}

case class Branch[A <% Ordered[A]](value: A,
                                   left: Tree[A] = Leaf,
                                   right: Tree[A] = Leaf,
                                   isEmpty: Boolean = false) extends Tree[A]

object Tree {
  def empty[A]: Tree[A] = Leaf
  def apply[A <% Ordered[A]](xs: A*): Tree[A] = create(xs.reverse, empty)

  @tailrec
  private def create[A <% Ordered[A]](xs: Seq[A], acc: Tree[A]): Tree[A] = xs match {
    case hd +: tl => create(tl, acc.add(hd))
    case Seq() => acc
  }
}
