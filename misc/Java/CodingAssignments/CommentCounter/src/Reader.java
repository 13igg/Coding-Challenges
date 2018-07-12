import java.io.File;
import java.io.FileReader;
/**
 * User: Matt
 * Date: 5/2/13
 * Time: 6:08 PM
 * Project Name CommentCounter
 */
public class Reader {
    //reference to a state object
    private ReaderState currentState;

    public int numCode;
    public int numComment;
    public int numJavaDoc;
    public int numMultiLine;

    public Reader()
    {
        //set the current state to IDLE
        changeState(CodeState.getInstance());
        System.out.println("Starting State: CodeState");
        //numCode = numComment = numJavaDoc = numMultiLine = 0;
    }

    public void changeState(ReaderState newState)
    {
        //change the state to point to a new state
        currentState = newState;
    }

    public void openFile(File f)  throws Exception
    {
        //reset to 0 for a new run
        numCode = 0;numComment = 0; numJavaDoc = 0;numMultiLine = 0;
        changeState(CodeState.getInstance());

        FileReader inputStream;
        inputStream = new FileReader(f);
         int c;

        while ((c = inputStream.read()) != -1)
        {
            if(c == 47)      // /
                currentState.Slash(this);
            else if(c == 42) // *
                currentState.Star(this);
            else if (c == 34)// "
                currentState.Quote(this);
            else if (c == 92)// \
                currentState.BackSlash(this);
            else if (c == 39)// '
                currentState.Apostrophe(this);
            else if(c == 10) // /n
                currentState.NewLine(this);
            else if(c != 13) // asdfasdffdqw4yut978
                currentState.Char(this);
        }
        if (inputStream != null)
            inputStream.close();
        //
        /*d*/
        /**d*/
        System.out.println("\nCode = " + getNumCode() + " out of = 6406");
        System.out.println("Comment = " + (getNumMultiLine() + getNumComment()) + " out of = 2774");
        System.out.println("Javadoc Comments = " + getNumJavaDoc() + " out of = 2078");
        System.out.println("Total text = " + ((getNumMultiLine() + getNumComment()) + getNumJavaDoc() + getNumCode()) + " out of = " + (6406+2774+2078));
       // System.out.println("\nSingleLine Comments = " + getNumComment());
       // System.out.println("MultiLine Comments = " + getNumMultiLine());
    }



    public int getNumCode() {
        return numCode;
    }

    public void setNumCode(int numCode) {
        this.numCode = numCode;
    }

    public void addToNumCode(int add) {
        setNumCode(getNumCode()+add);
    }


    public int getNumMultiLine() {
        return numMultiLine;
    }

    public void setNumMultiLine(int numMultiLine) {
        this.numMultiLine = numMultiLine;
    }

    public void addToNumMultiLine(int add) {
        setNumMultiLine(getNumMultiLine() + add);
    }


    public int getNumJavaDoc() {
        return numJavaDoc;
    }

    public void setNumJavaDoc(int numJavaDoc) {
        this.numJavaDoc = numJavaDoc;
    }

    public void addToNumJavaDoc(int add) {
        setNumJavaDoc(getNumJavaDoc() + add);
    }



    public int getNumComment() {
        return numComment;
    }

    public void setNumComment(int numComment) {
        this.numComment = numComment;
    }

    public void addToNumComment(int add) {
        setNumComment(getNumComment() + add);
    }
}
