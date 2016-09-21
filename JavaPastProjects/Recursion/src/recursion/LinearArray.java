/* CIST 2371 - 20790 - Kimberly Jackson - SID 0332
 * Week 14?, Recursion App - 12/6/12
 * 
 * Description: Create a recursive method - recursiveLinearSearch
 * to perform a linear search of an array. The method should receive
 * the search key and the starting index as arguments. If the 
 * search key is found, return the index in the array. If the key is
 * NOT found, return -1. Each call should only check one index in the array.
 *(Side note, this sounds like it would be dumb in practice? At first glance.)
 * 
 */
package recursion;

import java.util.Random;
import java.util.Arrays;

public class LinearArray 
{
    private int[] data;
    private static final Random generator = new Random();
    
    public LinearArray(int size)
    {
        data = new int[size];
        
        for(int i=0; i < size; i++)
        {
            data[i] = 10+generator.nextInt(90);
        }
    }
    
    public int linearsearch(int searchKey)
    {
        for (int index=0; index<data.length; index++)
        {
            if (data[index]==searchKey)
                return index;
        }
        return -1;
    }
    
    public String toString()
    {
        return Arrays.toString(data);
    }
    
    public int recursiveLinearSearch(int searchKey, int index)
    {
        if (index < data.length)
        {
            if (data[index]==searchKey)
                return index;
            else if (data[index]!=searchKey)
                return recursiveLinearSearch(searchKey, index+1);
            else
                return -1;
        }
        return -1;
    }
}
