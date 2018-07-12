/**
 * User: Matt
 * Date: 4/19/13
 * Time: 9:25 PM
 * Project Name Observer
 */

import java.net.*;  //the package for networking code
import java.io.*;   //the package for input/output, similar to iostream

public class ObserverClientProxy  implements Runnable
{
    Observer GUI;
    ServerSocket welcomeSocket;
    Socket mySocket;
    String text;

    public ObserverClientProxy(Observer GUI) throws Exception
    {
        this.GUI = GUI;
        //create the server socket passing the port number to listen for. The TCPServer
        //will create this socket and sit and listen for requests on the port
        welcomeSocket = new ServerSocket(55553);
    }
    public String getText()
    {
         return text;
    }

    @Override
    public void run()
    {
        try
        {
            while(true)
            {
                //block the server until a connection is created
                mySocket = welcomeSocket.accept();
                System.out.println("Subject Server has connected");

                //we can use inFromClient to read in to the socket
                BufferedReader inFromClient = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));
                //read the request from the client block until a request is made
                String requestFromClient = inFromClient.readLine();

                System.out.println("Request: " + requestFromClient);
                //split the request on the :
                String s[] = requestFromClient.split(":");
                if(s.length == 2 && s[0].equalsIgnoreCase("update"))
                {
                     //s[1] is the new text message
                    text = s[1];
                    GUI.update();
                }
                //close the socket
                mySocket.close();
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}