package Stacks;
import java.util.Stack;
//Iterative
//Take a temp stack 
//take an item off the top and hold it
//keep moving items over to R until r < temp
//then the item off of r and put it in s
//put the temp onto r
//
//Recursive

/*
 * if stack is not empty
 * 	temp = pop(s)
 * sortStack(S);
 * sortedInsert(s, temp);
 * */	

//O(n^2) time
//O(N( space
public class SortingStacks {	
	
	void Sort(Stack<Integer> s){
		Stack<Integer> r = new Stack<Integer>();
		while(!s.isEmpty()){
			int tmp = s.pop();
			while(!r.isEmpty() && r.peek() > tmp){
				s.push(r.pop());
			}
			r.push(tmp);
		}
		while (!r.isEmpty()){
			s.push(r.pop());
		}
	}
//****************************************************
	
	Stack<Integer> temp = new Stack<Integer>();
	void RecursiveSort(Stack<Integer> s)
	{
		while(s.peek() != null)
		{
			int item = s.pop();
			RecursiveSort(s);
			sortedInsert(s, item);
		}
	}	
	
	void sortedInsert(Stack<Integer> s, int item)
	{
		if (s.isEmpty() || item > s.peek())
		{
			s.push(item);
			return;
		}
		int t = s.pop();
		sortedInsert(s,t);
		s.push(t);
	}
}





