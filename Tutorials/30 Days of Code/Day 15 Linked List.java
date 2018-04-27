public static  Node insert(Node head,int data) {
    //Complete this method
    Node node = new Node(data);
    if (head == null) {
        return node;
    } else {
        Node tail = head;
        while (tail.next != null) {
            tail = tail.next;
        }
        tail.next = node;
        return head;
    }
}
