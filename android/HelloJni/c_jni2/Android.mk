LOCAL_PATH := $(call my-dir)    #当前路径（如果你了解shell语言，应该可以很轻松的理解） 

include $(CLEAR_VARS)      #模块开始 
LOCAL_MODULE    := hello#要生成的.so库名 
LOCAL_SRC_FILES :=hello.c        #你的.c文件名字 
LOCAL_LDLIBS += -llog
TARGET_ARCH_ABI=armeabi-v7a
LOCAL_ARM_MODE=arm
LOCAL_ARM_NEON=false
include $(BUILD_SHARED_LIBRARY)  #模块结束 
