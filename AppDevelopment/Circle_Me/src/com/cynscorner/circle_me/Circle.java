package com.cynscorner.circle_me;

public class Circle 
{

	private double radius;
	
	public Circle(double r)
	{
		radius = r;
	}
	
	public double getArea()
	{
		return 3.14*(radius*radius);
	}
	
	public double getCircum()
	{
		return 3.14*(radius*2);
	}

	public double getRadius() 
	{
		return radius;
	}

	public void setRadius(double radius) 
	{
		this.radius = radius;
	}
}
