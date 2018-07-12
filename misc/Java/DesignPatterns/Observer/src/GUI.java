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
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

public class GUI extends JFrame implements Observer{

    private JTextArea t;
    private JButton save;
    private ActionListener actionListener;
    private JFileChooser fileChooser;
    private DocumentListener docListener;
    private Boolean needsToUpdate;

    private  ObserverServerProxy osp;
    private  Thread ocpThread ;
    private  ObserverClientProxy ocp;

    public GUI() throws Exception {
        super("Code Editor");
        JPanel p = new JPanel(new BorderLayout());
        needsToUpdate = true;
        String IPToConnectTo = JOptionPane.showInputDialog("Welcome to the Chat Client! \nEnter the IP address of the machine to connect to: ");

        //store the port number in a string
        String PortToConnectTo = JOptionPane.showInputDialog(("Enter the port number of the application to connect to: "));
        //converts a string to an int
        int port = Integer.parseInt(PortToConnectTo);

        osp = new ObserverServerProxy(IPToConnectTo, port);
        ocp = new ObserverClientProxy(this);

        ocpThread = new Thread(ocp);
        ocpThread.start();

        setVisible(true);
        save = new JButton("SAVE");
       // save.setPreferredSize(new Dimension(50,50));
        t = new JTextArea();
        t.setLineWrap(true);
        t.setPreferredSize(new Dimension(175,175));
        actionListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //To change body of implemented methods use File | Settings | File Templates.
                try {UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());}catch (Exception ef){}
                fileChooser = new JFileChooser();
                FileNameExtensionFilter filter = new FileNameExtensionFilter("TXT File","TXT"); //bmp is the only file tipe
                fileChooser.setFileFilter(filter);//sets above
                fileChooser.setAcceptAllFileFilterUsed(false);
                File desktop = new File("c:\\Users\\Matt\\Desktop\\");//sets desktop as default
                fileChooser.setCurrentDirectory(desktop);//sets desktop as default
                int retVal = fileChooser.showSaveDialog(fileChooser);
                if(retVal == JFileChooser.APPROVE_OPTION)//checks to see if it was run or closed out
                {
                    try
                    {
                        File file = new File( fileChooser.getSelectedFile().toString() + "" + ".TXT");
                        // if file doesnt exists, then create it
                        if (!file.exists())
                            file.createNewFile();
                        FileWriter fw = new FileWriter(file.getAbsoluteFile());
                        BufferedWriter bw = new BufferedWriter(fw);
                        bw.write(t.getText());

                        bw.close();
                    }
                    catch(Exception edd)
                    {

                    }
                }
            }
        };

        docListener = new DocumentListener()
        {
            /**
             * This method will be called in response to a button press. We will
             * get the values in the text boxes and set the time. All the observers
             * should be updated accordingly.
             */
            @Override
            public void insertUpdate(DocumentEvent e) {
                try {
                    needsToUpdate = false;
                    osp.sendToAll(t.getText());
                } catch (Exception e1) {
                    System.out.println("error here");;  //To change body of catch statement use File | Settings | File Templates.
                }
                //send current text to the subject server proxy
            }
            @Override
            public void removeUpdate(DocumentEvent e) {
                try {
                    needsToUpdate = false;
                    osp.sendToAll(t.getText());
                } catch (Exception e1) {
                    System.out.println("error here");;  //To change body of catch statement use File | Settings | File Templates.
                }
                //to.setText(t.getText());
            }
            @Override
            public void changedUpdate(DocumentEvent e) {
                try {
                    needsToUpdate = false;
                    osp.sendToAll(t.getText());
                } catch (Exception e1) {
                    System.out.println("error here");;  //To change body of catch statement use File | Settings | File Templates.
                }
                //to.setText(t.getText());
            }
        };

        save.addActionListener(actionListener);
        t.getDocument().addDocumentListener(docListener);
        p.add(t, BorderLayout.NORTH);
        p.add(save,BorderLayout.SOUTH);
        add(p);
    }

    /**
       This method is called by the subject every time the state of the subject
     */
    public void update()
    {
        if(needsToUpdate)
        {
            t.getDocument().removeDocumentListener(docListener);
            System.out.println("ocp.getText = " + ocp.getText());
            t.setText(ocp.getText());
            t.getDocument().addDocumentListener(docListener);
        }
        needsToUpdate = true;

    }
}
