import javax.swing.JOptionPane;
public class Driver
{
	public static void main(String[] args)
	{
		int red = 0;
		int green = 0;
		int blue = 0;
		Icon i = new Icon(5,5);//0 5 by 0 5
		//for(int r = 0; r<5; r ++)
		//	for(int c = 0; c<5; c++)
		//		i.getPixel(r,c).setRGB(red,green,blue);
		
		i.getPixel(0,0).setRGB(0,0,0);
		i.getPixel(1,0).setRGB(255,255,255);
		i.getPixel(2,0).setRGB(0,0,0);
		i.getPixel(3,0).setRGB(255,255,255);
		i.getPixel(4,0).setRGB(0,0,0);
		i.getPixel(0,1).setRGB(255,255,255);
		i.getPixel(1,1).setRGB(0,0,0);
		i.getPixel(2,1).setRGB(255,255,255);
		i.getPixel(3,1).setRGB(0,0,0);
		i.getPixel(4,1).setRGB(255,255,255);
		i.getPixel(0,2).setRGB(0,0,0);
		i.getPixel(1,2).setRGB(255,255,255);
		i.getPixel(2,2).setRGB(255,255,255);
		i.getPixel(3,2).setRGB(255,255,255);
		i.getPixel(4,2).setRGB(0,0,0);
		i.getPixel(0,3).setRGB(255,255,255);
		i.getPixel(1,3).setRGB(0,0,0);
		i.getPixel(2,3).setRGB(255,255,255);
		i.getPixel(3,3).setRGB(0,0,0);
		i.getPixel(4,3).setRGB(255,255,255);
		i.getPixel(0,4).setRGB(0,0,0);
		i.getPixel(1,4).setRGB(255,255,255);
		i.getPixel(2,4).setRGB(0,0,0);
		i.getPixel(3,4).setRGB(255,255,255);
		i.getPixel(4,4).setRGB(0,0,0);
		i.printIconRGB();
		i.writeToFile(0);

		i.setColors(0,4);
		i.printIconRGB();
		i.writeToFile(0);
	}
}