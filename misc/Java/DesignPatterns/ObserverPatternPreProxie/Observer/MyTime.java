
/**
 * This is a class that represents time. It also is a concrete subject
 * that observers can attach to so they can observe any changes
 * to the time.
 */
public class MyTime implements Subject
{
	//data for the time
    private int second;
    private int minute;
    private int hour;
    private boolean clockStarted;

    //reference to the subject that handles notifying observers
    private SubjectImpl subjectImpl;

    //delegate all functionality to the impl
    public void attach(Observer o)
	{
		subjectImpl.attach(o);
	}
    public void detach(Observer o)
	{
    	subjectImpl.detach(o);
	}
    public void notifyAllObservers()
	{
    	subjectImpl.notifyAllObservers();
	}
    
	/**
	 * Constructor that creates the impl, initializes the time, and sets
	 * the clock started flag to false
	 */
    public MyTime()
    {
    	//create the subject impl
    	subjectImpl = new SubjectImpl();
    	
        //set the time
        setTime(0, 0, 0);

        //indicate that we should not start incrementing yet
        setClockStarted(false);
    }

	/**
	 * set the time and roll over the seconds, minutes, and seconds
	 */
    public void increment()
    {
		//if it is not the last second in a minute
        if(getSecond() != 59)
        {
			//simply add one second to the current second
            setSecond(getSecond() + 1);
        }
        else //it is the last second in the minute
        {
			//wrap the seconds back to 0 and add a minute
            setSecond(0);

            //if this is not the last minute in an hour
            if(getMinute() != 59)
            {
				//add a minute to the current number of minutes
                setMinute(getMinute() + 1);
            }
            else //it is the last minute in an hour
            {
				//wrap the minutes back to 0 and add an hour
                setMinute(0);

                //if it is not the last hour in the day
                if(getHour() != 23)
                {
					//add one to the current hour number
                    setHour(getHour() + 1);
                }
                else //it is the last hour in the day, wrap back to 0
                {
                    setHour(0);
                }
            }
        }
        
        //notify all observers that the time has changed
        notifyAllObservers();

    }
    /**
     * Build a string with the current time
     */
    public String getTime()
    {
		//get the hour
        StringBuffer retVal = new StringBuffer();

		if(getHour() < 10)
		{
			retVal.append("0");
		}

		retVal.append(Integer.toString(getHour()));

		//add a colon
        retVal.append(":");

        //add a zero in the minute spot
        if(getMinute() < 10)
        {
            retVal.append("0");
        }

        //add the minute
        retVal.append(Integer.toString(getMinute()));

        //add a colon
        retVal.append(":");

		//add a zero in the second
        if(getSecond() < 10)
        {
            retVal.append("0");
        }

		//add the second
        retVal.append(Integer.toString(getSecond()));

        return retVal.toString();
    }

	//getters and setters
	/**
	 * Getter for if the clock has been started yet
	 */
    public boolean getClockStarted()
    {
        return clockStarted;
    }

	/**
	 * Getter for if the clock has been started yet
	 */
    public void setClockStarted(boolean b)
    {
        clockStarted = b;
    }

	/**
	 * Set the time, set the clock started flag, and notify all observers
	 */
    public void setTime(int h, int m, int s)
    {
		//set the time
        setHour(h);
        setMinute(m);
        setSecond(s);
    }

	/**
	 * Setter for the hour
	 */
    public void setHour(int h)
    {
        if(h >= 0 && h < 24)
        {
            hour = h;
        }
        else
        {
            hour = 0;
        }
    }

	/**
	 * getter for the hour
	 */
    public int getHour()
    {
        return hour;
    }

	/**
	 * Setter for the minute
	 */
    public void setMinute(int m)
    {
        if(m >= 0 && m < 60)
        {
            minute = m;
        }
        else
        {
            minute = 0;
        }
    }

	/**
	 * getter for the minute
	 */
    public int getMinute()
    {
        return minute;
    }

	/**
	 * Setter for the second
	 */
    public void setSecond(int s)
    {
        if(s >= 0 && s < 60)
        {
            second = s;
        }
        else
        {
            second = 0;
        }
    }

	/**
	 * Getter for the second
	 */
    public int getSecond()
    {
        return second;
    }
}