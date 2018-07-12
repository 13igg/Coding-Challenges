/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:58 PM
 * Project Name CommentCounter
 */
public class MultiLineCommentState extends ReaderState {
    private static MultiLineCommentState instance = null;

    //private constructor
    private MultiLineCommentState()
    {
    }
    //singleton get instance
    public static MultiLineCommentState getInstance()
    {
        if(instance == null)
            instance = new MultiLineCommentState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        r.addToNumMultiLine(1);
    }

    @Override
    public void Char(Reader r) {
        r.addToNumMultiLine(1);
    }

    @Override
    public void Star(Reader r) {
        System.out.println("Now in the MultiLine Star State");
        r.changeState(MultiLineStarState.getInstance());
    }

    @Override
    public void Quote(Reader r) {
        r.addToNumMultiLine(1);
    }

    @Override
    public void BackSlash(Reader r) {
        r.addToNumMultiLine(1);
    }

    @Override
    public void Apostrophe(Reader r) {
        r.addToNumMultiLine(1);
    }

    @Override
    public void NewLine(Reader r) {
        //r.addToNumMultiLine(1);
    }
}
