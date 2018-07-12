import javax.swing.*;

public class Main {

    public static void main(String[] args) {
        TextObject to = new TextObject();

        GUI jft = new GUI(to);
        GUI jft2 = new GUI(to);
        GUI jft3 = new GUI(to);
        GUI jft4 = new GUI(to);

        //set the dimensions of the window
        jft.setSize(200, 200);
        jft2.setSize(200, 200);
        jft3.setSize(200, 200);
        jft4.setSize(200, 200);

        //stagger the locations of the JFrames
        jft.setLocation(100, 100);
        jft2.setLocation(300, 300);
        jft3.setLocation(500, 500);
        jft4.setLocation(700, 700);

        //close when the 'x' is clicked
        jft.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jft2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jft3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jft4.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //make them visible
        jft.setVisible(true);
        jft2.setVisible(true);
        jft3.setVisible(true);
        jft4.setVisible(true);
    }
}
