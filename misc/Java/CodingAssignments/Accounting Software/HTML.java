import javax.swing.JOptionPane;
import java.util.*;
import java.io.BufferedWriter;
import java.io.File;
import java.io.*;
public class HTML
{
	private String htmlHeadder;
	private String htmlText;
	private String htmlCloser;
	public HTML(ArrayList<Accounts> accountList)
	{
		htmlHeadder = "<html><head><title>Accounts</title></head><body>";
		htmlCloser = "</body></html>";
		htmlText = htmlHeadder;
		for(int i = 0; i < accountList.size()-1; i ++)
			for(int j = 1; j < accountList.size(); j ++)
				if(accountList.get(i).getBalance() < accountList.get(j).getBalance())
					Collections.swap(accountList,i,j);
					
		for(int i = 0; i < accountList.size(); i ++)
			htmlText += (accountList.get(i) + "<br></br>");
		htmlText += htmlCloser;
		writeToFile(1,htmlText);
	}

	public void writeToFile(int fileNum, String pT)
	{
		try 
		{
			String num = Integer.toString(fileNum);
			String link = "D:\\Sophomore 2nd Semester\\OOP\\JavaFiles\\Accounting Software\\Accounting Software1.html";
			File file = new File(link + fileNum + ".HTML");
		// if file doesnt exists, then create it
			if (!file.exists())
				file.createNewFile();
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			
			bw.write(pT);
			bw.close(); 
			System.out.println("File written to .HTML file");
		} 
		catch (IOException e){
			e.printStackTrace();}
	}
}