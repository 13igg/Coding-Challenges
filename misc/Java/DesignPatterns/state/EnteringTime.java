public class EnteringTime extends MicrowaveState
{
	//one and only instance
	private static EnteringTime instance = null;

	//private constructor
	private EnteringTime()
	{
	}

	//singleton get instance
	public static EnteringTime getInstance()
	{
		if(instance == null)
		{
			instance = new EnteringTime();
		}

		return instance;
	}

	//handle these events in this state
	public void number(Microwave m, int num)
	{
		System.out.println("In ENTERINGTIME");
		System.out.println("Handling number");

		//append the number to the string
		m.setTimeString(m.getTimeString() + String.valueOf(num));

		//display the new time
		System.out.println("New time: " + m.getTimeString());
	}
	public void start(Microwave m)
	{
		//print current state, event and next state
		System.out.println("In ENTERINGTIME");
		System.out.println("Handling start");
		if(!m.getTimeString().isEmpty())
		{
			m.setTimeString("");

			//change state telling the context object which 
			//state to transition to
			m.changeState(Cooking.getInstance());

			System.out.println("Transition to COOKING");
		}
		else
		{
			System.out.println("Ignoring start");
		}
	}
	public void cancel(Microwave m)
	{
		//print current state, event and next state
		System.out.println("In ENTERINGTIME");
		System.out.println("Handling cancel");

		m.setTimeString("");

		//change state telling the context object which 
		//state to transition to
		m.changeState(Idle.getInstance());

		System.out.println("Transition to IDLE");
	}
}