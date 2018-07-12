import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayList;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.JTextField;
public class guiFrame extends JFrame
{
	//grid flow border
	//maybe make these smaller, like an array of sliders.panels.texts, 123, rgb?
	private JPanel all;
	
	private JPanel sliders;
	private JSlider rSlider, gSlider,bSlider;
	
	private int prevColorCount;
	private JPanel colorPanel;
	private JPanel prevColorPanel;
	private JButton prevColor1, prevColor2, prevColor3, prevColor4, prevColor5;
	
	private JPanel levels;
	private JLabel rLevels, gLevels, bLevels;

	private JPanel pButtons;
	//private PixelButton[][] pixel; //make an array list of array lists
	private ArrayList<ArrayList<PixelButton>> pixel;
	//private ArrayList<ArrayList<Pixel>> p;
	private Icon icon;
	
	private JPanel pOptions;
	private JCheckBox advanced;
	private JButton Save;
	private JFileChooser fileChooser;
	private BufferedImage img;
	private readBMP n; 	
	private JPanel pPreview;
	
	private AdvancedWindow advW;
	private JTextField  tfRow;
	private JTextField  tfCols;
	
	public guiFrame()
	{
			super("Pixel");
			buildGUI();		
			setVisible(true);
			setSize(500,400);
			setLocation(100,100);
			prevColorCount = 0;
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
	}

