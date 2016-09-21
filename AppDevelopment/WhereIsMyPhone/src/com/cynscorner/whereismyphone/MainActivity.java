package com.cynscorner.whereismyphone;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.content.SharedPreferences.Editor;
import android.view.View.OnClickListener;
import android.widget.*;

public class MainActivity extends Activity implements OnClickListener 
{

    private Button start;
    private EditText pword;
    private EditText confirm;
    
    
    @Override
    protected void onCreate(Bundle savedInstanceState) 
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        start = (Button)findViewById(R.id.start);
        pword = (EditText)findViewById(R.id.pword);
        confirm = (EditText)findViewById(R.id.confirm);
        
        start.setOnClickListener(this);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) 
    {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public void onClick(View v) 
    {
        String pass = pword.getText().toString();
        String conf = confirm.getText().toString();
        
        // Check that user typed a password
        if (pass.length() == 0) 
        {
            Toast.makeText(this, "Please enter a Password", Toast.LENGTH_SHORT).show();
            pword.requestFocus();
            return;
        }
        
        // Make sure the two fields match
        if (pass.equals(conf)) 
        {
            Toast.makeText(this, "Passwords accepted", Toast.LENGTH_SHORT).show();

            // Fields match, store password in shared preferences
            Editor passwdFile = getSharedPreferences("passwd", 0).edit();
            passwdFile.putString("passwd", pass);
            passwdFile.commit();
            finish();
        } 
        else 
        { // password mismatch
            Toast.makeText(this, "Passwords must match", Toast.LENGTH_SHORT).show();
            pword.setText("");
            confirm.setText("");
            pword.requestFocus();
            return;
        }
        
    }
    
}