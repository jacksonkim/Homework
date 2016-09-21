// Random Access Account Record
// this class extends the AccountRecord class
// so it can read and write fixed length records
// to a random access file for transaction processing

import java.io.*;

public class RandomAccessAccountRecord extends AccountRecord
{
	// the length of a name
	private static final int NAME_LENGTH = 20;
	// the size of the record is determined by counting bytes
	// 4 bytes per integer
	// 8 bytes per double
	// 2 bytes per character in strings
	public static final int SIZE = 4 + 8 + NAME_LENGTH * 2 + NAME_LENGTH * 2;

	public RandomAccessAccountRecord()
	{
		this(0,"","",0.0);
	}

	public RandomAccessAccountRecord(int account, String firstName, String lastName, double balance)
	{
		super(account, firstName, lastName, balance);
	}

	public RandomAccessAccountRecord( AccountRecord data )
	{
		setAccountNumber(data.getAccountNumber());
		setFirstName(data.getFirstName());
		setLastName(data.getLastName());
		setBalance(data.getBalance());
	}

	// read an AccountRecord from RandomAccessFile
	public void read(RandomAccessFile file) throws IOException
	{
		setAccountNumber(file.readInt());
		setFirstName( readName(file) );
		setLastName( readName(file) );
		setBalance( file.readDouble() );
	}

	// utility method to read a fixed length name from file
	private String readName( RandomAccessFile file) throws IOException
	{
		char name[] = new char[NAME_LENGTH], temp;

		for (int count = 0; count < name.length; count++)
		{
			temp = file.readChar();
			name[count] = temp;
		}
		return new String(name).replace('\0',' ');
	}

	// write the AccountRecord to RandomAccessFile
	public void write(RandomAccessFile file) throws IOException
	{
		file.writeInt( getAccountNumber() );
		writeName( file, getFirstName() );
		writeName( file, getLastName() );
		file.writeDouble( getBalance() );
	}

	// utility method to write fixed length name to file
	private void writeName( RandomAccessFile file, String name ) throws IOException
	{
		StringBuffer buffer = null;

		if (name != null )
			buffer = new StringBuffer(name);
		else
			buffer = new StringBuffer(NAME_LENGTH);

		buffer.setLength(NAME_LENGTH);
		file.writeChars( buffer.toString() );
	}

}




