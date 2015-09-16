package com.jinlei.mycanvas;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import android.util.AttributeSet;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class MyView extends View
{

		static Paint paint;
		static Canvas c;
	public MyView(Context context)
	{
		super(context);
		// TODO Auto-generated constructor stub
		Log.e("MyView ","context ");
		paint = new Paint();  
	        paint.setColor(Color.RED);  
	        //设置字体大小  
	        paint.setTextSize(100);  
	          
	        //让画出的图形是空心的  
	        paint.setStyle(Paint.Style.STROKE);  
	        //设置画出的线的 粗细程度  
	        paint.setStrokeWidth(12);  
	        //画出一根线  
	}
	public MyView(Context context,AttributeSet attrs){ 
	
	       super(context, attrs);  
	   	Log.e("MyView ","context attrs");
	       TypedArray array = context.obtainStyledAttributes(attrs, R.styleable.MyView); 

	        int textColor = array.getColor(R.styleable.MyView_textColor, 0XFF00FF00); //提供默认值，放置未指定   

	        float textSize = array.getDimension(R.styleable.MyView_textSize, 36);   

	  paint = new Paint();
			paint.setColor(textColor);   

	        paint.setTextSize(textSize);   

	        array.recycle(); //一定要调用，否则这次的设定会对下次的使用造成影响   



	    } 


	
	@Override
	protected void onDraw(Canvas canvas)
	{
		// TODO Auto-generated method stub
		super.onDraw(canvas);
		c = canvas;
		Log.e("MyView ","onDraw");
        canvas.drawLine(0, 0, 200, 200, paint);  
              //画矩形  
        canvas.drawRect(200, 200, 300, 300, paint); 
    
	}




}
