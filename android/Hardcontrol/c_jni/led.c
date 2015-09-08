
#include <jni.h>  /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdio.h>
#include <stdlib.h>
#include <log.h>
#include <fcntl.h>
#include <sys/ioctl.h>


static jint fd;

jint ledOpen(JNIEnv *env, jobject cls)
{
	fd = open("/dev/mychar_dev", O_RDWR);
	__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledOpen : %d", fd);
	if (fd >= 0)
		return 0;
	else
		return -1;
}

void ledClose(JNIEnv *env, jobject cls)
{
	__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledClose ...");
	close(fd);
}


jint ledControl(JNIEnv *env, jobject cls, jint led, jint status)
{
	int ret = ioctl(fd, status, led);
	__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledCtrl : %d, %d, %d", led, status, ret);
	return ret;
}


static const JNINativeMethod methods[] = {
	{"ledOpen", "()I", (void *)ledOpen},
	{"ledClose", "()V", (void *)ledClose},
	{"ledControl", "(II)I", (void *)ledControl},
};


JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	jclass cls;

	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
		return JNI_ERR; /* JNI version not supported */
	}
	cls = (*env)->FindClass(env, "com/jinlei/hardcontrol/Led");
	if (cls == NULL) {
		return JNI_ERR;
	}

	/* 2. map java hello <-->c c_hello */
	if ((*env)->RegisterNatives(env, cls, methods, sizeof(methods) / sizeof(JNINativeMethod) ) < 0)
		return JNI_ERR;

	return JNI_VERSION_1_4;
}


