
/**
 * Created with IntelliJ IDEA.
 * User: Matt
 * Date: 4/17/13
 * Time: 8:19 PM
 * To change this template use File | Settings | File Templates.
 */
public class TextObject implements Subject {
    //reference to the subject that handles notifying observers
    private SubjectImpl subjectImpl;
    private String text;

    public TextObject()
    {
        text = "";
        subjectImpl = new SubjectImpl();
    }

    public void setText(String text) throws Exception {
        this.text = text;
        notifyAllObservers(text);
    }
    //delegate all functionality to the impl
    public void attach(Observer o)
    {
        subjectImpl.attach(o);
    }
    public void detach(Observer o)
    {
        subjectImpl.detach(o);
    }
    public void notifyAllObservers(String message) throws Exception {
        //notify all observers that the time has changed
        subjectImpl.notifyAllObservers(message);
    }
}
