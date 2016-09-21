/*import java.util.*;
import javax.swing.*;
import javax.swing.JComboBox;
import java.awt.*;
import java.awt.Dimension;
import java.awt.event.*;
import java.io.*;
import java.sql.*;

public class GUIConnect implements ActionListener
{
	private JFrame fr1;
	private JFrame fr2;
	private JFrame fr3;
	
	private JButton fr1_bu1;
	private JButton fr1_bu2;
	
	private JButton fr2_bu1;
	private JButton fr2_bu2;
	
	private JTextField fr2_tf1;
	private JTextField fr2_tf2;
	
	
	private JTextArea fr3_ta;
	private JComboBox fr3_cb;
	
	
	public GUIConnect()
	{
		createFrame1("Make a Choice", 290, 130);
		createFrame2("Enter Information", 290, 190);
		createFrame3("Status Report", 290, 400);
	}
	
	public void createFrame1(String windowTitle, int width, int height)
	{
		fr1 = new JFrame(windowTitle);
		fr1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fr1.setLocation(100, 100);
		fr1.setLayout(null);
		
		JLabel lb = new JLabel("Choose wisely");
		lb.setBounds(97, 10, 150, 30);
		fr1.add(lb);
		
		fr1_bu1 = new JButton("Continue");		
		fr1.add(fr1_bu1);
		
		fr1_bu2 = new JButton("Cancel & Exit");		
		fr1.add(fr1_bu2);
		
		fr1_bu1.setBounds(13, 50, 100, 25);
		fr1_bu1.addActionListener(this);
		fr1_bu2.setBounds(123, 50, 130, 25);
		fr1_bu2.addActionListener(this);
		
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
		
		JLabel lb1 = new JLabel("Name:");
		lb1.setBounds(10, 10, 120, 30);
		fr2.add(lb1);
		
		JLabel lb2 = new JLabel("Age:");
		lb2.setBounds(150, 10, 100, 30);
		fr2.add(lb2);
		
		fr2_bu1 = new JButton("Record Data");
		fr2_bu1.setBounds(10, 95, 130, 30);
		fr2_bu1.addActionListener(this);
		fr2.add(fr2_bu1);
		
		fr2_bu2 = new JButton("Cancel");
		fr2_bu2.setBounds(150, 95, 80, 30);
		fr2_bu2.addActionListener(this);
		fr2.add(fr2_bu2);
	
		fr2_tf1 = new JTextField();
		fr2_tf1.setBounds(10, 45, 130, 30);
		fr2.add(fr2_tf1);
		
		fr2_tf2 = new JTextField();
		fr2_tf2.setBounds(150, 45, 80, 30);
		fr2.add(fr2_tf2);
		
		fr2.setSize(width, height);
		fr2.setResizable(false);
		fr2.setVisible(false);
	}
	
	public void createFrame3(String windowTitle, int width, int height)
	{
		fr3 = new JFrame();		
		fr3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fr3.setLocation(100, 100);
		fr3.setLayout(null);
		
		String[] options = {"Select a task", "View Data", "Sort by age", "Start over", "Quit Program"};
		fr3_cb = new JComboBox(options);
		fr3_cb.setBounds(50, 20, 200, 25);
		fr3_cb.setSelectedIndex(0);
		fr3.add(fr3_cb);
		fr3_cb.addActionListener(this);
		
		fr3_ta = new JTextArea(5, 20);
		fr3_ta.setEditable(false);
		JScrollPane sp = new JScrollPane(fr3_ta, 
			JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		sp.setBounds(20, 75, 245, 285);
		fr3.add(sp);
		
		fr3.setSize(width, height);
		fr3.setResizable(false);
		fr3.setVisible(false);
	}
	
	/*public void writeToFile(String fileName, String dataLine)
	{
		try
		{
			FileWriter fw = new FileWriter(fileName);
			BufferedWriter bw = new BufferedWriter(fw);
			
			bw.write(dataLine + "\n");
			
			bw.close();
			fw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource() == fr1_bu1)
		{
			fr1.setVisible(false);
			fr2.setVisible(true);
		}
		else if(ae.getSource() == fr1_bu2)
		{
			System.exit(0);
		}
		else if(ae.getSource() == fr2_bu1)
		{
			//add data to database
			DBWrite(fr2_tf1.getText(), Integer.parseInt(fr2_tf2.getText()));
			fr2.setVisible(false);
			fr3.setVisible(true);
		}
		else if(ae.getSource() == fr2_bu2)
		{
			fr1.setVisible(true);
			fr2.setVisible(false);
		}
		else
		{
			JComboBox tempCB = (JComboBox)ae.getSource();
			if(((String)tempCB.getSelectedItem()).compareToIgnoreCase("View Data") == 0)
			{	
				//retrieve database data
				fr3_ta.setText("Name:\tAge:\n");
				DBRead(false);
			}
			else if(((String)tempCB.getSelectedItem()).compareToIgnoreCase("Sort by age") == 0)
			{
				fr3_ta.setText("Name:\tAge:\n");
				DBRead(true);
			}
			else if(((String)tempCB.getSelectedItem()).compareToIgnoreCase("Start Over") == 0)
			{
				fr1.setVisible(true);
				fr3.setVisible(false);
			}
			else if(((String)tempCB.getSelectedItem()).compareToIgnoreCase("Quit program") == 0)
			{
				System.exit(0);
			}
		}
		
		/*System.out.println("Button is clicked.");
		ta.append("You entered " + tf.getText() +".\n");
		
		writeToFile("data.txt", tf.getText());
	}
	
	public void DBWrite(String e_name, int e_age)
	{
		Connection con = null;
		Statement sta = null;
		ResultSet res = null;
		
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://localhost:1527/EmployeeDB;create=false");
			sta = con.createStatement();
			int res1 = sta.executeUpdate("insert into EmployeeTB values('" + e_name + "', " + e_age + ")");
			
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
	
	public void DBRead(boolean sorted)
	{
		int age;
		String name;
		
		Connection con = null;
		Statement sta = null;
		ResultSet res = null;
		
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://localhost:1527/EmployeeDB;create=false");
			sta = con.createStatement();
			if(sorted == false)
			{
				res = sta.executeQuery("select * from EmployeeTB");
				
				while(res.next())
				{
					fr3_ta.append(res.getString("e_name") + "\t" + res.getInt("e_age") + "\n");
				}
			}
			else if(sorted == true)
			{
				res = sta.executeQuery("select * from EmployeeTB order by e_age");
				
				while(res.next())
				{
					fr3_ta.append(res.getString("e_name") + "\t" + res.getInt("e_age") + "\n");
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
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args)
	{
		GUIConnect goo = new GUIConnect();
	}
}*/