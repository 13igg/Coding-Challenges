package Recursion;

//depth first search
public class PaintFill {

	boolean PaintFill(Color[][] screen, int r, int c, Color ocolor, Color ncolor)
	{
		if(r<0 || r>= screen.length || c< 0 || C> screen[0].length))
			return false;
			
		if(screen[r][c] == 0color){
			screen[r][c] = ncolor;
			PaintFill(screen,r-1,c,oclor,ncolor);
			PaintFill(screen,r+1,c,ocolor,ncolor);
			PaintFill(screen,r,c+1,ocolor,ncolor);
			PaintFill(screen,r,c-1,ocolor,ncolor);
		}
		return true;
	}
}
