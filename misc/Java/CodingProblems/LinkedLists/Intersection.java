package LinkedLists;
//So first, get the tail of both
//check if that tail is the same for each (address not the value)
//Find the shorter of the two lists
//subtract to find the difference in lengths - N
//set longer = to its Nth node in
//1 2 a b c d e f
//	    g y d e f
public class Intersection {
	public LinkedListNode findIntersection(LinkedListNode list1, LinkedListNode list2)
	{
		if(list1 == null || list2 == null) return null;
		Result result1 = getTailAndLength(list1);
		Result result2 = getTailAndLength(list2);
		
		if(result1.tail != result2.tail)
			return null;
		
		LinkedListNode shorter = result1.length < result2.length ? list1 : list2;
		LinkedListNode longer = result1.length < result2.length ? list2 : list1;
		
		longer = getKthNode(longer, Math.abs(result1.length - result2.length));
		
		while(shorter != longer){
			shorter = shorter.next;
			longer = longer.next;
		}
		
		return longer;
	}
	
	class Result{
		public LinkedListNode tail;
		public int length;
		public Result(LinkedListNode tail, int length)
		{
			this.tail = tail;
			this.length = length;
		}
	}
	
	Result getTailAndLength(LinkedListNode list){
		if(list == null) return null;
		int length = 1;
		
		LinkedListNode current = list;
		while (current.next != null)
		{
			length++;
			current = current.next;
		}
		return new Result(current, length);
	}
	
	LinkedListNode getKthNode(LinkedListNode head, int k){
		LinkedListNode current = head;
		while(k>0 && current != null){
			current = current.next;
			k--;
		}
		return current;
	}
}
