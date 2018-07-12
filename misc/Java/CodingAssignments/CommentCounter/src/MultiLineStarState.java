/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:59 PM
 * Project Name CommentCounter
 */
public class MultiLineStarState extends ReaderState {
    private static MultiLineStarState instance = null;

    //private constructor
    private MultiLineStarState()
    {
    }
    //singleton get instance
    public static MultiLineStarState getInstance()
    {
        if(instance == null)
            instance = new MultiLineStarState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {

        System.out.println("Now in the Code State");
        r.addToNumMultiLine(2);
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void Char(Reader r) {
        System.out.println("Now in the MultiLine Comment State");
        r.addToNumMultiLine(2);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void Star(Reader r) {
        System.out.println("Now in the MultiLine Comment State");
        r.addToNumMultiLine(2);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void Quote(Reader r) {
        System.out.println("Now in the MultiLine Comment State");
        r.addToNumMultiLine(2);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void BackSlash(Reader r) {
        System.out.println("Now in the MultiLine Comment State");
        r.addToNumMultiLine(2);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void Apostrophe(Reader r) {
        System.out.println("Now in the MultiLine Comment State");
        r.addToNumMultiLine(2);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void NewLine(Reader r) {
        System.out.println("Now in the MultiLine Comment State");
        //r.addToNumMultiLine(1);
        r.changeState(MultiLineCommentState.getInstance());
    }
}
