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
	        //���������С  
	        paint.setTextSize(100);  
	          
	        //�û�����ͼ���ǿ��ĵ�  
	        paint.setStyle(Paint.Style.STROKE);  
	        //���û������ߵ� ��ϸ�̶�  
	        paint.setStrokeWidth(12);  
	        //����һ����  
	}
	public MyView(Context context,AttributeSet attrs){ 
	
	       super(context, attrs);  
	   	Log.e("MyView ","context attrs");
	       TypedArray array = context.obtainStyledAttributes(attrs, R.styleable.MyView); 

	        int textColor = array.getColor(R.styleable.MyView_textColor, 0XFF00FF00); //�ṩĬ��ֵ������δָ��   

	        float textSize = array.getDimension(R.styleable.MyView_textSize, 36);   

	  paint = new Paint();
			paint.setColor(textColor);   

	        paint.setTextSize(textSize);   

	        array.recycle(); //һ��Ҫ���ã�������ε��趨����´ε�ʹ�����Ӱ��   



	    } 


	
	@Override
	protected void onDraw(Canvas canvas)
	{
		// TODO Auto-generated method stub
		super.onDraw(canvas);
		c = canvas;
		Log.e("MyView ","onDraw");
        canvas.drawLine(0, 0, 200, 200, paint);  
              //������  
        canvas.drawRect(200, 200, 300, 300, paint); 
    
	}




}
