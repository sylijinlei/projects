#include <jni.h>  /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>
#include <fcntl.h>
#include <sys/ioctl.h>

static jint fd;
#define Loge(...) __android_log_print(ANDROID_LOG_ERROR, "LEDDemo", __VA_ARGS__);
jint ledOpen(JNIEnv *env, jobject cls)
{
    fd = open("/dev/myled_dev", O_RDWR);
    /*__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledOpen : %d", fd);*/
    Loge("native ledOpen : %d", fd);
    if (fd >= 0)
        return 0;
    else
        return -1;
}

void ledClose(JNIEnv *env, jobject cls)
{
    /*__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledClose ...");*/
    Loge("native ledClose ... ");
    close(fd);
}

jint ledControl(JNIEnv *env, jobject cls, jint which, jint status)
{
    int ret = ioctl(fd, status, which);
    /*__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledCtrl : %d, %d, %d", which, status, ret);*/
    Loge("native ledCtrl : %d, %d ,%d",which ,status, ret);
    return ret;
}

static const JNINativeMethod methods[] = {
    {"native_ledOpen", "()I", (void *)ledOpen},
    {"native_ledClose", "()V", (void *)ledClose},
    {"native_ledControl", "(II)I", (void *)ledControl},
};

    JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
    JNIEnv *env;
    jclass cls;

    if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
        return JNI_ERR; /* JNI version not supported */
    }
    cls = (*env)->FindClass(env, "com/jinlei/hardcontrol/LedService");
    if (cls == NULL) {
        return JNI_ERR;
    }
    /* 2. map java hello <-->c c_hello */
    if ((*env)->RegisterNatives(env, cls, methods, sizeof(methods) / sizeof(JNINativeMethod) ) < 0)
        return JNI_ERR;

    return JNI_VERSION_1_4;
}


