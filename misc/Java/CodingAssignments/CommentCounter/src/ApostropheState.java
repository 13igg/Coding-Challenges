/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:57 PM
 * Project Name CommentCounter
 */
public class ApostropheState extends ReaderState  {
    private static ApostropheState instance = null;

    //private constructor
    private ApostropheState()
    {
    }
    //singleton get instance
    public static ApostropheState getInstance()
    {
        if(instance == null)
            instance = new ApostropheState();
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
        r.addToNumCode(1);
    }

    @Override
    public void BackSlash(Reader r) {
        System.out.println("Now in the backSlash State");
        r.addToNumCode(1);
    }

    @Override
    public void Apostrophe(Reader r) {
        System.out.println("Now in the Code State");
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void NewLine(Reader r) {
        // r.addToNumCode(1);
    }
}
