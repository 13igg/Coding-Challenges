/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:58 PM
 * Project Name CommentCounter
 */
public class SlashStarState extends ReaderState{
    private static SlashStarState instance = null;

    //private constructor
    private SlashStarState()
    {
    }
    //singleton get instance
    public static SlashStarState getInstance()
    {
        if(instance == null)
            instance = new SlashStarState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        System.out.println("Now in the MultiLine State");
        r.addToNumMultiLine(3);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void Char(Reader r) {
        System.out.println("Now in the MultiLine State");
        r.addToNumMultiLine(3);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void Star(Reader r) {
        System.out.println("Now in the Star State");
        r.changeState(StarState.getInstance());
    }

    @Override
    public void Quote(Reader r) {
        System.out.println("Now in the MultiLine State");
        r.addToNumMultiLine(3);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void BackSlash(Reader r) {
        System.out.println("Now in the MultiLine State");
        r.addToNumMultiLine(3);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void Apostrophe(Reader r) {
        System.out.println("Now in the MultiLine State");
        r.addToNumMultiLine(3);
        r.changeState(MultiLineCommentState.getInstance());
    }

    @Override
    public void NewLine(Reader r) {
        System.out.println("Now in the MultiLine State");
        r.addToNumMultiLine(2);
        r.changeState(MultiLineCommentState.getInstance());
    }
}
