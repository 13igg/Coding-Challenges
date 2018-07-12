/**
 * Created with IntelliJ IDEA.
 * User: Matt
 * Date: 4/17/13
 * Time: 8:00 PM
 * To change this template use File | Settings | File Templates.
 */
import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;

public class GUI extends JFrame implements Observer {

    private TextObject to;
    private JTextArea t;
    private DocumentListener docListener;
    private Boolean needsToUpdate;
    public GUI(TextObject text)
    {
        super("Code Editor");
        needsToUpdate = true;
        setVisible(true);

        t = new JTextArea();
        t.setLineWrap(true);
        t.setPreferredSize(new Dimension(175,175));
        to = text;
        to.attach(this);

        docListener = new DocumentListener()
        {
            /**
             * This method will be called in response to a button press. We will
             * get the values in the text boxes and set the time. All the observers
             * should be updated accordingly.
             */
            @Override
            public void insertUpdate(DocumentEvent e) {
                needsToUpdate = false;
                to.setText(t.getText());
            }
            @Override
            public void removeUpdate(DocumentEvent e) {
                needsToUpdate = false;
                to.setText(t.getText());
            }
            @Override
            public void changedUpdate(DocumentEvent e) {
                needsToUpdate = false;
                to.setText(t.getText());
            }
        };
        t.getDocument().addDocumentListener(docListener);
        add(t);
    }

    /**
     * This method is called by the subject every time the state of the subject
     * change. This object will get the new time from the time reference and
     * write it to the label.
     */
    public void update()
    {
        if(needsToUpdate)
        {
            t.getDocument().removeDocumentListener(docListener);

            t.setText(to.getText());

            t.getDocument().addDocumentListener(docListener);
        }
        needsToUpdate = true;

    }
}
