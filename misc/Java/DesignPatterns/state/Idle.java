public class Idle extends MicrowaveState
{
	//one and only instance
	private static Idle instance = null;

	//private constructor
	private Idle()
	{
	}

	//singleton get instance
	public static Idle getInstance()
	{
		if(instance == null)
		{
			instance = new Idle();
		}

		return instance;
	}

	//handle these events in this state
	public void enterTime(Microwave m)
	{
		//print current state, event and next state
		System.out.println("In IDLE");
		System.out.println("Handling enterTime");

		//change state telling the context object which 
		//state to transition to
		m.changeState(EnteringTime.getInstance());

		System.out.println("Transition to EnteringTime");

		//clear screen and do other interesting actions
	}
}










