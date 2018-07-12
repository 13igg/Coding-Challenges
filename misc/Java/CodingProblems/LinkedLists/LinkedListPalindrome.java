package LinkedLists;

import java.util.Stack;
//two possible solutions
//1 compare reverse with head
//2 make a stack
//push the first half to the stack
//then pop and check with second half
public class LinkedListPalindrome {
	//***************************
	public boolean IsPalindrome(LinkedListNode head)
	{
		System.out.println(head.toString());
		LinkedListNode reversed = reverse(head);
		System.out.println(reversed.toString());
		return equality(reversed,head);
	}
	
	boolean equality(LinkedListNode a, LinkedListNode b)
	{
		while(a != null && b!= null)
		{
			if(a.data != b.data)
				return false;
			a = a.next;
			b = b.next;
		}
		return a == null && b == null;		
	}
	
	LinkedListNode reverse(LinkedListNode node)
	{
		LinkedListNode head = null;
		while(node != null)
		{
			LinkedListNode n = new LinkedListNode(node.data);
			n.next = head;
			head = n;
			node = node.next;
		}
		return head;
	}
	//*******************************
	
	//using a stack
	public boolean isPalindrome2(LinkedListNode head)
	{
		LinkedListNode fast = head;
		LinkedListNode slow = head;
		
		Stack<Integer> stack = new Stack<Integer>();
		
		while(fast != null && fast.next != null)
		{
			stack.push(slow.data);
			slow = slow.next;
			fast = fast.next.next;
		}
		
		if(fast != null)
			slow = slow.next;
		
		while(slow != null){
			int top = stack.pop().intValue();
			
			if(top != slow.data)
				return false;
			
			slow = slow.next;
		}
		return true;
	}
}
