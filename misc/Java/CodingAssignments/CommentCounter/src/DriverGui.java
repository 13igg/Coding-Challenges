import javax.swing.*;
import javax.swing.event.DocumentListener;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

public class DriverGui  extends JFrame implements ActionListener {
    private JButton selectFile;
    private JButton confirm;
    private JPanel buttons;

    private JLabel filePath;
    private JPanel label;

    private JFileChooser fileChooser;
    private DocumentListener docListener;

    Reader r;

    public DriverGui()
    {
        super("Code Counter");
        r = new Reader();
        //GUI setup
        buttons = new JPanel();
        buttons.setLayout(new GridLayout(1, 2));

        label = new JPanel();
        label.setLayout(new FlowLayout());

        selectFile = new JButton("Select File");
        selectFile.addActionListener(this);
        buttons.add(selectFile);

        confirm = new JButton("Confirm");
        confirm.addActionListener(this);
        buttons.add(confirm);

        filePath = new JLabel("");
        label.add(filePath);

        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(label, BorderLayout.NORTH);
        getContentPane().add(buttons, BorderLayout.SOUTH);
    }

    public static void main(String[] args) {
        System.out.println("code testing");
        //Read in a file piece by piece
        System.out.println("Select the file you wish to count");

        DriverGui m = new DriverGui();
        m.setSize(350, 100);
        m.setLocation(100, 300);
        m.setVisible(true);
        m.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    public void actionPerformed(ActionEvent e)
    {
        if(e.getActionCommand().equals("Select File"))
        {
            //ask the state machine to handle the event
            try {UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());}catch (Exception ef){}

            fileChooser = new JFileChooser();
            FileNameExtensionFilter filter = new FileNameExtensionFilter("JAVA File","JAVA"); //bmp is the only file tipe
            fileChooser.setFileFilter(filter);//sets above
            fileChooser.setAcceptAllFileFilterUsed(false);
            File desktop = new File("c:\\Users\\Matt\\Desktop\\");//sets desktop as default
            fileChooser.setCurrentDirectory(desktop);//sets desktop as default
            int retVal = fileChooser.showSaveDialog(fileChooser);
            if(retVal == JFileChooser.APPROVE_OPTION)//checks to see if it was run or closed out
                filePath.setText(fileChooser.getSelectedFile().toString());
        }
        else
        {
            //Start reading in the seclected file. NEW STATE
            try {
                r.openFile(fileChooser.getSelectedFile());
            } catch (Exception e1) {
                e1.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            }
        }


    }
}
