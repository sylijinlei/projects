package com.android.server;

import android.os.ILedService;




public class LedService extends ILeddService.Stub
        implements InputManager.InputDeviceListener {
    private static final String TAG = "LedService";
   /*call native c function to access hardware*/
   
   public  int ledCtrl(int which, int status) throws android.os.RemoteException
   {
		return native_ledCtrl(which, status);
   }
   public int native native_ledCtrl(int which, int status);
   public int native native_ledOpen();
   public void native native_ledClose();
}


