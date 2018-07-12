public class MicrowaveState
{
	public void start(Microwave m)
	{
		//inherit an error message for all subclasses
		System.out.println("Invalid Event: start");
	}

	public void cancel(Microwave m)
	{
		//inherit an error message for all subclasses
		System.out.println("Invalid Event: cancel");
	}

	public void enterTime(Microwave m)
	{
		//inherit an error message for all subclasses
		System.out.println("Invalid Event: enterTime");
	}

	public void number(Microwave m, int num)
	{
		//inherit an error message for all subclasses
		System.out.println("Invalid Event: number");
	}
}