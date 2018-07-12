/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:57 PM
 * Project Name CommentCounter
 */
public class SlashState extends ReaderState {
    private static SlashState instance = null;

    //private constructor
    private SlashState()
    {
    }
    //singleton get instance
    public static SlashState getInstance()
    {
        if(instance == null)
            instance = new SlashState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        System.out.println("Now in the Comment State");
        r.addToNumComment(2);
        r.changeState(CommentState.getInstance());
    }

    @Override
    public void Char(Reader r) {
        System.out.println("Now in the Code State");
        r.addToNumCode(2);
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void Star(Reader r) {
        System.out.println("Now in the Slash Star State");
        r.changeState(SlashStarState.getInstance());
    }

    @Override
    public void Quote(Reader r) {
        System.out.println("Now in the Code State");
        r.addToNumCode(2);
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void BackSlash(Reader r) {
        System.out.println("Now in the Code State");
        r.addToNumCode(2);
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void Apostrophe(Reader r) {
        System.out.println("Now in the Code State");
        r.addToNumCode(2);
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void NewLine(Reader r) {
        System.out.println("Now in the Code State");
        //r.addToNumCode(2);
        r.changeState(CodeState.getInstance());
    }
}
