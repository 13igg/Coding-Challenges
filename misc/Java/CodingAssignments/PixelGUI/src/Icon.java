import javax.swing.*;
import java.util.*;
import java.io.BufferedWriter;
import java.io.File;
import java.io.*;
public class Icon
{
	//private Pixel[][] p;
	private ArrayList<ArrayList<Pixel>> p;
	//for row
	//make a temp row
	//for col
	//Pixel p = new Pixel()
	//tempRow.add(p)
	//pixels.add(tempRow);
	private char[] heightArray;
	private char[] widthArray;
	private	int row;
	private	int col;
	private	int pixelArraySize;
	private	String bfHeadder, dibHeadder, pixelData;

	public Icon()
	{
		row = col = 40;		
		pixelData = "";
		p = new ArrayList <ArrayList<Pixel>>();
		//fill all empty Pixels
		for(int r = 0; r < row; r ++)
		{
			ArrayList<Pixel> listRow = new ArrayList<Pixel>();
			for(int c = 0; c < col; c++)
			{
				Pixel p = new Pixel();
				listRow.add(p);
			}
			p.add(listRow);
		}
	}
	public Icon(int r, int c)
	{		
		row = r;
		col = c;
		pixelData = "";
		p = new ArrayList <ArrayList<Pixel>>();
		//fill all empty Pixels
		for(int r2 = 0; r2 < row; r2 ++)
		{
			ArrayList<Pixel> listRow = new ArrayList<Pixel>();
				for(int c2 = 0; c2 < col; c2++)
				{
					Pixel p = new Pixel();
					listRow.add(p);
				}
			p.add(listRow);
		}
	}
	public int getRow() 
	{
		return row;
	}
	public void setRow(int r) 
	{
		row = r;
	}
	public int getCol() 
	{
		return col;
	}
	public void setCol(int c)
	{
		col = c;
	}
	public Pixel getPixel(int r, int c)
	{
		if(r < 0 || c < 0 || r > row || c > col)
		{
			System.out.println("wrong row or col length, repick please!");
			setRow(Integer.parseInt(JOptionPane.showInputDialog("Select a row...")));
			setCol(Integer.parseInt(JOptionPane.showInputDialog("Select a col...")));
		}
		return p.get(r).get(c);
	}
	public void setColors(int r, int c,Pixel pi)
	{//user sets the colors of designated pixel
		int red = Integer.parseInt(JOptionPane.showInputDialog("Set a RED value for Pixel ["+r+"]["+c+"]"));
		int green = Integer.parseInt(JOptionPane.showInputDialog("Set a GREEN value for Pixel ["+r+"]["+c+"]"));
		int blue = Integer.parseInt(JOptionPane.showInputDialog("Set a BLUE value for Pixel ["+r+"]["+c+"]"));
		pi.setRGB(red,green,blue);
	}
	public void colorPixles(int r, int c)
	{//random pixel for the selected pixel
		//Random generator = new Random();
		int red = 255;//generator.nextInt(255);
		int green = 255;//generator.nextInt(255);
		int blue = 255;//generator.nextInt(255);
		getPixel(row-r-1,c).setRGB(red,green,blue);
	}
	public void printIconRGB()
	{
		for(int r = 0; r < row; r ++)
		{
			for(int c = 0; c < col; c++)
				System.out.print(getPixel(row-r-1,c).printRGB() + ", ");	
			System.out.println("");	
		}			
	}	
	private void setBMPheadder()
	{//always 14
		//  BMP HEADDER		bitmap 424d     size of BMP           //leave 0s
		String bfType,  bfSize,      bfReserved1, bfReserved2, bfOffset; 
		setPixelArray();
		bfType = "424d"; //states it s a bitmap 424d
		bfSize = setBFsize(pixelArraySize + 54); //pixels size + bmp + DIB//size
		bfReserved1 = "0000"; bfReserved2 = "0000"; // leave 0s
		bfOffset = "36000000";//54
		bfHeadder = bfType + bfSize + bfReserved1 + bfReserved2 + bfOffset;
	}
	private String setBFsize(int s)
	{		
		String size = String.format("%08x", s);
		char[] c = size.toCharArray();
		char[] tempChars = {c[6],c[7],c[4],c[5],c[2],c[3],c[0],c[1]}; //reverse hex
		return new String(tempChars);
	}
	private String setRawData(int s)
	{		
		String size = String.format("%08x", s);
		char[] c = size.toCharArray();
		char[] tempChars = {c[6],c[7],c[4],c[5],c[2],c[3],c[0],c[1]}; //reverse hex
		return new String(tempChars);
	}
	private void setDIBheadder()
	{
		//DIB HEADDER 
		String dibSize, width, height, colorPlanes, numBits, compression, raw_Data, vRes, hRes, plateletColors, importantColors;
		dibSize = "28000000"; //always 40
		width = getWidth();	height = getHeight();
		colorPlanes = "0100";
		numBits = "1800";
		compression = "00000000";
		raw_Data = setRawData(pixelArraySize); //changes with num of pixels + padding
		hRes = "130b0000"; vRes = "130b0000";
		plateletColors = "00000000";
		importantColors = "00000000";
		dibHeadder = dibSize + width + height + colorPlanes + numBits + compression + raw_Data + hRes + vRes + plateletColors + importantColors;
	}
	private void setPixelArray()
	{		
		int padd = (col * 3) % 4; //remainder
		padd = (4-padd); // num of bytes to add
		for(int r = 0; r < row; r ++)
		{
			for(int c = 0; c < col; c++)//add hex values
				pixelData += getPixel(row-r-1,c).printHexBackwards();				
			for(int i = padd; i > 0; i--) //add padding
				pixelData += "00";
		}
		pixelArraySize = (pixelData.length())/2;
	}
	
	public String createBMP()
	{
		setBMPheadder();
		setDIBheadder();
		return bfHeadder + dibHeadder + pixelData;
	}
	public String getHeight()
	{
		String h = String.format("%08x", row);
		heightArray = h.toCharArray();
		char[] tempChars = {heightArray[6],heightArray[7],heightArray[4],heightArray[5],heightArray[2],heightArray[3],heightArray[0],heightArray[1]};
		h = new String(tempChars);
		return h;
	}
	public String getWidth()
	{
		String w = String.format("%08x", col);
		widthArray = w.toCharArray();
		char[] tempChars = {widthArray[6],widthArray[7],widthArray[4],widthArray[5],widthArray[2],widthArray[3],widthArray[0],widthArray[1]};
		w = new String(tempChars);
		return w;
	}	
	// Writes hex String converted to binary to the .bmp file
	public void writeToFile(String fileName, String fileLocation)
	{
		try 
		{
			File file = new File( fileLocation + fileName + ".BMP");			
		// if file doesnt exists, then create it
			if (!file.exists())
				file.createNewFile();
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			
			String temp = createBMP();
			char[] tempChar;
			char[] tempChar2 = new char[2];
			tempChar = temp.toCharArray();
			for(int i = 0; i < temp.length(); i += 2)//very hex to binary
					{
						tempChar2[0] = tempChar[i];
						tempChar2[1] = tempChar[i+1];
						String t = new String(tempChar2);
						int content = Integer.parseInt(t,16);				
						bw.write(content);
					}
			bw.close(); 
			System.out.println("File written to .bmp file");
			pixelData = "";
	} 
	catch (IOException e){
			e.printStackTrace();}
	}
}