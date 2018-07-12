/**
 * This defines a subject, or piece of data that is observed
 */
public interface Subject 
{
	//an observer will add itself to the list of those interested in this data
	public void attach(Observer o);
	//an observer can detach itself if it is no longer interested
	public void detach(Observer o);
	//called by a concrete subject when the data changes (notifies all observers)
	public void notifyAllObservers();
}
