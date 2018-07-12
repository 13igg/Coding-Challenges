package LinkedLists;
//take two linked lists
//one called head which will be the lesser half
//one called tail which will be the greater half
//

/*public class PartitionLinkedList {
	public LinkedListNode partition(LinkedListNode node, int x) {
		LinkedListNode head = node;
		LinkedListNode tail = node;
		
		while(node != null) {
			LinkedListNode next = node.next;
			if(node.data < x){
				node.next = head;
				head = node;
			}
			else
			{
				tail.next = node;
				tail = node;
			}
			node = next;
		}
		tail.next = null;
		return head;
	}
}*/

public class PartitionLinkedList {
	public LinkedListNode partition(LinkedListNode node, int x) {
	    LinkedListNode beforeHead = null;
	    LinkedListNode beforeTail = null;
	    LinkedListNode afterHead = null;
	    LinkedListNode afterTail = null;
	    
	    while(node != null){
	    	LinkedListNode next = node.next;
	    	node.next = null;
	        if(node.data < x){
	            if(beforeHead == null)
	            	{
	            		beforeHead = node;
	            		beforeTail = beforeHead;
	            	}
	            else
	            {
	            	beforeTail.next = node;
	            	beforeTail = node;
	            }
	        }
	        else{
	        	if(afterHead == null)
            	{
	        		afterHead = node;
            		afterTail = afterHead;
            	}
	            else
	            {
	            	afterTail.next = node;
	            	afterTail = node;
	            }
	        }
        	node = next;
	    }
	    if(beforeTail == null){return afterHead;}
	    beforeTail.next = afterHead;
	    return beforeHead;
	}
}

