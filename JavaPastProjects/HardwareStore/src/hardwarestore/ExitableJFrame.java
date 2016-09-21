package hardwarestore;

/*
	ExitableJFram.java
	Extends JFrame so it exits on close
	Also relocates JFrame location to 1/3 from left top of screen
*/
import javax.swing.JFrame;
import java.awt.GraphicsConfiguration;
import java.awt.Toolkit;
import java.awt.Dimension;


public class ExitableJFrame extends JFrame
{
    public ExitableJFrame()
    {
        super();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLocationThird();
    }

    public ExitableJFrame(GraphicsConfiguration gc)
    {
        super(gc);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLocationThird();
    }

    public ExitableJFrame(String title)
    {
        super(title);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLocationThird();
    }

    public ExitableJFrame(String title,GraphicsConfiguration gc)
    {
        super(title, gc);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLocationThird();
    }

    public void setLocationThird()
    {
        Toolkit tk = getToolkit();
        Dimension wndSize = tk.getScreenSize();
        setLocation((wndSize.width)/3,(wndSize.height)/3);
    }
}