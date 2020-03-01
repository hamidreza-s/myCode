package functional.data.structure

case class Queue[+A](in: List[A] = Nil, out: List[A] = Nil) {
  def isEmpty: Boolean = in.isEmpty && out.isEmpty

  /**
   * Time: O(1)
   * Space: O(1)
   */
  def enqueue[B >: A](x: B): Queue[B] = new Queue(x :: in, out)

  /**
   * Time: O(1) - amortized complexity
   * Space: O(1) - amortized complexity
   */
  def dequeue: (A, Queue[A]) = out match {
    case hd :: tl => (hd, new Queue(in, tl))
    case Nil => in.reverse match {
      case hd :: tl => (hd, new Queue(Nil, tl))
      case Nil => throw new NoSuchElementException("Empty queue")
    }
  }

  /**
   * Time: O(1) - amortized complexity
   * Space: O(1) - amortized complexity
   */
  def front: A = dequeue match { case (a, _) => a }

  /**
   * Time: O(1) - amortized complexity
   * Space: O(1) - amortized complexity
   */
  def rear: Queue[A] = dequeue match { case (_, q) => q }
}

object Queue {
  def empty[A]: Queue[A] = new Queue()

  def apply[A](xs: A*): Queue[A] =
    xs.foldLeft(Queue.empty[A]) { case (acc, x) => acc.enqueue(x) }
}

