import java.net.*;  //the package for networking code
import java.io.*;   //the package for input/output, similar to iostream

public class ServerProxy implements ServerInterface 
{
    public int add(int n1, int n2) throws Exception
    {
        //now that we have the IP address and port number, lets
        //create a socket connection with a server on another machine
        Socket clientSocket = new Socket("127.0.0.1", 55555);

        //in order to write to the socket we have to
        //create a stream of characters in and out

        //we can use outToServer to write to the socket
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

        //we can use inFromServer to read in to the socket
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        //send a request to the server- must end with a newline but the newline will not be sent
        outToServer.writeBytes("add:10:20\n");

        //wait for a response from the server- block until there is a response
        String responseFromServer = inFromServer.readLine();

        //close the socket after we are done with it
        clientSocket.close();

        return Integer.parseInt(responseFromServer);
    }
}
