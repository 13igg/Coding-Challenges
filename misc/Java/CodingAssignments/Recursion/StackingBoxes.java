package Recursion;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
//Create a BOX Class first
//Create a comparator to sort them
//take 1 box, try all other box combinations on top of it
//take the next box, try all other combinations
//keep the height stored.

public class StackingBoxes {
	int createStack(ArrayList<Box> boxes)
	{
		Collections.sort(boxes, new BoxComparator());
		int maxHeight = 0;
		for(int i = 0; i<boxes.size(); i ++){
			int height = createStack(boxes, i);
			maxHeight = Math.max(maxHeight, height);
		}
		return maxHeight;
	}
	
	int createStack(ArrayList<Box> boxes, int bottomIndex){
			Box bottom = boxes.get(bottomIndex);
			int maxHeight = 0;
			for(int i = bottomIndex + 1; i < boxes.size(); i ++)
			{
				if(boxes.get(i).canBeAbove(bottom)){
					int height = createStack(boxes, i);
					maxHeight = Math.max(height,  maxHeight);
				}
			}
			maxHeight += bottom.height;
			return maxHeight;
	}
	
	class Box{
		int height;
		int width;
		int depth;
		public Box(int height, int width, int depth)
		{
			this.height = height;
			this.width = width;
			this.depth = depth;
		}
		
		public boolean canBeAbove(Box b)
		{
			return b.height < height && b.width < width && b.depth < depth; 
		}
	}
	
	class BoxComparator implements Comparator<Box> {
		@Override
		public int compare(Box x, Box y){
			return y.height - x.height;
		}
	}
}
