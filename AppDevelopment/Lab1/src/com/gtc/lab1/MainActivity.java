package com.gtc.lab1;

import java.util.Calendar;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.*;
import android.view.View.OnClickListener;
 

public class MainActivity extends Activity implements OnClickListener
{
     
     // GUI Widgets
     private Button btn;
     private EditText edit;
     private TextView view;
     private TextView birthview;
     
 
    @Override
     protected void onCreate(Bundle savedInstanceState) 
    {                
         super.onCreate(savedInstanceState);
         setContentView(R.layout.activity_main);
         
         // create program objects that refer to GUI widgets
         edit = (EditText)findViewById(R.id.editText1);
         view = (TextView)findViewById(R.id.textView1);
         btn = (Button)findViewById(R.id.button1);
         birthview = (TextView)findViewById(R.id.editText2);
         
         // register the listener for the button
         btn.setOnClickListener(this);
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
         // Add code here to react to the event
         if (btn == v) 
         {
             int age = 0;
             int birthYear = 0;
             int currentYear = 0;
             String birthyearStr = birthview.getText().toString();
             
             birthYear = Integer.parseInt(birthyearStr);
             
             Calendar c = Calendar.getInstance(); 
            currentYear = c.get(Calendar.YEAR);
             
             age = currentYear - birthYear;
             
             String msg = "Welcome to Android, " + edit.getText() + "!" + " You will be " + String.valueOf(age) + " years old in 2014.";
             Toast toast = Toast.makeText(this, msg, Toast.LENGTH_SHORT);
             toast.show();
             view.setText(msg);
         }
     }
 
}
