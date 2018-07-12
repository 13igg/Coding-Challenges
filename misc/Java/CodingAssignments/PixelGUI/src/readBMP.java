import java.awt.FlowLayout;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;


public class readBMP extends JPanel
{
	private BufferedImage img;
	public readBMP(JFrame frame)
	{
		 setLayout(new FlowLayout());
		 setSize(200,250);		 
		try{UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());}catch (Exception e){}
		try {img = ImageIO.read(selectBMPFile().getAbsoluteFile());} catch (IOException e) {}
		
	}
	public BufferedImage previewImage(int beginX, int beginY, int endX, int endY)
	{
		if(img.getHeight()<endY)
			endY = img.getHeight();
		if(img.getWidth()<endX)
			endX = img.getWidth();
		JLabel jLabel = new JLabel(new ImageIcon(enlarge(img.getSubimage(beginX, beginY, endX, endY),30)));
        JPanel jPanel = new JPanel();
        jPanel.add(jLabel);
        add(jPanel);
        return img.getSubimage(beginX, beginY, endX, endY);
	}
	public static BufferedImage enlarge(BufferedImage image, int n) 
	{	        
        int w = n * image.getWidth();
        int h = n * image.getHeight();
        
        BufferedImage enlargedImage =
        		new BufferedImage(w, h, image.getType());
        
        for (int y=0; y < h; ++y)
            for (int x=0; x < w; ++x)
                enlargedImage.setRGB(x, y, image.getRGB(x/n, y/n));
        
        return enlargedImage;
	}
	
	public File selectBMPFile() //used for grabbing the specific file to be used to input
	{
		do{
			try{
				UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
				}
				catch (Exception e){}
			JFileChooser chooser = new JFileChooser();
			FileNameExtensionFilter filter = new FileNameExtensionFilter("BMP files","BMP");
			chooser.setFileFilter(filter);
			chooser.setAcceptAllFileFilterUsed(false);
			int retVal = chooser.showOpenDialog(null);
				if(retVal == JFileChooser.APPROVE_OPTION)
					return (chooser.getSelectedFile());
				else
					return null;
			
		}while(true);
	}
}
