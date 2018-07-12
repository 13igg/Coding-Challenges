
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
        subjectImpl = new SubjectImpl();
    }
    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
        refresh();
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
    public void notifyAllObservers()
    {
        subjectImpl.notifyAllObservers();
    }

    //notify all observers that the time has changed
    public void refresh()
    {
         notifyAllObservers();
    }
}
