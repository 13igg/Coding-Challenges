/**
 * User: Matt
 * Date: 5/3/13
 * Time: 6:23 PM
 * Project Name CommentCounter
 */
public class EscapeState extends ReaderState {
        private static EscapeState instance = null;

        //private constructor
        private EscapeState()
        {
        }
        //singleton get instance
        public static EscapeState getInstance()
        {
            if(instance == null)
                instance = new EscapeState();
            return instance;
        }

        @Override
        public void Slash(Reader r) {
            System.out.println("Now in the String State");
            r.addToNumCode(1);
            r.changeState(StringState.getInstance());
        }

        @Override
        public void Char(Reader r) {
            System.out.println("Now in the String State");
            r.addToNumCode(1);
            r.changeState(StringState.getInstance());
        }

        @Override
        public void Star(Reader r) {
            System.out.println("Now in the String State");
            r.addToNumCode(1);
            r.changeState(StringState.getInstance());
        }

        @Override
        public void Quote(Reader r) {
            System.out.println("Now in the String State");
            r.addToNumCode(1);
            r.changeState(StringState.getInstance());
        }

        @Override
        public void BackSlash(Reader r) {
            System.out.println("Now in the Escape State");
            r.changeState(StringState.getInstance());
            r.addToNumCode(1);
        }

        @Override
        public void Apostrophe(Reader r) {
            System.out.println("Now in the String State");
            r.addToNumCode(1);
            r.changeState(StringState.getInstance());
        }

        @Override
        public void NewLine(Reader r) {
            // r.addToNumCode(1);
        }
    }
