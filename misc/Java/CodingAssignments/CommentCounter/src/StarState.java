/**
 * User: Matt
 * Date: 5/2/13
 * Time: 5:59 PM
 * Project Name CommentCounter
 */
public class StarState extends ReaderState {
    private static StarState instance = null;

    //private constructor
    private StarState()
    {
    }
    //singleton get instance
    public static StarState getInstance()
    {
        if(instance == null)
            instance = new StarState();
        return instance;
    }

    @Override
    public void Slash(Reader r) {
        System.out.println("Now in the Code State");
        r.addToNumMultiLine(4);
        r.changeState(CodeState.getInstance());
    }

    @Override
    public void Char(Reader r) {
        System.out.println("Now in the Slash Star Star State");
        r.addToNumJavaDoc(4);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void Star(Reader r) {
        System.out.println("Now in the Javadoc Star State");
        r.addToNumJavaDoc(3);
        r.changeState(JavadocStarState.getInstance());
    }

    @Override
    public void Quote(Reader r) {
        System.out.println("Now in the Slash Star Star State");
        r.addToNumJavaDoc(4);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void BackSlash(Reader r) {
        System.out.println("Now in the Slash Star Star State");
        r.addToNumJavaDoc(4);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void Apostrophe(Reader r) {
        System.out.println("Now in the Slash Star Star State");
        r.addToNumJavaDoc(4);
        r.changeState(SlashStarStarState.getInstance());
    }

    @Override
    public void NewLine(Reader r) {
        System.out.println("Now in the Slash Star Star State");
        r.addToNumJavaDoc(3);
        r.changeState(SlashStarStarState.getInstance());
    }
}
