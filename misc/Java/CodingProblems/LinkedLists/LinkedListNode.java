package LinkedLists;

public class LinkedListNode {
	public LinkedListNode next = null;
	public int data;
	public LinkedListNode(int d)
	{
		data = d;
	}

	public LinkedListNode()
	{
	}
	public void appendToTail(int d)
	{
		LinkedListNode end = new LinkedListNode(d);
		LinkedListNode n = this;
		while(n.next != null) {
			n = n.next;
		}
		n.next = end;
	}
	
	public String toString()
	{
		StringBuilder sb = new StringBuilder();
		LinkedListNode n = this;
		while(n.next != null)
		{
			sb.append(n.data);
			n = n.next;
		}
		sb.append(n.data);
		return sb.toString();
	}
	
	LinkedListNode deleteLinkedListNode(LinkedListNode head, int d)
	{
		LinkedListNode n = head;
		if(n.data == d)
		{
			return head.next;
		}
		
		while(n.next != null)
		{
			if(n.next.data == d)
			{
				n.next = n.next.next;
				return head;
			}
			n = n.next;
		}
		return head;
	}
}
