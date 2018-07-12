package Stacks;
//stack is push, pop, isEmpty, isFull
//Lets go ahead and split it into 3 subparts

//Hold an array for their values
//Hold an array for the sizes of each

//Push:
//if it is full, return
//increase the size array
//find the index of the top item in that array

//FindTopIndex:

public class ThreeStacks {
		
	int numberOfStacks = 3;
	int stackCapacity;
	int[] values;
	int[] sizes;
	
	public ThreeStacks(int size)
	{
		stackCapacity = size;
		values = new int[size * numberOfStacks];
		sizes = new int[numberOfStacks];
	}
	
	public void push(int stackNum, int value)
	{
		if(isFull(stackNum))return;
		sizes[stackNum]++;
		values[indexOfTop(stackNum)] = value;
	}
	
	public int pop(int stackNum)
	{
		if(isEmpty(stackNum))
			return 0;
		
		int topIndex = indexOfTop(stackNum);
		int value = values[topIndex];
		values[topIndex] = 0;
		sizes[stackNum]--;
		return value;		
	}
	
	public int peek(int stackNum)
	{
		if(isEmpty(stackNum))
			return 0;
		return values[indexOfTop(stackNum)];
	}
	
	public boolean isEmpty(int stackNum)
	{
		return sizes[stackNum] == 0;
	}
	
	public boolean isFull(int stackNum)
	{
		return sizes[stackNum] == stackCapacity;
	}
	
	private int indexOfTop(int stackNum)
	{
		int offset = stackNum*stackCapacity;
		int size = sizes[stackNum];
		return offset + size - 1;
	}
	
}
