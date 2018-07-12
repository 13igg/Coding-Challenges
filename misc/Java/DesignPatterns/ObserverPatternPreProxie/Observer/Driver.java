import java.awt.*;  //always include these imports with a GUI app
import java.awt.event.*;
import javax.swing.*;

/**
 * This is the driver for the time application. It creates several
 * GUI's and a non-gui object that observes a time object.
 */
public class Driver
{
    public static void main(String args[])
    {
		//create the one shared time object
        MyTime time = new MyTime();

        //set the time to 06:30:00
        time.setTime(6, 30, 0);
        time.setClockStarted(true);

        //create the non-gui observer
        CommandLineTime clt = new CommandLineTime(time);

        //create 4 GUI observers
        JFrameTime jft = new JFrameTime(time);
        JFrameTime jft2 = new JFrameTime(time);
        JFrameTime jft3 = new JFrameTime(time);
        JFrameTime jft4 = new JFrameTime(time);

        //close when the 'x' is clicked
        jft.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jft2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jft3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jft4.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //set the dimensions of the window
        jft.setSize(500, 100);
		jft2.setSize(500, 100);
		jft3.setSize(500, 100);
		jft4.setSize(500, 100);

		//stagger the locations of the JFrames
		jft.setLocation(100, 100);
		jft2.setLocation(200, 200);
		jft3.setLocation(300, 300);
		jft4.setLocation(400, 400);
		
        //make them visible
        jft.setVisible(true);
        jft2.setVisible(true);
        jft3.setVisible(true);
        jft4.setVisible(true);

		//forever
        while(true)
        {
			//if the clock has been started
            if(time.getClockStarted())
            {
                //increment the time by one second (this will result in
                //all the observers being notified)
                time.increment();

                //sleep for one second before incrementing the second
                try
                {
                    Thread.sleep(1000);
                }
                catch(InterruptedException e)
                {
					System.out.println("Thread Interrupted");
                    e.printStackTrace();
                }
            }
        }
    }
}