import LinkedLists.*;
import StringsArrays.*;
import Stacks.*;
import Recursion.*;
public class Main {
	public static void main(String args[])
	{
		//PalindromePerm();
		//IsOneAway();
		//StringCompression();
		//Rotate();
		//SubstringRotation();
		
		//RemoveDuplicatesLL();
		//PartitionLinkedList();
		//SumLinkedList();
		//LinkedListPalindrome();
		//Intersection();
		//FindCollisionPoint();
		//Implement3StackOneArray();
		//ImplementStackWithMins();
		//MyQueueWithStacks();
		//TripStep();
		//RecurMultiply();
		Hanoi();
		
	}
	
	static void PalindromePerm()
	{
		PalindromePermutation a = new PalindromePermutation();
		System.out.println(a.isPermutationOfPalindrome("testS"));
	}	
	
	static void IsOneAway()
	{
		OneAway a = new OneAway();
		System.out.println(a.isOneAway("pales", "pale"));
		System.out.println(a.isOneAway("pale", "pales"));
		System.out.println(a.isOneAway("pdle", "pale"));
	}
	
	static void StringCompression()
	{
		StringCompression a = new StringCompression();
		System.out.println(a.compress("aabbbcdeefffffffgg"));
	}
	
	static void Rotate()
	{
		int arraySize = 4;
		int square[][] = new int[arraySize][arraySize];
		for(int r = 0; r < arraySize; r ++)
		{
			for(int c = 0; c < arraySize; c++)
			{
				square[r][c] = r+c;
			}
		}
		
		for(int r = 0; r < arraySize; r ++)
		{
			for(int c = 0; c < arraySize; c++)
			{
				System.out.print(square[r][c]);
			}
			System.out.println();
		}
		
		RotateSquare rot = new RotateSquare();
		rot.Rotate(square);
		for(int r = 0; r < arraySize; r ++)
		{
			for(int c = 0; c < arraySize; c++)
			{
				System.out.print(square[r][c]);
			}
			System.out.println();
		}
	}
	
	static void SubstringRotation()
	{
		StringRotation sr = new StringRotation();
		sr.Rotate("waterbottle","erbottlewat");
	}
	
	static void RemoveDuplicatesLL(){
		RemoveLinkedListDups rd = new RemoveLinkedListDups();
		LinkedListNode n = new LinkedListNode(2);
		
		n.appendToTail(2);
		n.appendToTail(4);
		n.appendToTail(5);
		n.appendToTail(4);
		n.appendToTail(2);
				
		System.out.println(n.toString());
		rd.RemoveDupsNoBuffer(n);
		System.out.println(n.toString());
	}
	
	static void FindKthToLastLL()
	{
		KthToLast k = new KthToLast();
		LinkedListNode n = new LinkedListNode(2);
		
		n.appendToTail(2);
		n.appendToTail(4);
		n.appendToTail(5);
		n.appendToTail(4);
		n.appendToTail(2);
		
		k.printKthToLast(n, 5);
	}

	static void PartitionLinkedList()
	{
		PartitionLinkedList pll = new PartitionLinkedList();
		
		LinkedListNode n = new LinkedListNode(3);
		n.appendToTail(5);
		n.appendToTail(8);
		n.appendToTail(5);
		n.appendToTail(10);
		n.appendToTail(2);
		n.appendToTail(1);
				
		System.out.println(n.toString());
		pll.partition(n, 5);
		System.out.println(n.toString());
	}

	static void SumLinkedList() {
		SumList SL = new SumList();
		
		LinkedListNode n = new LinkedListNode(7);
		n.appendToTail(1);
		n.appendToTail(6);
		
		LinkedListNode o = new LinkedListNode(5);
		o.appendToTail(9);
		o.appendToTail(2);
				
		System.out.println(n.toString());
		System.out.println(o.toString());
		System.out.println(SL.SumLists(n, o, 0).toString());
	}
	
	static void LinkedListPalindrome() {
		LinkedListPalindrome LLP = new LinkedListPalindrome();
		
		LinkedListNode n = new LinkedListNode(0);
		n.appendToTail(1);
		n.appendToTail(2);
		n.appendToTail(1);
		n.appendToTail(0);
				
		System.out.println(LLP.IsPalindrome(n));
	}

	static void Intersection()
	{
		Intersection a = new Intersection();
		
		LinkedListNode tail = new LinkedListNode(7);	
		tail.appendToTail(2);
		tail.appendToTail(1);

		LinkedListNode n = new LinkedListNode(3);	
		n.appendToTail(1);
		n.appendToTail(5);
		n.appendToTail(9);	
		n.next.next.next.next = tail;	

		LinkedListNode o = new LinkedListNode(4);	
		o.appendToTail(6);
		o.next.next = tail;
		
		System.out.println(n.toString());
		System.out.println(o.toString());
		
		System.out.println(a.findIntersection(n,o).toString());			
	}
	
	static void FindCollisionPoint()
	{
		CircularLinkedList cll = new CircularLinkedList();
		LinkedListNode intersection = new LinkedListNode(77);
		LinkedListNode n = new LinkedListNode(3);	
		n.appendToTail(1);
		n.appendToTail(5);
		n.next.next.next = intersection;
		n.appendToTail(9);
		n.appendToTail(3);
		n.appendToTail(4);
		n.appendToTail(7);
		n.appendToTail(6);
		n.appendToTail(3);
		n.appendToTail(8);
		n.next.next.next.next.next.next.next.next.next.next.next = intersection;
		
		System.out.println(cll.FindCollision(n).data);
	}

	static void Implement3StackOneArray()
	{
		ThreeStacks ts = new ThreeStacks(10);
		ts.push(1,6);
		ts.push(1,2);
		ts.push(1,4);
		ts.push(1,3);
		ts.push(1,1);	
		
		ts.pop(1);		
	}

	static void ImplementStackWithMins()
	{
		StackWithMin s = new StackWithMin();
		s.push(6);
		System.out.println(s.min());
		s.push(2);
		s.push(4);
		s.push(3);
		s.push(1);	
		System.out.println(s.min());
		System.out.println(s.pop());	
		System.out.println(s.min());
	}

	static void MyQueueWithStacks()
	{
		StackQueue<Integer> sq = new StackQueue<Integer>();
		sq.enqueue(1);
		sq.enqueue(6);
		sq.enqueue(4);
		sq.enqueue(3);
		sq.enqueue(7);
		
		sq.dequeue();
		sq.enqueue(8);
		sq.enqueue(2);
		sq.enqueue(8);
		sq.enqueue(1);
	}

	static void TripStep()
	{
		TripleStep ts = new TripleStep(15);
	}

	static void RecurMultiply()
	{
		RecursiveMultiply rm = new RecursiveMultiply();
		System.out.println(rm.multiply(2, 2));
		System.out.println(rm.minProducts(31, 35));
	}

	static void Hanoi()
	{
		TowersOfHanoi toh = new TowersOfHanoi(4);
	}
}
