package com.android.server;

import android.os.ILedService;
import android.util.Slog;
public class LedService extends ILedService.Stub {
    private static final String TAG = "LedService";
   /*call native c function to access hardware*/
   public LedService(){
		//native_ledOpen();
		 Slog.e(TAG, "LedService constructor called.");
   }
   public  int ledCtrl(int which, int status) throws android.os.RemoteException
   {
		 Slog.e(TAG, "LedService ledCtrl called.");
		//return native_ledCtrl(which, status);
		return 0;
   }
   //public native int native_ledCtrl(int which, int status);
   //public native int native_ledOpen();
   //public native void native_ledClose();
}


