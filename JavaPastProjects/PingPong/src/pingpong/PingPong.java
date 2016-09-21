/* CIST 2373 - 20411 - Kimberly Jackson - SID: 0332
 * Week 2, Multithreading, Ping Pong - 8/26/13
 * 
 * Description: Implements a runnable interface that will write ping or pong
 * in a console window. Ping or Pong must be printed at least 10 times before
 * termination. Printing ping or pong must be run in separate threads.
 * 
 */
package pingpong;

import java.util.*;

public class PingPong implements Runnable
{
    private int threadNum;
    
    public PingPong(int tn)
    {
        threadNum = tn;
    }
    
    public void PingThread()
    {
        System.out.println("Ping");
    }
    
    public void PongThread()
    {
        System.out.println("\tPong");
    }
    
    public void run()
    {
        for(int counter=0; counter < 10; counter++)
        {
            if(threadNum == 0)
                PingThread();
            else
                PongThread(); 
        }
       
    }
}
