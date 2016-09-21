package edu.gtc.hardnett.DotSmasher;

import java.util.TimerTask;

public class DotSmasherTimerTask extends TimerTask {
    
    DotSmasherCanvas canvas;
    
    public DotSmasherTimerTask(DotSmasherCanvas canvas) {
        this.canvas = canvas;
    }

   /* (non-Javadoc)
     * @see java.util.TimerTask#run()
     *
     */
    @Override
    public void run() {
        // TODO Auto-generated method stub
        canvas.moveDot();
        canvas.postInvalidate();
    }

}
