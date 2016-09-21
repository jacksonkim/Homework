package hardwarestore;

/*
	JScrollingTextArea.java

	A JTextArea that can be scrolled

*/
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class JScrollingTextArea extends JScrollPane
{
    private JTextArea textArea;

    public JScrollingTextArea(int rows, int columns)
    {
        super();
        textArea = new JTextArea(rows,columns);
        setViewportView(textArea);
    }

    public void setEditable( boolean b)
    {
        textArea.setEditable(b);
    }

    public void setText(String s)
    {
        textArea.setText(s);
    }

    public void append(String s)
    {
        textArea.append(s);
    }

}