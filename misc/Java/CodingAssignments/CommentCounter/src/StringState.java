/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:57 PM
 * Project Name CommentCounter
 */
public class StringState extends ReaderState {
    private static StringState instance = null;

    //private constructor
    private StringState()
    {
    }
    //singleton get instance
    public static StringState getInstance()
    {
        if(instance == null)
            instance = new StringState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        r.addToNumCode(1);
    }

    @Override
    public void Char(Reader r) {
        r.addToNumCode(1);
    }

    @Override
    public void Star(Reader r) {
        r.addToNumCode(1);
    }

    @Override
    public void Quote(Reader r) {
        System.out.println("Now in the Code State");
        r.addToNumCode(1);
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void BackSlash(Reader r) {
        System.out.println("Now in the Escape State");
        r.changeState(EscapeState.getInstance());
        r.addToNumCode(1);
    }

    @Override
    public void Apostrophe(Reader r) {
        r.addToNumCode(1);
    }

    @Override
    public void NewLine(Reader r) {
       // r.addToNumCode(1);
    }
}
