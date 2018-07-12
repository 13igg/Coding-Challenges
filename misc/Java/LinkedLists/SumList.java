package LinkedLists;
//6 1 7
//+
//5 2 3
public class SumList {
	public LinkedListNode SumLists(LinkedListNode l1, LinkedListNode l2, int carry)
	{
		LinkedListNode result = new LinkedListNode();
		int value = carry;
		
		if(l1 != null)
			value += l1.data;
		
		if(l2 != null)
			value += l2.data;
		
		result.data = value % 10;
		
		if(l1 != null || l2 != null)
		{
			LinkedListNode more = SumLists(l1 == null ? null : l1.next,
										   l2 == null ? null : l2.next,
										   value >= 10 ? 1 : 0);
			result.next = more;
		}
		return result;		
	}
}
