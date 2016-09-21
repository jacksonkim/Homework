package hardwarestore;

/*
	Hardware Store application
	RandomAccessToolFile class
	implements the toolID file limited to 100 records

*/
import java.io.*;

public class RandomAccessToolFile extends RandomAccessFile
{
    // limited to 100 records
    public static final int MAX_RECORDS = 100;

    public RandomAccessToolFile( ) throws IOException
    {
        this( "hardware.dat" );
    }

    public RandomAccessToolFile( String fileName ) throws IOException
    {
        this( fileName, "rw" );
    }

    public RandomAccessToolFile( String fileName, String mode ) throws IOException
    {
        super( fileName, mode );
    }

    public void initializeRecords( ) throws IOException
    {
        RandomAccessToolRecord record = new RandomAccessToolRecord();

        for(int i = 0; i < RandomAccessToolFile.MAX_RECORDS; i++)
        {
            record.write( this );
        }

    }

    public ToolRecord readRecord( int recordNumber ) throws IOException
    {
        if ( recordNumber < 0 || recordNumber > MAX_RECORDS) 
            throw new IOException("Bad Record Number " + recordNumber );

         // note the recordNumber starts 1 but offsets start at 0
        seek( (recordNumber - 1) * RandomAccessToolRecord.SIZE );

        RandomAccessToolRecord record = new RandomAccessToolRecord( );
        record.read( this );
        return record;
    }

    public void writeRecord( ToolRecord record ) throws IOException
    {
        int recordNumber = record.getToolID( );
        if ( recordNumber < 0 || recordNumber > MAX_RECORDS) 
            throw new IOException("Bad Record Number" + recordNumber );
             // note the recordNumber starts 1 but offsets start at 0
        seek( (recordNumber - 1) * RandomAccessToolRecord.SIZE );

        RandomAccessToolRecord randomRecord = new RandomAccessToolRecord( record );
        randomRecord.write( this );
    }
    
    public void deleteRecord( int recordNumber ) throws IOException
    {
        if ( recordNumber < 0 || recordNumber > MAX_RECORDS) 
            throw new IOException("Bad Record Number" + recordNumber );

         // note the recordNumber starts 1 but offsets start at 0
        seek( (recordNumber - 1) * RandomAccessToolRecord.SIZE );

        RandomAccessToolRecord randomTool = new RandomAccessToolRecord( );
        randomTool.write( this );
    }
}