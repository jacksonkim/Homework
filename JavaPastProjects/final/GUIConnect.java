import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.sql.*;

public class GUIConnect implements ActionListener
{
	private JFrame fr1;
	private JFrame fr2;
	
	private JButton fr1_bu1;
	private JButton fr1_bu2;
	
	private JButton fr2_bu1;
	private JButton fr2_bu2;
	
	private JTextField fr1_tf1;
	private JTextField fr1_tf2;
	private JTextField fr1_tf3;

	private JTextField fr2_tf1;
	private JTextField fr2_tf2;
	
	private JTextArea fr2_ta;
	
	
	public GUIConnect()
	{
		createFrame1("DB Connect", 280, 210);
		createFrame2("Add Users", 290, 400);
	}
	
	public void createFrame1(String windowTitle, int width, int height)
	{		
		fr1 = new JFrame();		
		fr1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fr1.setLocation(100, 100);
		fr1.setLayout(null);
		
		JLabel lb1 = new JLabel("Username:");
		lb1.setBounds(10, 10, 120, 30);
		fr1.add(lb1);
		
		JLabel lb2 = new JLabel("Password:");
		lb2.setBounds(120, 10, 100, 30);
		fr1.add(lb2);
		
		fr1_bu1 = new JButton("Login");
		fr1_bu1.setBounds(25, 95, 80, 30);
		fr1_bu1.addActionListener(this);
		fr1.add(fr1_bu1);
		
		fr1_bu2 = new JButton("Cancel");
		fr1_bu2.setBounds(120, 95, 80, 30);
		fr1_bu2.addActionListener(this);
		fr1.add(fr1_bu2);
	
		fr1_tf1 = new JTextField();
		fr1_tf1.setBounds(10, 45, 110, 30);
		fr1.add(fr1_tf1);
		
		fr1_tf2 = new JTextField();
		fr1_tf2.setBounds(130, 45, 110, 30);
		fr1.add(fr1_tf2);
		
		fr1_tf3 = new JTextField();
		fr1_tf3.setBounds(40, 135, 110, 30);
		fr1.add(fr1_tf3);
		
		fr1.setSize(width, height);
		fr1.setResizable(false);
		fr1.setVisible(true);
	}
	
	public void createFrame2(String windowTitle, int width, int height)
	{		
		fr2 = new JFrame();		
		fr2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fr2.setLocation(100, 100);
		fr2.setLayout(null);
		
		JLabel lb1 = new JLabel("Username to add:");
		lb1.setBounds(10, 10, 120, 30);
		fr2.add(lb1);
		
		JLabel lb2 = new JLabel("Password to add:");
		lb2.setBounds(120, 10, 100, 30);
		fr2.add(lb2);
		
		fr2_bu1 = new JButton("Add");
		fr2_bu1.setBounds(10, 95, 80, 30);
		fr2_bu1.addActionListener(this);
		fr2.add(fr2_bu1);
		
		fr2_bu2 = new JButton("Refresh");
		fr2_bu2.setBounds(120, 95, 80, 30);
		fr2_bu2.addActionListener(this);
		fr2.add(fr2_bu2);
	
		fr2_tf1 = new JTextField();
		fr2_tf1.setBounds(10, 45, 100, 30);
		fr2.add(fr2_tf1);
		
		fr2_tf2 = new JTextField();
		fr2_tf2.setBounds(120, 45, 100, 30);
		fr2.add(fr2_tf2);
		
		fr2_ta = new JTextArea(5, 20);
		fr2_ta.setEditable(false);
		JScrollPane sp = new JScrollPane(fr2_ta, 
			JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		sp.setBounds(10, 135, 245, 205);
		fr2.add(sp);
		
		fr2.setSize(width, height);
		fr2.setResizable(false);
		fr2.setVisible(false);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource() == fr1_bu1)
		{
			if(DBConnect() == true)
			{
				fr1.setVisible(false);
				fr2.setVisible(true);
			}			
		}
		else if(ae.getSource() == fr1_bu2)
		{
			System.exit(0);
		}
		else if(ae.getSource() == fr2_bu1)
		{
			//add data to database
			DBWrite(fr2_tf1.getText(), fr2_tf2.getText());
			fr2_ta.setText("Name:\tAge:\n");
			DBRead();
		}
		else if(ae.getSource() == fr2_bu2)
		{
			fr2_ta.setText("Name:\tAge:\n");
			DBRead();
		}
	}
	
	public void DBWrite(String uname, String pword)
	{
		Connection con = null;
		Statement sta = null;
		ResultSet res = null;
		
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://localhost:1527/LoginDB;create=false");
			sta = con.createStatement();
			int res1 = sta.executeUpdate("insert into LoginTB values('" + uname + "', '" + pword + "')");
			
			if(res != null)
			{
				res.close();
			}
			if(sta != null)
			{
				sta.close();
			}
			if(con != null)
			{
				con.close();
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public void DBRead()
	{
		Connection con = null;
		Statement sta = null;
		ResultSet res = null;
		
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://localhost:1527/LoginDB;create=false");
			sta = con.createStatement();
			res = sta.executeQuery("select * from LoginTB");
				
			while(res.next())
			{
				fr2_ta.append(res.getString("u_name") + "\t" + res.getString("p_word") + "\n");
			}
			
			if(res != null)
			{
				res.close();
			}
			if(sta != null)
			{
				sta.close();
			}
			if(con != null)
			{
				con.close();
			}
			
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public boolean DBConnect()
	{
		Connection con = null;
		Statement sta = null;
		ResultSet res = null;
		
		boolean login = false;
		
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://localhost:1527/LoginDB;create=false");
			sta = con.createStatement();
			res = sta.executeQuery("select * from LoginTB");
			while(res.next())
			{
				if(res.getString("u_name").compareToIgnoreCase(fr1_tf1.getText()) == 0)
				{
					if(res.getString("p_word").compareToIgnoreCase(fr1_tf2.getText()) == 0)
					{
						login = true;
					}
					else
					{
						fr1_tf3.setText("Invalid Password");
						writeToFile(fr1_tf1.getText(), fr1_tf2.getText());
						login = false;
					}
				}
				else
				{
					login = false;
					fr1_tf3.setText("Invalid Username");
					writeToFile(fr1_tf1.getText(), fr1_tf2.getText());
				}
			}
			if(res != null)
			{
				res.close();
			}
			if(sta != null)
			{
				sta.close();
			}
			if(con != null)
			{
				con.close();
			}

		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
			
		
		return login;
	}
	
	public void writeToFile(String username, String password)
	{
		try
		{
			FileWriter fw = new FileWriter("invalid_attempts.txt", true);
			BufferedWriter bw = new BufferedWriter(fw);
			
			bw.append(username + "," + password + "\n");
			
			bw.close();
			fw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args)
	{
		GUIConnect dbgui = new GUIConnect();
	}

}
