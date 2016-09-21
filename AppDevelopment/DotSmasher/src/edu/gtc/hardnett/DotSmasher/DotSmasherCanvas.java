package edu.gtc.hardnett.DotSmasher;
import java.util.Random;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;

public class DotSmasherCanvas extends View implements OnTouchListener {

	// vars for the dot position
	private int dotX, dotY;

	// var for the player's score
	private int score;

	// paint for the dot
	private Paint dotPaint;

	public DotSmasherCanvas(Context context) {
		super(context);
		dotPaint = new Paint(); // create once and use many times
		moveDot(); // moves the dot to a random start position
		setOnTouchListener(this); // makes this class react to the screen
									// touches
	}

	public int getDotX() {
		return dotX;
	}

	public void setDotX(int dotX) {
		this.dotX = dotX;
	}

	public int getDotY() {
		return dotY;
	}

	public void setDotY(int dotY) {
		this.dotY = dotY;
	}

	public int getScore() {
		return score;
	}

	public void setScore(int score) {
		this.score = score;
	}

	/*
	 * This method is called to move the dot to a random start position
	 */
	protected void moveDot() {
		// crate two random numbers for the (x, y) position of the dot
		Random generator = new Random();
		generator.setSeed(System.currentTimeMillis());

		// constrain the position of the dot
		int w = getWidth() - 20;
		int h = getHeight() - 40;

		// randomly generate the (X, Y) position
		float f = generator.nextFloat();
		dotX = (int) (f * w) % w;
		f = generator.nextFloat();
		dotY = (int) (f * h) % h;
	}

	/*
	 * Determine if the touch is a hit on the dot
	 */
	protected boolean detectHit(int x, int y) {
		if ((x >= dotX && x <= dotX + 20) && (y >= dotY && y <= dotY + 20)) {
			// got a hit
			return true;
		}

		return false;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see android.view.View#onDraw(android.graphics.Canvas) When the screen
	 * needs to be redrawn this method is called by the system
	 */
	@Override
	protected void onDraw(Canvas canvas) {
		canvas.drawColor(Color.BLACK);
		dotPaint.setColor(Color.RED);
		canvas.drawRect(dotX, dotY, dotX + 20, dotY + 20, dotPaint);
		canvas.drawText("Score: " + score, 20, 20, dotPaint);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see android.view.View.OnTouchListener#onTouch(android.view.View,
	 * android.view.MotionEvent) This method is called when a touch on the
	 * screen happens
	 */
	@Override
	public boolean onTouch(View v, MotionEvent event) {
		if (detectHit((int) event.getX(), (int) event.getY())) {
			score += 1;
			invalidate();
		}
		return false;
	}

}
