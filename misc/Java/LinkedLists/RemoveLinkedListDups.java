package LinkedLists;
import java.util.HashSet;
//remove dups
//use a hashset
//store the previous node
//if the set contains next's data, set previous.next = next
//else, add the data to the set 

//remove dups with no buffer
//take current, and then
//use a runner that checks ahead the list
//set the next = to that next

//O(n) time - one pass through the linked list
public class RemoveLinkedListDups {
	public void RemoveDups(LinkedListNode n)
	{
		HashSet<Integer> set = new HashSet<Integer>();
		LinkedListNode previous = null;
		while(n != null)
		{
			if(set.contains(n.data))
				previous.next = n.next;
			else
			{
				set.add(n.data);
				previous = n;
			}
			n = n.next;
		}
	}
//************************************************************************	
	public void RemoveDupsNoBuffer(LinkedListNode head)
	{
		LinkedListNode current = head;
		while(current != null)
		{
			LinkedListNode runner = current;
			while(runner.next != null)
			{
				if(runner.next.data == current.data)
					runner.next = runner.next.next;
				else
					runner = runner.next;				
			}
			current = current.next;
		}
	}
}

	
	
			
			
			
			