/**
 * User: Matt
 * Date: 5/2/13
 * Time: 6:00 PM
 * Project Name CommentCounter
 */
public class JavadocStarState extends ReaderState {
    private static JavadocStarState instance = null;

    //private constructor
    private JavadocStarState()
    {
    }
    //singleton get instance
    public static JavadocStarState getInstance()
    {
        if(instance == null)
            instance = new JavadocStarState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        System.out.print("Now in the Code State");
        r.addToNumJavaDoc(2);
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void Char(Reader r) {
        System.out.print("Now in the Slash Star Star State");
        r.addToNumJavaDoc(2);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void Star(Reader r) {
        System.out.print("Now in the Slash Star Star State");
        r.addToNumJavaDoc(2);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void Quote(Reader r) {
        System.out.print("Now in the Slash Star Star State");
        r.addToNumJavaDoc(2);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void BackSlash(Reader r) {
        System.out.print("Now in the Slash Star Star State");
        r.addToNumJavaDoc(2);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void Apostrophe(Reader r) {
        System.out.print("Now in the Slash Star Star State");
        r.addToNumJavaDoc(2);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void NewLine(Reader r) {
        System.out.print("Now in the Slash Star Star State");
        r.addToNumJavaDoc(1);
        r.changeState(SlashStarStarState.getInstance());
    }
}
