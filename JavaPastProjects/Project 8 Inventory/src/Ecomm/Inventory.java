/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Ecomm;

/**
 *
 * @author Kim
 */
public class Inventory {
    
    private int NUM_PRODUCTS = 5;
    private String[] products;
    private double[] product_prices;
    
    Inventory()
    {
        products = new String[NUM_PRODUCTS];
        product_prices = new double[NUM_PRODUCTS];
        
        for (int count = 0; count < NUM_PRODUCTS; count++)
        {
            switch (count)
            {
                case 0:
                    products[count] = "Kindle";
                    product_prices[count] = 199.00;
                    break;
                case 1:
                    products[count] = "SonyPlasma";
                    product_prices[count] = 800.00;
                    break;
                case 2:
                    products[count] = "IPhone5";
                    product_prices[count] = 400.00;
                    break;
                case 3:
                    products[count] = "Xbox360";
                    product_prices[count] = 350.00;
                    break;
                case 4:
                    products[count] = "HelloKittyDoll";
                    product_prices[count] = 24.00;
                    break;
            }
        }
       
    }
    
    Inventory (String[] p, double[] pp)
    {
        products = new String[NUM_PRODUCTS];
        product_prices = new double[NUM_PRODUCTS];
        
        products = p;
        product_prices = pp;
    }
    
    public void ListAvailableProducts()
    {
        System.out.printf("%s%20s\n", "Product", "Price");
        
        for (int count = 0; count < NUM_PRODUCTS; count++)
        {            
            System.out.print(count+1);
            System.out.printf(". %s", products[count]);
            
            System.out.printf("     %.2f", product_prices[count]);
            System.out.println();
        } //end for
    } //end listavailable products
    
    public boolean SetProductPrice(String p, double pp)
    {             
        boolean pricetest = false;
        for (int count = 0; count < NUM_PRODUCTS; count++)
        {
          if (p.toLowerCase() == products[count].toLowerCase())
          {
              product_prices[count] = pp;
              pricetest = true;
          }
          else
          {
              pricetest = false;
          } //end if-else
        } //end for
        
        return pricetest;
    } //end setproductprice
    
    public double GetProductPrice(String p)
    {
        double price = 0.00;
        for (int count = 0; count < NUM_PRODUCTS; count++)
        {
          if (p.toLowerCase() == products[count].toLowerCase())
          {
              price = product_prices[count];
          } //end if
        } //end for
        return price;
    }
}
