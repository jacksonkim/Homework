package edu.gtc.hardnett.DotSmasher;

import java.util.Timer;
import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
//import android.view.MenuItem;

public class MainActivity extends Activity {
    
    private Timer timer;
     private DotSmasherCanvas canvas;
     private DotSmasherTimerTask task;
     

    @Override
     protected void onCreate(Bundle savedInstanceState) {
         super.onCreate(savedInstanceState);
         // gets rid of the xml setup and leaves a blank screen
         //setContentView(R.layout.activity_main);  
        setTitle("dotSmasher");
         
        canvas = new DotSmasherCanvas(getBaseContext());
         timer = new Timer();
         task = new DotSmasherTimerTask(canvas);
         timer.schedule(task, 0, 1500);
         setContentView(canvas);
     }
 
    @Override
     public boolean onCreateOptionsMenu(Menu menu) {
         //MenuInflater inflater = getMenuInflater();
         // Inflate the menu; this adds items to the action bar if it is present.
         getMenuInflater().inflate(R.menu.main, menu);
         return true;
     }
     
    /*@Override
     public boolean onOptionsItemSelected(MenuItem item) {
         // Handle Item Selection
         switch (item.getItemId()) {
         case R.id.item1:
             newGame();
             return true;
         case R.id.item2:
             quit();
             return true;
         default:
             return super.onOptionsItemSelected(item);
         } 
        
    }
 
    private void quit() {
         timer.cancel();
         task = null;
         timer = null;
         canvas = null;
         finish();
     }
 
    private void newGame() {
         canvas.setScore(0);
     }*/
 
}
 
