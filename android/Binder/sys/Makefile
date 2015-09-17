NAME=Led
SOURCE=/work/sources/android-5.0.2
all:
	cp I$(NAME)Service.aidl $(SOURCE)/frameworks/base/core/java/android/os/  # ILedService.aidl   接口生成文件
	@#修改 /frameworks/base/Android.mk      到/base目录下执行 mmm .

	cp $(NAME)Service.java $(SOURCE)/frameworks/base/services/core/java/com/android/server/       #LedService.java      接口实现类
	                         @#修改 /frameworks/base/services/java/com/android/server/SystemServer.java ,不需要修改Android.mk
	
	@# mmm /frameworks/base/services     编译LedService.java，生成Service 
	
	cp com_android_server_LedService.cpp  $(SOURCE)/frameworks/base/services/core/jni

	                        @#修改 /frameworks/base/services/core/jni下的onload.cpp
	                        @#修改 /frameworks/base/services/core/jni下的Android.mk
							@#执行mmm ./frameworks/base/service/core/jni


