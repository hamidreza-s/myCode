object List {

  class SinglyLinkedListNode(
    var data: Int,
    var next: SinglyLinkedListNode = null
  )

  class SinglyLinkedList(
    var head: SinglyLinkedListNode = null,
    var tail: SinglyLinkedListNode = null
  )

  def insert(root: SinglyLinkedListNode, data: Int, position: Int)
      : SinglyLinkedListNode = {
    if (position == 0) return new SinglyLinkedListNode(data, root)

    var curr    = root
    var currPos = 0

    while (currPos != position - 1) {
      curr = curr.next
      currPos += 1
    }

    curr.next = new SinglyLinkedListNode(data, curr.next)
    root
  }

  def reverse(root: SinglyLinkedListNode): SinglyLinkedListNode = {

    var head: SinglyLinkedListNode = root
    var tail: SinglyLinkedListNode = null
    var temp: SinglyLinkedListNode = null

    while (head != null) {
      temp = head.next

      head.next = tail
      tail = head
      head = temp
    }

    tail
  }
}

