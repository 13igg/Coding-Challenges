import java.net.*;  //the package for networking code
import java.io.*;   //the package for input/output, similar to iostream

import javax.swing.JOptionPane;

public class Client
{
    public static void main(String args[]) throws Exception
    {
        //store the address in a string
        //this is equivalent to a cin>>IPToConnectTo in C++
        String IPToConnectTo = JOptionPane.showInputDialog("Welcome to the TCP Client! \nEnter the IP address of the machine to connect to: ");

        //store the port number in a string
        String PortToConnectTo = JOptionPane.showInputDialog(("Enter the port number of the application to connect to: "));

        //converts a string to an int
        int port = Integer.parseInt(PortToConnectTo);

        //now that we have the IP address and port number, lets
        //create a socket connection with a server on another machine
        Socket clientSocket = new Socket(IPToConnectTo, port);

        //in order to write to the socket we have to
        //create a stream of characters in and out

        //we can use outToServer to write to the socket
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

        //we can use inFromServer to read in to the socket
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        //prompt for a request
        String request = JOptionPane.showInputDialog("Enter in a request to the server: ");

        //send a request to the server- must end with a newline but the newline will not be sent
        outToServer.writeBytes(request + "\n");

        //wait for a response from the server- block until there is a response
        String responseFromServer = inFromServer.readLine();

        System.out.println("Server response: " + responseFromServer);

        //close the socket after we are done with it
        clientSocket.close();
    }
}