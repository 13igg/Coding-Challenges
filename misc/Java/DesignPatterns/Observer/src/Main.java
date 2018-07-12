import javax.swing.*;

public class Main {

    public static void main(String[] args) throws  Exception{


        GUI jft = new GUI();

        //set the dimensions of the window
        jft.setSize(200, 240);

        //stagger the locations of the JFrames
        jft.setLocation(50, 100);

        //close when the 'x' is clicked
        jft.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //make them visible
        jft.setVisible(true);


    }
}
