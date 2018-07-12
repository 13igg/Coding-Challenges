package Stacks;

import java.util.Stack;

public class StackQueue<T> {
	Stack<T> stackNewest, stackOldest;
	
	public StackQueue(){
		stackNewest = new Stack<T>();
		stackOldest = new Stack<T>();
	}
	
	public int size(){
		return stackNewest.size() + stackOldest.size();
	}
	
	public void enqueue(T value)
	{
		stackNewest.push(value);
	}
		
	public T dequeue(){
		shiftStacks();
		return stackOldest.pop();
	}
	
	private void shiftStacks(){
		if(stackOldest.isEmpty()) {
			while(!stackNewest.isEmpty()){
				stackOldest.push(stackNewest.pop());
			}
		}
	}
	
	public T peek(){
		shiftStacks();
		return stackOldest.peek();
	}	
}
