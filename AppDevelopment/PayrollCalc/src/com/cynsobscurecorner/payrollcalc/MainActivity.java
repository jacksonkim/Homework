package com.cynsobscurecorner.payrollcalc;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity implements OnClickListener 
{
	
	private Button goButton;
	private EditText inputHours;
	private EditText inputPay;
	private TextView finalPay;

	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		inputHours = (EditText)findViewById(R.id.inputHours);
		inputPay = (EditText)findViewById(R.id.inputPay);
        finalPay = (TextView)findViewById(R.id.finalPay);
        goButton = (Button)findViewById(R.id.goButton);
        
        // register the listener for the button
        goButton.setOnClickListener(this);
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
		if(goButton == v)
		{
			String interim = inputHours.getText().toString();
			double hoursWorked = Double.parseDouble(interim);
			
			interim = inputPay.getText().toString();
			double payRate = Double.parseDouble(interim);
			
			double overtime = 0;
			
			double totalPay = 0;
			
			//i feel like there should be a caveat for payRate in case
			//someone puts in something less than minimum wage, but waitstaff get
			//less than minimum wage and thrive on tips. so... or if payRate is like
			//something ridiculous, but with the way CEOs get paid, who knows.
			//there are only 168 hours in a week, you see
			if (hoursWorked >= 168)
			{
				finalPay.setText("Nice try. There's only 168 hours in a week.\nIf anyone worked that, they'd be dead.");
				
			}
			else
			{
				do
				{
					if(hoursWorked > 40)
					{
						overtime = hoursWorked - 40;
						hoursWorked -= 40;
					}
				}while (hoursWorked > 40);
				
				totalPay = (hoursWorked*payRate)+((overtime*payRate)*1.5);
				
				interim = "Final Pay with Overtime: $" + totalPay;
				
				finalPay.setText(interim);
			}
			
		}
		
   }

}
