public class Cooking extends MicrowaveState
{
	//one and only instance
	private static Cooking instance = null;

	//private constructor
	private Cooking()
	{
	}

	//singleton get instance
	public static Cooking getInstance()
	{
		if(instance == null)
		{
			instance = new Cooking();
		}

		return instance;
	}

	//handle these events in this state
	public void cancel(Microwave m)
	{
		//print current state, event and next state
		System.out.println("In COOKING");
		System.out.println("Handling cancel");

		//change state telling the context object which 
		//state to transition to
		m.changeState(Idle.getInstance());

		System.out.println("Transition to IDLE");
	}
}