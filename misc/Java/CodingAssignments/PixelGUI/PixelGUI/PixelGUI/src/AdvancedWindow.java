import java.awt.*;

import javax.swing.*;
public class AdvancedWindow extends JDialog
{
	 public AdvancedWindow(JFrame frame)
	 {
		 super(frame,"Advanced Options",true);
		 setLayout(new FlowLayout());
		 setSize(300,150);
		 setLocation(100,100);	
		 setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);	
	
	 }
}
