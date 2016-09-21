/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package day2;

/**
 *
 * @author Kim
 */

import java.util.Scanner;

public class Day2 //global level - variables shouldn't exist here, per usual
{

    /**
     * @param args the command line arguments
     */
    int boogers;
    
    public static void main(String[] args) 
    {
      Greeting greet = new Greeting();
      String boogers = greet.PrintGreeting();
      System.out.println(boogers);
      System.out.println();
      Scanner input = new Scanner(System.in);
      int number1,
              number2;
      System.out.print("Please input your first number that you would like to average with another: ");
      number1 = input.nextInt();
      
      System.out.println();
      System.out.print("And your second number: ");
      number2 = input.nextInt();
      
      PrintAvg(number1, number2);
    }
    
    public static int Average (int num1, int num2)
    {
        return (num1+num2)/2;
    }
    
    public static void PrintAvg(int num1a, int num2a)
    {
        System.out.printf("%d", Average(num1a, num2a));
        System.out.println();
    }
}

