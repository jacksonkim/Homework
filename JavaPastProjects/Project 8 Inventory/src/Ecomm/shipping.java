//  SHIPPING.JAVA by David Chesser

package ecomm;
public class shipping {
    static double cost;
    
    static void setCost(String state)	{
	//  Tests for GA, FL, AL, SC, NC, or TN
	String[] southest = {"GA", "FL", "AL", "SC", "NC", "TN"};
	
	for (int i = 0; i < southest.length; i++)	{
	    if (state.equals(southest[i]))	{   cost = 10.00;}
	    else				{   cost = 15.00;}
	//  setCost is to compare the state argument to the southeastern state array (southest).
	//  $5 discount if shipping to the southeastern state array!
}}}