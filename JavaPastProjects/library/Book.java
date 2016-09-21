class Book 
{
	private String author1, author2, author3, author4;
	private String ISBN;
	private String publisher;
	private String title;
	private String copyrightDate;
	private double price;
	private static int nBooks = 0;
	private boolean checkedOut = false;
	
	//empty constructor
	Book()
	{
		title = "";
		author1 = "";
		author2 = "";
		author3 = "";
		author4 = "";
		ISBN = "";
		publisher = "";		
		copyrightDate = "";
		price = 0.0;
		nBooks++;
	}
	
	//constructor 1
	Book(String t, String auth1, String is, String pub, String copyd, double pr)
	{
		title = t;
		author1 = auth1;
		author2 = "";
		author3 = "";
		author4 = "";
		ISBN = is;
		publisher = pub;		
		copyrightDate = copyd;
		price = pr;
		nBooks++;
	}
	
	//constructor 1 author/title/isbn/price information
	Book(String t, String auth1, String is, double pr)
	{
		title = t;
		author1 = auth1;
		author2 = "";
		author3 = "";
		author4 = "";
		ISBN = is;
		publisher = "";		
		copyrightDate = "";
		price = pr;
		nBooks++;
	}
	
	//constructor 2 authors
	Book(String t, String auth1, String auth2, String is, String pub, String copyd, double pr)
	{
		title = t;
		author1 = auth1;
		author2 = auth2;
		author3 = "";
		author4 = "";
		ISBN = is;
		publisher = pub;		
		copyrightDate = copyd;
		price = pr;
		nBooks++;
	}
	
	//constructor 3 authors
	Book(String t, String auth1, String auth2, String auth3, String is, String pub, String copyd, double pr)
	{
		title = t;
		author1 = auth1;
		author2 = auth2;
		author3 = auth3;
		author4 = "";
		ISBN = is;
		publisher = pub;		
		copyrightDate = copyd;
		price = pr;
		nBooks++;
	}
	
	//constructor 4 authors
	Book(String t, String auth1, String auth2, String auth3, String auth4, String is, String pub, String copyd, double pr)
	{
		title = t;
		author1 = auth1;
		author2 = auth2;
		author3 = auth3;
		author4 = auth4;
		ISBN = is;
		publisher = pub;		
		copyrightDate = copyd;
		price = pr;
		nBooks++;
	}
	
	//copy constructor
	Book(Book bk)
	{
		title = bk.getTitle();
		author1 = bk.getAuthor1();
		author2 = bk.getAuthor2();
		author3 = bk.getAuthor3();
		author4 = bk.getAuthor4();
		ISBN = bk.getISBN();
		publisher = bk.getPub();		
		copyrightDate = bk.getCopyDate();
		price = bk.getPrice();
		nBooks++;
	}
	
	//get methods
	public String getTitle()
	{
		return title;
	}
	
	public String getAuthor1()
	{
		return author1;
	}
	
	public String getAuthor2()
	{
		return author2;
	}
	
	public String getAuthor3()
	{
		return author3;
	}
	
	public String getAuthor4()
	{
		return author4;
	}
	
	public String getISBN()
	{
		return ISBN;
	}
	
	public String getPub()
	{
		return publisher;
	}
	
	public String getCopyDate()
	{
		return copyrightDate;
	}
	
	public double getPrice()
	{
		return price;
	}
	
	public static int getBooks()
	{
		return nBooks;
	}
	
	public boolean getCheckedOut()
	{
		return checkedOut;
	}
	
	//set methods
	public void setTitle(String t)
	{
		title = t;
	}
	
	public void setAuthor1(String auth1)
	{
		author1 = auth1;
	}
	
	public void setAuthor2(String auth2)
	{
		author2 = auth2;
	}
	
	public void setAuthor3(String auth3)
	{
		author3 = auth3;
	}
	
	public void setAuthor4(String auth4)
	{
		author4 = auth4;
	}
	
	public void setISBN(String is)
	{
		ISBN = is;
	}
	
	public void setPub(String pub)
	{
		publisher = pub;
	}
	
	public void setCopyDate(String copyd)
	{
		copyrightDate = copyd;
	}
	
	public void setPrice(double pr)
	{
		price = pr;
	}
	
	public void setCheckedOut(boolean co)
	{
		checkedOut = co;
	}
	
	//overrides
	/*@Override
	public boolean equals(Object obj)
	{
		boolean retVal = false;
		Book bk = (Book)obj;
		
		if(bk.getISBN().compareToIgnoreCase(ISBN) == 0)
		{
			if(bk.getAuthor1().compareToIgnoreCase(author1) == 0)
			{
				if(bk.getTitle().compareToIgnoreCase(title) == 0)
				{
					retVal = true;
				}
			}
		}//end ifs
		
		return retVal;
	}
	
	@Override
	public int hashCode()
	{
		
	}*/
	
	//misc
	public void displayAllInfo()
	{
		System.out.print("Title: " + title + "\n");
		System.out.print("Author: " + author1 + "\n");
		if(author2.isEmpty() == false)
		{
			System.out.print("Author2 : " + author2 + "\n");
			if(author3.isEmpty() == false)
			{
				System.out.print("Author 3: " + author3 + "\n");
				if(author4.isEmpty() == false)
				{
					System.out.print("Author 4: " + author4 + "\n");
				}//end author4
			}//end author3
		}//end author1
		System.out.print("ISBN: " + ISBN + "\n");
		System.out.print("Publisher: " + publisher + "\n");
		System.out.print("Copyright Date: " + copyrightDate + "\n");
		System.out.print("Price: $" + price + "\n");
		if(checkedOut == true)
		{
			System.out.print("Checked Out: Yes\n");
		}
		else
		{
			System.out.print("Checked Out: No\n");
		}
	}
	
	public void displayShortInfo()
	{
		System.out.print("Title: " + title + "\n");
		System.out.print("Author: " + author1 + "\n");
		System.out.print("ISBN: " + ISBN + "\n");
		System.out.print("Price: $" + price + "\n");
		if(checkedOut == true)
		{
			System.out.print("Checked Out: Yes\n");
		}
		else
		{
			System.out.print("Checked Out: No\n");
		}
	}
	
	public void setAll()
	{
		title = "";
		author1 = "";
		author2 = "";
		author3 = "";
		author4 = "";
		ISBN = "";
		publisher = "";		
		copyrightDate = "";
		price = 0.0;
	}
}