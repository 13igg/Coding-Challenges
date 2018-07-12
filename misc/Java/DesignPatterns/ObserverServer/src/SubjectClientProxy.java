import java.net.*;  //the package for networking code
import java.io.*;   //the package for input/output, similar to iostream

public class SubjectClientProxy implements Runnable
{
    ServerSocket welcomeSocket;
    Socket mySocket;
    TextObject to;

    //ServerInterface server = new Server();

   public SubjectClientProxy(TextObject to, ServerSocket ss)
   {
       this.to = to;
       welcomeSocket = ss;
   }

    @Override
    public void run() {
        //usually a server runs 24/7
            try
            {
                while(true)
                {
                    //block the server until a connection is created
                    mySocket = welcomeSocket.accept();

                    System.out.println("New ObserverServer has connected");

                    //we can use inFromClient to read in to the socket
                    BufferedReader inFromClient = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));

                    //read the request from the client block until a request is made
                    String requestFromClient = inFromClient.readLine();

                    System.out.println("Request: " + requestFromClient);
                    //split the request on the :
                    String s[] = requestFromClient.split(":");

                    //enforce a protocol, make sure there are three params and the first is
                    //split attach message
                    if(s.length == 3 && s[0].equalsIgnoreCase("Attach"))
                    {
                        //create the subject server proxy
                        SubjectServerProxy ssp = new SubjectServerProxy(s[1],Integer.parseInt(s[2].toString()));

                        //attach the subject server proxy;
                        to.attach(ssp);
                    }

                    //split sendToAll : message
                    else  if(s.length == 2 && s[0].equalsIgnoreCase("sendToAll"))
                    {
                        //received a changed message
                        //use this changed message and send it to every Subject Server Proxy
                        //all these subject server proxies are observers therefore they all
                        //have the update command. FUCK EYAH
                        to.setText(s[1]);
                        //to.notifyAllObservers();
                    }
                    //close the socket
                    mySocket.close();
                }
            } catch (IOException e)
            {
                e.printStackTrace();
            } catch (Exception e) {
                e.printStackTrace(); }

        }


}