	public void buildGUI()
	{
		all = new JPanel();
		all.setLayout(new GridLayout(2,3,2,2));	
		
		
		buildPixels();
		all.add(pButtons);
					
		sliders = new JPanel(new GridLayout(3,1,2,2));	    
		slideEvent e = new slideEvent();
		sliders.add(newSlider(rSlider= new JSlider(JSlider.HORIZONTAL,0,255,0),e));
		sliders.add(newSlider(gSlider= new JSlider(JSlider.HORIZONTAL,0,255,0),e));
		sliders.add(newSlider(bSlider= new JSlider(JSlider.HORIZONTAL,0,255,0),e));				
		all.add(sliders);
		
		levels = new JPanel(new GridLayout(3,1,2,2));
		levels.add(rLevels = new JLabel("RED = 0")); //new labels all at 0
		levels.add(gLevels = new JLabel("GREEN = 0"));
		levels.add(bLevels = new JLabel("BLUE = 0"));
		all.add(levels);
		
		JPanel test = new JPanel(new BorderLayout());
		colorPanel = new JPanel();
		colorPanel.setBackground(Color.BLACK);

		test.add(colorPanel,BorderLayout.CENTER);
		all.add(test);
		
		//previous colors. Press one of these, then the sliders change to the color of this.
		//MAKE A JPANEL TO HOLD ALL FO THESE, PLUS NEED TO MAKE A CONTER TO KNOW WHICH ONE TO CHANGE TO THE NEXT COLOR. COUNT TO 5, THEN BACK TO 1
		prevColorPanel = new JPanel(new GridLayout(5,1,3,3));
		prevColorPressed p = new prevColorPressed();
		
		prevColorPanel.add(newPrevColor(prevColor1 = new JButton(), p));
		prevColorPanel.add(newPrevColor(prevColor2 = new JButton(), p));
		prevColorPanel.add(newPrevColor(prevColor3 = new JButton(), p));
		prevColorPanel.add(newPrevColor(prevColor4 = new JButton(), p));
		prevColorPanel.add(newPrevColor(prevColor5 = new JButton(), p));
		all.add(prevColorPanel);
		
		pOptions = new JPanel(new GridLayout(2,1,2,2));
		advanced = new JCheckBox("Advanced Stuff");
		pOptions.add(advanced);
		
		saveEvent sE = new saveEvent();
		Save = new JButton("Save");
		Save.addActionListener(sE);
		pOptions.add(Save);
		all.add(pOptions);
		
		add(all);	 		
		
	}	
	private JSlider newSlider(JSlider Slider, slideEvent e)
	{
		Slider.addChangeListener(e);
		Slider.setPaintTicks(true);
		Slider.setMajorTickSpacing(85);
		Slider.setPaintLabels(true);
		return Slider;
	}
	private JButton newPrevColor(JButton prevColor, prevColorPressed p)
	{
		prevColor.setBackground(Color.BLACK);
		prevColor.addActionListener(p); //each pixel has an action listener
		return prevColor;
	}
	private class saveEvent implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			try {UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());}catch (Exception ef){}
			fileChooser = new JFileChooser();
			FileNameExtensionFilter filter = new FileNameExtensionFilter("BMP File","BMP"); //bmp is the only file tipe
			fileChooser.setFileFilter(filter);//sets above
			fileChooser.setAcceptAllFileFilterUsed(false);
			File desktop = new File("c:\\Users\\Matt\\Desktop\\");//sets desktop as default
			fileChooser.setCurrentDirectory(desktop);//sets desktop as default
			int retVal = fileChooser.showSaveDialog(fileChooser);
		    if(retVal == JFileChooser.APPROVE_OPTION)//checks to see if it was run or closed out
				icon.writeToFile("", fileChooser.getSelectedFile().toString());
		 }	
	}
    private class slideEvent implements ChangeListener
	{
		public void stateChanged(ChangeEvent e)
		{
			int r = rSlider.getValue();
			int g = gSlider.getValue();
			int b = bSlider.getValue();
			
			rLevels.setText("RED = " + r);
			gLevels.setText("GREEN = " + g);
			bLevels.setText("BLUE = " + b);		
			
			colorPanel.setBackground(new Color(r,g,b));
		}
	}
    private void changePrevColors(int r, int g, int b)
    {

		prevColorCount++;
    	if(prevColorCount == 1){
	    	if((prevColor5.getBackground().getRed() == r && prevColor5.getBackground().getGreen() == g && prevColor5.getBackground().getBlue() == b))
	    		prevColorCount -= 1;
	    	else
	    		prevColor1.setBackground(new Color(r,g,b));}			    
	    else if(prevColorCount == 2){
	    	if((prevColor1.getBackground().getRed() == r && prevColor1.getBackground().getGreen() == g && prevColor1.getBackground().getBlue() == b))
	    		prevColorCount -= 1;
	    	else
	    		prevColor2.setBackground(new Color(r,g,b));}			    
	    else if(prevColorCount == 3){
	    	if((prevColor2.getBackground().getRed() == r && prevColor2.getBackground().getGreen() == g && prevColor2.getBackground().getBlue() == b))
	    		prevColorCount -= 1;
	    	else
	    		prevColor3.setBackground(new Color(r,g,b));}			    
	    else if(prevColorCount == 4){
	    	if((prevColor3.getBackground().getRed() == r && prevColor3.getBackground().getGreen() == g && prevColor3.getBackground().getBlue() == b))
	    		prevColorCount -= 1;
	    	else
	    		prevColor4.setBackground(new Color(r,g,b));}
	    else if(prevColorCount == 5){
	    	if((prevColor4.getBackground().getRed() == r && prevColor4.getBackground().getGreen() == g && prevColor4.getBackground().getBlue() == b))
	    		prevColorCount -= 1;
	    	else
	    		prevColor5.setBackground(new Color(r,g,b));}			    
	    else if(prevColorCount == 6)//MIGHT NEED TO FIX INSIDE HERE. GOING TO BED SO IM NOT SURE.
	    		{
			    	if((prevColor5.getBackground().getRed() == r && prevColor5.getBackground().getGreen() == g && prevColor5.getBackground().getBlue() == b))
			    		prevColorCount -= 1;
			    	else
			    	{
			    		prevColor1.setBackground(new Color(r,g,b));
			    		prevColorCount = 1;
			    	}
	    		}
    }
    private JPanel pMain2;
	private class pixelPress implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			int r = rSlider.getValue();
			int g = gSlider.getValue();
			int b = bSlider.getValue();	
			if(!advanced.isSelected())
			{				
			    ((PixelButton)e.getSource()).setBackground(new Color(r,g,b)); //casts the source as a PixelButton and changes the background color
			     icon.getPixel(((PixelButton)e.getSource()).getRow(),((PixelButton)e.getSource()).getCol()).setRGB(r, g, b);//sets the pixel at the pressed buttons row,col to the color chosen
			    //changes the previous color slates but makes sure it hasnt already changed one.
			    changePrevColors(r,g,b);			    	
			}
			else
			{
				//open a new window with more options!
				 advW = new AdvancedWindow(guiFrame.this);
				 advW.setLocation(600,100);
				 JPanel pMain = new JPanel(new GridLayout(3,1,2,2));
				 pMain2 = new JPanel(new FlowLayout());
				 JPanel pRows = new JPanel(new GridLayout(1,2,2,2));
				 JPanel pCols = new JPanel(new GridLayout(1,2,2,2));
				 JPanel pButtons = new JPanel(new GridLayout(1,2,2,2));
				 
				 JLabel lRows = new JLabel("rows");
				 JLabel lCols = new JLabel("columns");
				 tfRow = new JTextField(10);
				 tfCols = new JTextField(10);
				
				 pRows.add(lRows);
				 pRows.add(tfRow);
				 pCols.add(lCols);
				 pCols.add(tfCols);
				 pMain.add(pRows);
				 pMain.add(pCols);
				 
				 JButton cancel = new JButton("Cancel");
				 JButton accept = new JButton("OK");
				 JButton upload = new JButton("Select Image");
				 
				 accept.addActionListener(new okPress(r,g,b,((PixelButton)e.getSource())));
				 cancel.addActionListener(new cancelPress());
				 upload.addActionListener(new grabBMP(((PixelButton)e.getSource())));
				 
				 pButtons.add(cancel);
				 pButtons.add(accept);
				 pMain.add(pButtons);	
				 pMain2.add(upload);
				 pPreview = new JPanel();
				 pMain2.add(pPreview);
				 JTabbedPane tabbedPane = new JTabbedPane();
				 tabbedPane.addTab("Color Squares",pMain);
				 tabbedPane.addTab("Upload Image",pMain2);
				 advW.add(tabbedPane);
				 advW.setVisible(true);
			}
		}
	}	
	
	private class grabBMP implements ActionListener
	{
		private PixelButton p;
		grabBMP(PixelButton p)
		{this.p = p;}
		
		public void actionPerformed(ActionEvent e)
		{
			advW.setSize(advW.getWidth()+1,advW.getHeight()+1);
			n = new readBMP(guiFrame.this);
			int endRow, endCol;
				 endRow = icon.getRow();//end row/col is the maxsize of the icon
				 endCol = icon.getCol();
			img = n.previewImage(0,0,endCol-p.getCol(),endRow-p.getRow());//preview image returns the image
			
			advW.setSize(200+img.getWidth()*43,250+img.getHeight()*20);
			n.setVisible(true);
			pPreview.removeAll();
							
			JButton j;//if u want the previewImage to be used, press yess
			pPreview.add(j = new JButton("Fill 'em in!"));
			fillImage fI = new fillImage(p);
			j.addActionListener(fI);
			pPreview.add(n);		
		}
	}
	private class fillImage implements ActionListener
	{
		private PixelButton p;
		fillImage(PixelButton p)
		{this.p = p;}
		public void actionPerformed(ActionEvent e)
		{
			//if pressed yess, change the pixels
			int imgRow=0;
			int imgCol=0;
			for(int r = p.getRow(); r < p.getRow()+img.getHeight(); r++, imgRow++, imgCol=0)
				for(int c = p.getCol(); c < p.getCol()+img.getWidth(); c++, imgCol++)
				{
					pixel.get(r).get(c).setBackground(new Color(img.getRGB(imgCol,imgRow)));
				    icon.getPixel(r,c).usingINTsetRGB(img.getRGB(imgCol, imgRow));//sets the pixel at the pressed buttons row,col to the color chosen
				}
		}
    }
	private class okPress implements ActionListener
	{
		int r,g,b;
		Boolean doThis;
		PixelButton p;
		okPress(int r, int g, int b, PixelButton p)
		{
			this.r = r; this.g = g; this.b = b; this.p = p;
			doThis = true;
		}
		public void actionPerformed(ActionEvent e)
		{
			if(tfRow.getText().isEmpty() || tfCols.getText().isEmpty())
			{
				advW.dispose();
				System.out.println("row or col was empty, or out of bounds, closing window");
				doThis = false;
			}
			 //changes all the selected row n cols the selected color
			if(doThis==true){
			 int endRow = p.getRow() + Integer.parseInt(tfRow.getText()); //end row is inputed row + current row
			 int endCol = p.getCol() + Integer.parseInt(tfCols.getText());//end col is inputed col + current col
			 if(endRow > icon.getRow())
				 endRow = icon.getRow();
			 if(endCol > icon.getCol())
				 endCol = icon.getCol();
			 //fills the rest of the rows/cols in
			 for(int ro = p.getRow(); ro < endRow; ro++)
				for(int c = p.getCol(); c < endCol; c++){
					pixel.get(ro).get(c).setBackground(new Color(r,g,b)); icon.getPixel(ro,c).setRGB(r,g,b);}//sets the pixel at the pressed buttons row,col to white}
			 changePrevColors(r,g,b);}
			advW.dispose();
		}
	}
	private class cancelPress implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			advW.dispose();			 
		}
	}	
	
	private class prevColorPressed implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
				int r = ((JButton)e.getSource()).getBackground().getRed();
				int g = ((JButton)e.getSource()).getBackground().getGreen();
				int b = ((JButton)e.getSource()).getBackground().getBlue();	
				rSlider.setValue(r);
				gSlider.setValue(g);
				bSlider.setValue(b);
				
				//if a previous color is pressed, make prevCOlorCOunt that color so it wont keep making copies of those colors
				    if((prevColor1.getBackground().getRed() == r && prevColor1.getBackground().getGreen() == g && prevColor1.getBackground().getBlue() == b))
				    	prevColorCount = 1;				    
				    else if((prevColor2.getBackground().getRed() == r && prevColor2.getBackground().getGreen() == g && prevColor2.getBackground().getBlue() == b))
				    	prevColorCount = 2;				   
				    else if((prevColor3.getBackground().getRed() == r && prevColor3.getBackground().getGreen() == g && prevColor3.getBackground().getBlue() == b))
				    	prevColorCount = 3;				    
				    else if((prevColor4.getBackground().getRed() == r && prevColor4.getBackground().getGreen() == g && prevColor4.getBackground().getBlue() == b))
				    	prevColorCount = 4;
				    else if((prevColor5.getBackground().getRed() == r && prevColor5.getBackground().getGreen() == g && prevColor5.getBackground().getBlue() == b))
					    prevColorCount = 5;				   
		}				
	}	
	public Icon getIcon(){return icon;}
	
	public void buildPixels()
	{
		pButtons = new JPanel(); // this will hold the pixel buttons.
		int row = Integer.parseInt(JOptionPane.showInputDialog("Select a row..."));
		int col = Integer.parseInt(JOptionPane.showInputDialog("Select a col..."));
		icon = new Icon(row,col);
		pixelPress e = new pixelPress();
	    pButtons.setLayout(new GridLayout(getIcon().getRow(),getIcon().getCol())); // new grid layout of rows and cols
	  //  pixel = new PixelButton[getIcon().getRow()][getIcon().getCol()];
	   pixel = new ArrayList<ArrayList<PixelButton>>();
	    for (int r = 0; r < getIcon().getRow(); r++)
	    {
	    	ArrayList<PixelButton> listRow = new ArrayList<PixelButton>();
	    	 for (int c = 0; c < getIcon().getCol(); c++)
	    	 {
	    		 PixelButton newPixel = new PixelButton(r,c);
	    		 listRow.add(newPixel);
	    	 }
	    	 pixel.add(listRow);
	    	 for (int c = 0; c < getIcon().getCol(); c++)
	    	 {
		    	 pixel.get(r).get(c).addActionListener(e); //each pixel has an action listener
		    	 pixel.get(r).get(c).setBackground(Color.WHITE);
	    		 icon.getPixel(r,c).setRGB(255,255,255);//sets the pixel at the pressed buttons row,col to white
	    		 pButtons.add(pixel.get(r).get(c));
	    	 }
	    }
	}

}
