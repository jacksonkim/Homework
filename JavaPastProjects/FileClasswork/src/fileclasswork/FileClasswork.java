/* CIST 2371 - 20790 - Kimberly Jackson - SID: 0332
 */
package fileclasswork;

import java.io.File;
import java.util.Scanner;

public class FileClasswork 
{

    public static void main(String[] args) 
    {
        File infile;
        String fileInfo;
        Scanner input = new Scanner(System.in);
        
        System.out.println("Please input the name or directory of the file that"
                + "you would like to open.");
        System.out.print("File name or directory: ");
        fileInfo = input.next();
        
        infile = new File(fileInfo);
        if (infile.exists())
        {
            if (infile.isFile())
            {
                System.out.printf("The file's name is: %s\n", infile.getName());
                System.out.printf("The file's lase modified date is: %d\n", 
                        infile.lastModified());
                System.out.printf("The file's size at current is: %d\n", 
                        infile.getTotalSpace());              
            }
            else if (infile.isDirectory())
            {
                System.out.printf("This directory has %d files.\n", infile.list().length);
            }
        }
        else
        {
            System.out.println("Looks like whatever you typed in was incorrect.");
        }
    
    }
}
