import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * This is a driver for the simple microwave application
 * that uses the state pattern
 */
public class MWDriver extends JFrame implements ActionListener
{
	//create a microwave object
	Microwave micro;

	//GUI stuff
    private JButton start;
    private JButton cancel;
    private JButton setTime;

    private JButton b0;
    private JButton b1;
    private JButton b2;
    private JButton b3;
    private JButton b4;
    private JButton b5;
    private JButton b6;
    private JButton b7;
    private JButton b8;
    private JButton b9;
    private JPanel nums;
    private JPanel buttons;

	/**
	 * Build the gui
	 */
    public MWDriver()
    {
		super("Microwave Application");

		micro = new Microwave();

		//GUI setup
        buttons = new JPanel();
        buttons.setLayout(new GridLayout(1, 3));

        start = new JButton("Start");
        start.addActionListener(this);
        buttons.add(start);

        cancel = new JButton("Cancel");
        cancel.addActionListener(this);
        buttons.add(cancel);

        setTime = new JButton("Set Time");
        setTime.addActionListener(this);
        buttons.add(setTime);

        nums = new JPanel();
        nums.setLayout(new GridLayout(4, 3));

        b1= new JButton("1");
        b1.addActionListener(this);
        nums.add(b1);

        b2= new JButton("2");
        b2.addActionListener(this);
        nums.add(b2);

        b3= new JButton("3");
        b3.addActionListener(this);
        nums.add(b3);

        b4= new JButton("4");
        b4.addActionListener(this);
        nums.add(b4);

        b5= new JButton("5");
        b5.addActionListener(this);
        nums.add(b5);

        b6= new JButton("6");
        b6.addActionListener(this);
        nums.add(b6);

        b7= new JButton("7");
        b7.addActionListener(this);
        nums.add(b7);

        b8= new JButton("8");
        b8.addActionListener(this);
        nums.add(b8);

        b9= new JButton("9");
        b9.addActionListener(this);
        nums.add(b9);

        nums.add(new JLabel(""));

        b0= new JButton("0");
        b0.addActionListener(this);
        nums.add(b0);

		getContentPane().setLayout(new BorderLayout());
        getContentPane().add(nums, BorderLayout.NORTH);
        getContentPane().add(buttons, BorderLayout.SOUTH);
    }

	/**
	 * This method will handle all button events
	 */
    public void actionPerformed(ActionEvent e)
    {
		if(e.getActionCommand().equals("Start"))
        {
			//ask the state machine to handle the event
			micro.pressStart();
		}
        else if(e.getActionCommand().equals("Cancel"))
        {
			//ask the state machine to handle the event
			micro.pressCancel();
        }
        else if(e.getActionCommand().equals("Set Time"))
        {
			//ask the state machine to handle the event
			micro.pressEnterTime();
        }
        else //a number was pressed
        {
			//ask the state machine to handle the event
			micro.pressNumber(Integer.parseInt(e.getActionCommand()));
        }
    }
    public static void main(String args[])
    {
		MWDriver mw = new MWDriver();

		mw.setSize(300, 175);
		mw.setLocation(100, 300);
		mw.setVisible(true);
		mw.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}