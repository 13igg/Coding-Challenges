
import java.net.*;  //the package for networking code
import java.io.*;   //the package for input/output, similar to iostream
import java.util.*; //utility package to get the current date and time

public class Server
{
    public static void main(String args[]) throws Exception
    {
        //can call a function tp print info about this server
        printIPInfo();

        //create the server socket passing the port number to listen for. The TCPServer
        //will create this socket and sit and listen for requests on the port
        ServerSocket welcomeSocket = new ServerSocket(55555);

        //usually a server runs 24/7
        while(true)
        {
            //block the server until a connection is created
            //then create a new socket to transfer data
            Socket mySocket = welcomeSocket.accept();

            //get the IP address of the client by getting the InetAddress object
            //associated with the other end of this socket and then
            //calling the method that returns the IP address as a string
            String clientIP = mySocket.getInetAddress().getHostAddress();

            //print out the results
            System.out.println("The IP address of the client making a request is: " + clientIP);

            //we can use outToClient to write to the socket
            DataOutputStream outToClient = new DataOutputStream(mySocket.getOutputStream());

            //we can use inFromClient to read in to the socket
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));

            //read the request from the client
            //block until a request is made
            String requestFromClient = inFromClient.readLine();

            //print out the request to the screen
            System.out.println("Client Request: " + requestFromClient);

            //enforce a protocol
            if(requestFromClient.equalsIgnoreCase("date"))
            {
                //the request is for the date, send the current date back
                //to the client using the socket, remember to append a newline
                outToClient.writeBytes((new Date()).toString() + "\n");
            }
            else if(requestFromClient.equalsIgnoreCase("ms"))
            {
                //the request is for the number of milliseconds
                //since Jan 1, 1970. Send back that number.

                //convert that number to a string
                String numMs = String.valueOf( (new Date()).getTime() );

                //write that string value to the socket
                outToClient.writeBytes(numMs + "\n");
            }
            else
            {
                outToClient.writeBytes("Invalid Request!\n");
            }

            //close the socket
            mySocket.close();
        }
    }

    public static void printIPInfo() throws Exception
    {
        System.out.println("Welcome to the TCP Server!");

        //find out the IP address and host name of this machine
        //for more info go to http://java.sun.com/j2se/1.4.2/docs/api/index.html
        //and search for the class called InetAddress
        String myIP = InetAddress.getLocalHost().getHostAddress();
        System.out.println("My IP address is " + myIP);

        String myHostName = InetAddress.getLocalHost().getHostName();
        System.out.println("My host name is " + myHostName);
    }
}
