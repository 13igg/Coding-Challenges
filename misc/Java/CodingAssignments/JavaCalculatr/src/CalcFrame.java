import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
public class CalcFrame extends JFrame
{
	private JButton jbtNum1;
    private JButton jbtNum2;
    private JButton jbtNum3;
    private JButton jbtNum4;
    private JButton jbtNum5;
    private JButton jbtNum6;
    private JButton jbtNum7;
    private JButton jbtNum8;
    private JButton jbtNum9;
    private JButton jbtNum0;
    private JButton jbtEquals;
    private JButton jbtAdd;
    private JButton jbtSubtract;
    private JButton jbtMultiply;
    private JButton jbtDivide;
    private JButton jbtClear;
    
    private JTextField jEntry;
	
    public CalcFrame()
	{
		super("Calculator");
		buildGUI();
		
		setVisible(true);
		setSize(400,300);
		setLocation(100,100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public void buildGUI()
	{
		JPanel gb = new JPanel();
		gb.setLayout(new GridBagLayout());	
		GridBagConstraints C = new GridBagConstraints();
		
		C.fill = GridBagConstraints.HORIZONTAL;
		C.gridx = 0;
		C.gridy = 0;	
	    JPanel p = new JPanel();
	    p.add(jEntry = new JTextField("",15));    
	    gb.add(p,C);
	    
		C.fill = GridBagConstraints.HORIZONTAL;
		C.gridx = 0;
		C.gridy = 1;	
		JPanel p1 = new JPanel();
		p1.setLayout(new GridLayout(4,3));
	    p1.add(jbtNum1 = new JButton("1"));
	    p1.add(jbtNum2 = new JButton("2"));
	    p1.add(jbtNum3 = new JButton("3"));
	    p1.add(jbtNum4 = new JButton("4"));
	    p1.add(jbtNum5 = new JButton("5"));
	    p1.add(jbtNum6 = new JButton("6"));
	    p1.add(jbtNum7 = new JButton("7"));
	    p1.add(jbtNum8 = new JButton("8"));
	    p1.add(jbtNum9 = new JButton("9"));
	    p1.add(jbtNum0 = new JButton("0"));
	    p1.add(new JButton());
	    p1.add(jbtClear = new JButton("C"));
	    gb.add(p1,C);
	     
	    C.fill = GridBagConstraints.HORIZONTAL;
		C.gridx = 1;
		C.gridy = 1;	
		JPanel p2 = new JPanel();
		p2.setLayout(new GridLayout(5,1));
		p2.add(jbtAdd = new JButton("+"));
		p2.add(jbtSubtract = new JButton("-"));
		p2.add(jbtMultiply = new JButton("X"));
		p2.add(jbtDivide = new JButton("/"));
		p2.add(jbtEquals = new JButton("="));
		gb.add(p2,C);
		
		add(gb);
	    
		
	}

}
