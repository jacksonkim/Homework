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

public class RecRoom 
{

    public static void main(String[] args) 
    {
        Thread pingpong[] = new Thread[2];
        
        for (int count=0; count < pingpong.length; count++)
        {
            pingpong[count] = new Thread(new PingPong(count));
            pingpong[count].start();
        }
        
    }
}
