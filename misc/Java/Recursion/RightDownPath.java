package Recursion;

import java.util.ArrayList;
import java.util.HashSet;
//Create a Point
//Start in bottom right, recur up
//Check to see if each path has a way to get to the start
//DO NOT WORRY ABOUT FAILED POINTS
//Add Failed points in as memorization after
//
public class RightDownPath {
	ArrayList<Point> getPath(boolean[][] maze)
	{	
		ArrayList<Point> path = new ArrayList<Point>();
		int r =maze.length-1;
		int c = maze[0].length-1;
		if(getPath(maze, r, c, path, new HashSet<Point>()))
			return path;
		return null;
	}
	//O(row col)
	boolean getPath(boolean[][] maze, int row, int col, ArrayList<Point> path, HashSet<Point> failedPoints)
	{
		if(row < 0 || col < 0)
			return false;	

		Point p = new Point(row,col);
		if(failedPoints.contains(p))
			return false;
		
		boolean isZeroZero = row == 0 && col == 0; 
		if(isZeroZero || getPath(maze, row - 1, col, path, failedPoints)
						||  getPath(maze, row, col-1, path, failedPoints)) 
		{
			path.add(p);
			return true;
		}

		failedPoints.add(p);
		return false;
	}
	
	public class Point
	{
		int x;
		int y;
		public Point(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
	}

}

