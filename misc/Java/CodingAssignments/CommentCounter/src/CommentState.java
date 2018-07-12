/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:57 PM
 * Project Name CommentCounter
 */
public class CommentState extends ReaderState{
    private static CommentState instance = null;

    //private constructor
    private CommentState()
    {
    }
    //singleton get instance
    public static CommentState getInstance()
    {
        if(instance == null)
            instance = new CommentState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        r.addToNumComment(1);
    }                 //    kljsdalkfjslkjf"*?*/8/8"*"*


    @Override
    public void Char(Reader r) {
        r.addToNumComment(1);
    }

    @Override
    public void Star(Reader r) {
        r.addToNumComment(1);
    }

    @Override
    public void Quote(Reader r) {
        r.addToNumComment(1);
    }

    @Override
    public void BackSlash(Reader r) {
        r.addToNumComment(1);
    }

    @Override
    public void Apostrophe(Reader r) {
        r.addToNumComment(1);
    }

    @Override
    public void NewLine(Reader r) {
        System.out.println("Now in the Code State");
        //r.addToNumCode(1);
        r.changeState(CodeState.getInstance());
    }
}
