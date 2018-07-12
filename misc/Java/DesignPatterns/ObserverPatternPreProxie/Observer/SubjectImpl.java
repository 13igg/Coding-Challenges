import java.util.*;

/**
 * Implementation of the Subject interface (this is done so concrete
 * Subjects can extend or inherit from some other class)
 */
public class SubjectImpl implements Subject 
{
	//holds all the observers interested in being notified when the subject changes
	private List < Observer > observers;
	
	public SubjectImpl()
	{
		//create an empty list
		observers = new ArrayList < Observer >();
	}

	public void attach(Observer o) 
	{
		//add the passed in observer to the list
		observers.add(o);
	}

	public void detach(Observer o) 
	{
		//remove the observer from the list
		observers.remove(o);
	}

	public void notifyAllObservers() 
	{
		//for all the observers in the list
		for(Observer observer : observers)
		{
			//ask each observer to update itself
			observer.update();
		}
	}
}
