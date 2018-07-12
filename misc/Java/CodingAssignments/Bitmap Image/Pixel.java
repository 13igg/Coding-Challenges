import javax.swing.*;
import javax.*;
public class Pixel
{
	private int RGB;

	public Pixel()
	{
		RGB = 0;
	}
	public Pixel(int r, int g, int b)
	{
		RGB = 0;
		setRGB(r,g,b);
	}
	
	public void setRed(int r)
	{
		while(r>255 || r < 0)
			r = Integer.parseInt(JOptionPane.showInputDialog("Set a RED value between 0 and 255"));
		RGB = (r << 24) | (getGreen() << 16) | (getBlue() << 8);
	}
	
	public void setGreen(int g)
	{
		while(g>255 || g < 0)
			g = Integer.parseInt(JOptionPane.showInputDialog("Set a Green value between 0 and 255"));
		RGB = (getRed() << 24) | (g << 16) | (getBlue() << 8);
	}

	public void setBlue(int b)
	{
		while(b>255 || b < 0)
			b = Integer.parseInt(JOptionPane.showInputDialog("Set a BLUE value between 0 and 255"));
		RGB = (getRed() << 24) | (getGreen() << 16) | (b << 8);
	}

	public void setRGB(int r, int g, int b)
	{
		setRed(r); 	setGreen(g);  setBlue(b);
	}
	//0xFF is 255 is binary 00000000 00000000 00000000 11111111, 
	public int getRed()
	{
		return (RGB >> 24) & 0xFF;
	}
	
	public int getGreen()
	{
		return (RGB >> 16) & 0xFF;
	}

	public int getBlue()
	{
		return (RGB >> 8) & 0xFF;
	}
	public int getRGB()
	{
		return ((RGB >> 24 & 0xFF)*1000000 + (RGB >> 16 & 0xFF)*1000 + (RGB >> 8 & 0xFF));
	}
	public String printRGB()
	{
		return String.format("%09d", getRGB());
	}
	public String printHex()
	{
		 return String.format("%02x", getRed()) + String.format("%02x", getGreen()) + String.format("%02x", getBlue());
	}
	public String printHexBackwards()
	{
		 return String.format("%02x", getBlue()) + String.format("%02x", getGreen()) + String.format("%02x", getRed());
	}
}