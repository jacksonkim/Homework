/*
	Bank application
	RandomAccessAccountFile class
	implements the account file limited to 100 records

*/
import java.io.*;

public class RandomAccessAccountFile extends RandomAccessFile
{
	// limited to 100 records
	public static final int MAX_RECORDS = 100;

	public RandomAccessAccountFile( ) throws IOException
	{
		this( "Accounts.dat" );
	}

	public RandomAccessAccountFile( String fileName ) throws IOException
	{
		this( fileName, "rw" );
	}

	public RandomAccessAccountFile( String fileName, String mode ) throws IOException
	{
		super( fileName, mode );
	}

	public void initializeRecords( ) throws IOException
	{
		RandomAccessAccountRecord record = new RandomAccessAccountRecord();

		for(int i = 0; i < RandomAccessAccountFile.MAX_RECORDS; i++)
		{
			record.write( this );
		}

	}

	public AccountRecord readRecord( int recordNumber ) throws IOException
	{
		if ( recordNumber < 0 || recordNumber > MAX_RECORDS) throw new IOException("Bad Record Number " + recordNumber );

		 // note the recordNumber starts 1 but offsets start at 0
		seek( (recordNumber - 1) * RandomAccessAccountRecord.SIZE );

		RandomAccessAccountRecord record = new RandomAccessAccountRecord( );
		record.read( this );
		return record;
	}

	public void writeRecord( AccountRecord record ) throws IOException
	{
            int recordNumber = record.getAccountNumber( );
            if ( recordNumber < 0 || recordNumber > MAX_RECORDS) throw new IOException("Bad Record Number" + recordNumber );
        	 // note the recordNumber starts 1 but offsets start at 0
            seek( (recordNumber - 1) * RandomAccessAccountRecord.SIZE );

            RandomAccessAccountRecord randomRecord = new RandomAccessAccountRecord( record );
            randomRecord.write( this );
	}
}