/**
 * This is a non-gui version of the time observer. It
 * uses the same classes as GUI.
 */
public class CommandLineTime implements Observer
{
	//reference to the subject we are observing
    private MyTime time;

	/**
	 * Constructor to set the time (subject) and to attach 'this'
	 * to the subject.
	 */
    public CommandLineTime(MyTime mt)
    {
		//set the observer
        time = mt;

        //attach this to the subject
        time.attach(this);
    }
    /**
     * This method will be called when the subject changes. This object
     * will write the new time to the screen.
     */
    public void update()
    {
        System.out.println(time.getTime());
    }
}