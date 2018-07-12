/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:56 PM
 * Project Name CommentCounter
 */
public class CodeState extends ReaderState{
    private static CodeState instance = null;

    //private constructor
    private CodeState()
    {
    }
    //singleton get instance
    public static CodeState getInstance()
    {
        if(instance == null)
            instance = new CodeState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        System.out.println("Now in the Slash State");
        r.changeState(SlashState.getInstance());
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
        System.out.println("Now in the String State");
        r.changeState(StringState.getInstance());
        r.addToNumCode(1);
    }

    @Override
    public void BackSlash(Reader r) {
        r.addToNumCode(1);
    }

    @Override
    public void Apostrophe(Reader r) {
        System.out.println("Now in the String State");
        r.changeState(ApostropheState.getInstance());
        r.addToNumCode(1);
    }

    @Override
    public void NewLine(Reader r) {
        //r.addToNumCode(1);
    }
}
