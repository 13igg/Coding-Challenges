/**
 * User: Matt
 * Date: 4/19/13
 * Time: 9:19 PM
 * Project Name ObserverServer
 */
/**
 * User: Matt
 * Date: 4/18/13
 * Time: 7:31 PM
 * Project Name Observer
 */
import java.net.*;  //the package for networking code
import java.io.*;   //the package for input/output, similar to iostream

public class SubjectServerProxy implements ServerInterface, Observer
{
    private Socket clientSocket;
    private DataOutputStream outToServer;
    private String text;

    private String IPToConnectTo;
    int port;
                       //send requests to the client
    public SubjectServerProxy(String IPToConnectTo, int port) throws  Exception
    {
        text = "";
        this.IPToConnectTo = IPToConnectTo;
        this.port = port;
    }
    @Override
    public void update(String message) throws Exception {
        text = message;
        createSocket();
        //update the text object text
    }

    @Override
    public void createSocket() throws Exception {
        //opens the socket
        System.out.println("sending -> " + text+" to port -> " + port);

        clientSocket = new Socket(IPToConnectTo, port);
        //sends the message out to the server
        outToServer = new DataOutputStream(clientSocket.getOutputStream());
        outToServer.writeBytes("update:" + text);
        //close the socket
        clientSocket.close();
    }
}

