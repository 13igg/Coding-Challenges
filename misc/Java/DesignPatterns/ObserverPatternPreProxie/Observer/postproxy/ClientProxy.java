import java.net.*;  //the package for networking code
import java.io.*;   //the package for input/output, similar to iostream
import java.util.*; //utility package to get the current date and time

public class ClientProxy 
{	
	public static void main(String[] args) throws Exception
	{
		//this is the server that will fo the math
		ServerInterface server = new Server();

	    //create the server socket passing the port number to listen for. The TCPServer
        //will create this socket and sit and listen for requests on the port
        ServerSocket welcomeSocket = new ServerSocket(55555);

        //usually a server runs 24/7
        while(true)
        {
            //block the server until a connection is created
            //then create a new socket to transfer data
            Socket mySocket = welcomeSocket.accept();

            //we can use outToClient to write to the socket
            DataOutputStream outToClient = new DataOutputStream(mySocket.getOutputStream());

            //we can use inFromClient to read in to the socket
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));

            //read the request from the client
            //block until a request is made
            String requestFromClient = inFromClient.readLine();

            System.out.println("Request: " + requestFromClient);
            
            //split the request on the :
            String s[] = requestFromClient.split(":");

            //enforce a protocol, make sure there are three params and the first is
            //the command add
            if(s.length == 3 && s[0].equalsIgnoreCase("add"))
            {
            	//get the parameters and convert them from strings to ints
            	int n1 = Integer.parseInt(s[1]);
            	int n2 = Integer.parseInt(s[2]);
            	
            	//ask the real server to do the math
            	int result = server.add(n1, n2);

            	//send the result back to the client
                outToClient.writeBytes(Integer.toString(result) +  "\n");
            }
            else
            {
                outToClient.writeBytes("Invalid Request!\n");
            }

            //close the socket
            mySocket.close();
        }	
	}
}
