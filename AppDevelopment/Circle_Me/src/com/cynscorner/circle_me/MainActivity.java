package com.cynscorner.circle_me;

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
	private EditText inputNum;
    private TextView circumText;
    private TextView areaText;

	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		goButton = (Button)findViewById(R.id.goButton);
		inputNum = (EditText)findViewById(R.id.inputNum);
		circumText = (TextView)findViewById(R.id.circumText);
		areaText = (TextView)findViewById(R.id.areaText);
		
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
		// TODO Auto-generated method stub
		if(goButton == v)
		{
			String radiustr = inputNum.getText().toString();
			
			Circle circ = new Circle(Double.parseDouble(radiustr));
			
			String interim = "Circumference: " + circ.getCircum();			
			circumText.setText(interim);
			
			interim = "Area: " + circ.getArea();
			areaText.setText(interim);
			
		}		
		
	}

}
