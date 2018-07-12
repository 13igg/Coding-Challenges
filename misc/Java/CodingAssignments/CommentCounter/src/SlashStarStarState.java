/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:59 PM
 * Project Name CommentCounter
 */
public class SlashStarStarState extends ReaderState {
    private static SlashStarStarState instance = null;

    //private constructor
    private SlashStarStarState()
    {
    }
    //singleton get instance
    public static SlashStarStarState getInstance()
    {
        if(instance == null)
            instance = new SlashStarStarState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        r.addToNumJavaDoc(1);
    }

    @Override
    public void Char(Reader r) {
        r.addToNumJavaDoc(1);
    }

    @Override
    public void Star(Reader r) {
        System.out.println("Now in the JavaDdc Star State");
        r.changeState(JavadocStarState.getInstance());
    }

    @Override
    public void Quote(Reader r) {
        r.addToNumJavaDoc(1);
    }

    @Override
    public void BackSlash(Reader r) {
        r.addToNumJavaDoc(1);
    }

    @Override
    public void Apostrophe(Reader r) {
        r.addToNumJavaDoc(1);
    }

    @Override
    public void NewLine(Reader r) {
       // r.addToNumJavaDoc(1);
    }
}
