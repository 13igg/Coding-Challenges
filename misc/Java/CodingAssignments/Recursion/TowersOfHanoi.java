package Recursion;
import java.util.Stack;

//moveDisks n, origin, destination, buffer
//move top n-1 disks from origin to buffer - destination is our buffer
//move top from origin to destination
//move top n-1 disks from buffer to destination, origin is our buffer

public class TowersOfHanoi {
	public TowersOfHanoi(int numRings)
	{
		Tower[] towers = new Tower[numRings];
		for(int i = 0; i < 3; i++)
			towers[i] = new Tower(i);
		
		for(int i = numRings; i > 0; i--)
			towers[0].add(i);
		
		towers[0].moveDisks(numRings, towers[2], towers[1]);		
	}
	
	public class Tower{
		private Stack<Integer> rings;
		private int towerNumber;
		
		public Tower(int towerNumber)
		{
			this.rings = new Stack<Integer>();
			this.towerNumber = towerNumber;
		}
		
		public int towerNumber()
		{
			return towerNumber;
		}
		
		public void add(int d)
		{
			if(!rings.isEmpty() && rings.peek()<=d)
				System.out.println("cannot place disk: " + d);
			else 
				rings.push(d);
		}
		
		public void moveTopTo(Tower t){
			t.add(rings.pop());
		}
		
		public void moveDisks(int n, Tower destination, Tower buffer){
			if (n > 0){
				moveDisks(n-1, buffer, destination);
				moveTopTo(destination);
				buffer.moveDisks(n-1,destination,this);
			}
		}
	}	
}
