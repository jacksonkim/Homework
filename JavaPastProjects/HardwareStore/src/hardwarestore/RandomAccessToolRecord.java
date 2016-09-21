package hardwarestore;

// Random Access toolID Record
// this class extends the toolIDRecord class
// so it can read and write fixed length records
// to a random access file for transaction processing

import java.io.*;

public class RandomAccessToolRecord extends ToolRecord
{
    // the length of a name
    private static final int NAME_LENGTH = 20;
    // the size of the record is determined by counting bytes
    // 4 bytes per integer
    // 8 bytes per double
    // 2 bytes per character in strings
    public static final int SIZE = 4 + 8 + NAME_LENGTH * 2 + NAME_LENGTH * 2;

    public RandomAccessToolRecord()
    {
        this(0, "", 0, 0.0);
    }

    public RandomAccessToolRecord(int toolID, String toolName, int quantity, double unitCost)
    {
        super(toolID, toolName, quantity, unitCost);
    }

    public RandomAccessToolRecord( ToolRecord data )
    {
        setToolID(data.getToolID());
        setToolName(data.getToolName());
        setToolQuantity(data.getToolQuantity());
        setToolUnitCost(data.getToolUnitCost());
    }

    // read an toolIDRecord from RandomAccessFile
    public void read(RandomAccessFile file) throws IOException
    {
        setToolID(file.readInt());
        setToolName( readName(file) );
        setToolQuantity( file.readInt() );
        setToolUnitCost( file.readDouble() );
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

    // write the toolIDRecord to RandomAccessFile
    public void write(RandomAccessFile file) throws IOException
    {
        file.writeInt( getToolID() );
        writeName( file, getToolName() );
        file.writeInt( getToolQuantity() );
        file.writeDouble( getToolUnitCost() );
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




