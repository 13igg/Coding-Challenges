/**
 * User: Matt
 * Date: 4/18/13
 * Time: 7:31 PM
 * Project Name Observer
 */
import java.net.*;  //the package for networking code
import java.io.*;   //the package for input/output, similar to iostream

public class ObserverServerProxy
{
    private Socket clientSocket;
    String IPToConnectTo;
    int port;
    public ObserverServerProxy(String IPToConnectTo, int port)
    {
        //now that we have the IP address and port number, lets
        //create a socket connection with a server on another machine
        this.IPToConnectTo = IPToConnectTo;
        this.port = port;
        try
        {
            clientSocket = new Socket(IPToConnectTo, port);
            //we can use outToServer to write to the socket
            DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
            String myIP = InetAddress.getLocalHost().getHostAddress();

            //send a request to the server- must end with a newline but the newline will not be sent
            outToServer.writeBytes("Attach:" + myIP + ":" + "55553" +"\n");

            clientSocket.close();
        }
        catch (Exception e)
        {
            System.out.println("Error connecting to the sever");
        }

    }

    public void sendToAll(String message) throws Exception
    {
        clientSocket = new Socket(IPToConnectTo, port);
        //we can use outToServer to write to the socket
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        //send a request to the server- must end with a newline but the newline will not be sent
        outToServer.writeBytes("sendToAll:"+message+"\n");
        //close the socket after we are done with it
        clientSocket.close();

    }
}

