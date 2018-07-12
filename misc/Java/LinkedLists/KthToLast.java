package LinkedLists;

//lets do this iteratively first
//take two nodes, set them both = head
//move p1 k nodes in
//move p1 and p2 until p1 is null
//p2 is now k nodes from the end

public class KthToLast {
	//recursive
	public int printKthToLast(LinkedListNode head, int k)
	{
		if(head == null)
			return 0;
		int index = printKthToLast(head.next, k) + 1;
		if(index == k)
			System.out.println(k + "th to last node is: " + head.data);
		return index;
	}
	
	//O(n) time
	//O(1) space
	//iteratively
	public LinkedListNode kthToLast(LinkedListNode head, int k)
	{
		LinkedListNode p1 = head;
		LinkedListNode p2 = head;
		
		for(int i = 0; i < k ;i++)
		{
			if(p1==null) return null;
			p1 = p1.next;
		}
		
		while (p1 != null)
		{
			p1 = p1.next;
			p2 = p2.next;
		}
		return p2;
	}
}
