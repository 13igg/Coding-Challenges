package Stacks;

import java.util.Stack;

public class StackWithMin extends Stack<Integer>{
	Stack<Integer> s2;
	public StackWithMin()
	{
		s2 = new Stack<Integer>();
	}
	
	public void push(int value){
		if(value <= min())
			s2.push(value);
		super.push(value);
	}
	
	public Integer pop(){
		int value = super.pop();
		if(value == min())
			s2.pop();
		return value;
	}
	
	public int min(){
		if(s2.isEmpty())
			return Integer.MAX_VALUE;
		else
			return s2.peek();
	}
	
/*	int data[] = new int[10];
	
	public int pop(int i) {return data[i--];}
	
	public void push(int value)
	{
		int newMin = Math.min(value,min());
		super.push(new NodeWithMin(value, newMin));
	}
	
	public int min()
	{
		if(this.isEmpty())
			return Integer.MAX_VALUE;
		else
			return peek().min;
	}*/
}

class NodeWithMin{
	public int value;
	public int min;
	public NodeWithMin(int v, int min){
		value = v;
		this.min = min;
	}
}

