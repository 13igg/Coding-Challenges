import java.net.ServerSocket;

/**
 * User: Matt
 * Date: 4/19/13
 * Time: 9:51 PM
 * Project Name ObserverServer
 */
public class main {
    public static void main(String[] args) throws Exception {

        //ServerInterface server = new Server();//creates a new TextObject
        ServerSocket welcomeSocket = new ServerSocket(55555);
        TextObject to = new TextObject();

        SubjectClientProxy clientProxy = new SubjectClientProxy(to,welcomeSocket);
        Thread firstThread = new Thread(clientProxy);
        firstThread.start();
    }
}
