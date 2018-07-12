public class Microwave
{
	//reference to a state object
	private MicrowaveState currentState;
	
	//string that holds the display text
	private String timeString = "";
	
	public Microwave()
	{
		//set the current state to IDLE
		changeState(Idle.getInstance());

		System.out.println("Starting State: IDLE");
	}

	public void changeState(MicrowaveState newState)
	{
		//change the state to point to a new state
		currentState = newState;
	}

	public void pressStart()
	{
		//ask the current state to handle the event
		currentState.start(this);
	}

	public void pressCancel()
	{
		//ask the current state to handle the event
		currentState.cancel(this);
	}

	public void pressEnterTime()
	{
		//ask the current state to handle the event
		currentState.enterTime(this);
	}

	public void pressNumber(int n)
	{
		//ask the current state to handle the event
		currentState.number(this, n);
	}
	
	public String getTimeString()
	{
		return timeString;
	}
	
	public void setTimeString(String ts)
	{
		timeString = ts;
	}
}