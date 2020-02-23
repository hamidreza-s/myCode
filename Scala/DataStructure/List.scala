class LinkedList[T] {

  import scala.collection.mutable.ListBuffer

  case class Node[T](var value: T, var next: Option[Node[T]])
  
  var head: Option[Node[T]] = None

  def add(value: T) {
    val cache = head
    this.head = Some(Node(value, cache))
  }

  def delete(value: T): Unit = {

    if (head.isEmpty) return

    if (head.get.value == value) {
      head = head.get.next
      return
    }

    var curr = head

    while (curr.get.next.isDefined) {
      if (curr.get.next.get.value == value) {
        curr.get.next = curr.get.next.flatMap(_.next)
        return
      }
      curr = curr.get.next
    }

  }

  def toList: List[T] = {
    @scala.annotation.tailrec
    def loop(self: Option[Node[T]], acc: List[T]): List[T] = {
      self match {
        case Some(Node(value, Some(next))) => loop(Some(next), value :: acc)
        case Some(Node(value, None)) => value :: acc
        case None => acc
      }
    }
    loop(head, Nil)
  }
  
  def toListBuffer: ListBuffer[T] = {
    var current = head
    val result = ListBuffer.empty[T]

    while (current.isDefined) {
      result.append(current.get.value)
      current = current.get.next
    }

    result
  }

  override def toString: String = toList.toString
}
