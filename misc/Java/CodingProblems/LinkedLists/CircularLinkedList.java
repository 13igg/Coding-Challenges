package LinkedLists;	

//move one slow and one fast
//when fast = slow, reset slow to beginning
//move fast and slow at the same rate
//when they equal eachother, we are done. 
public class CircularLinkedList {
	public LinkedListNode FindCollision(LinkedListNode head)
	{
		LinkedListNode slow = head;
		LinkedListNode fast = head;
				
		while(fast != null && fast.next != null && slow!=fast)
		{			
			slow = slow.next;
			fast = fast.next.next;
			if(slow == fast)
				break;
		}
		
		if(fast == null || fast.next == null)
			return null;
		
		slow = head;
		while(fast != slow)
		{
			fast = fast.next;
			slow = slow.next;
		}
		
		return fast;
	}
}
