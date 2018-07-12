import java.awt.*;  //always include these imports with a GUI app
import java.awt.event.*;
import javax.swing.*;

/**
 * This class is the GUI observer for the time object in the
 * system.
 */
public class JFrameTime extends JFrame implements Observer, ActionListener
{
	//reference to the subject we are observing
    private MyTime time;

    //gui widgets
    private JLabel prompt;
    private JLabel colon1;
    private JLabel colon2;
    private JLabel results;
    private JButton start;
    private JTextField hour;
    private JTextField minute;
    private JTextField second;

    /**
     * Constructor that sets up the gui and sets the time object to
     * observe.
     */
    public JFrameTime(MyTime mt)
    {
        super("This is a clock (Observer Pattern)");

		//store a reference to the subject, we will observe it
        time = mt;

		//attach 'this' observer to the subject. Whenever the subject changes
		//'this' object will be updated
        time.attach(this);

		//set up the gui
        getContentPane().setLayout(new FlowLayout());

        prompt = new JLabel("Enter the time: ");
        getContentPane().add(prompt);

        hour = new JTextField(4);
        getContentPane().add(hour);

        colon1 = new JLabel(":");
        getContentPane().add(colon1);

        minute = new JTextField(4);
        getContentPane().add(minute);

        colon2 = new JLabel(":");
        getContentPane().add(colon2);

        second= new JTextField(4);
        getContentPane().add(second);

        start = new JButton("Start Incrementing the time");
        start.addActionListener(this);
        getContentPane().add(start);

        results = new JLabel();
        getContentPane().add(results);
    }

	/**
	 * This method will be called in response to a button press. We will
	 * get the values in the text boxes and set the time. All the observers
	 * should be updated accordingly.
	 */
    public void actionPerformed(ActionEvent e)
    {
		//get the time from the text boxes and use the subject (time) to set the
		//new time. The subject will then notify all the observers (including this one)
        time.setTime(Integer.parseInt(hour.getText()), Integer.parseInt(minute.getText()), Integer.parseInt(second.getText()));

        //indicate that we should start the clock
        time.setClockStarted(true);

        //clear the input box so they are all empty
        hour.setText("");
        minute.setText("");
        second.setText("");
    }
    /**
     * This method is called by the subject every time the state of the subject
     * change. This object will get the new time from the time reference and
     * write it to the label.
     */
    public void update()
    {
		//get the time from the subject and write it to the label in this gui
        results.setText(time.getTime());
    }
}