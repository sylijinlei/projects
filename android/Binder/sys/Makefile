NAME=Led
SOURCE=/work/sources/android-5.0.2
all:
	cp I$(NAME)Service.aidl $(SOURCE)/frameworks/base/core/java/android/os/  # ILedService.aidl   接口生成文件
	@#修改 /frameworks/base/Android.mk      到/base目录下执行 mmm .

	cp $(NAME)Service.java $(SOURCE)/frameworks/base/services/core/java/com/android/server/       #LedService.java      接口实现类
	                         @#修改 /frameworks/base/services/java/com/android/server/SystemServer.java
	
	@# mmm /frameworks/base/services


