
#include <jni.h>  /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>

void c_sayhello()
{
    printf("I am in the c lib !\n");
__android_log_print(ANDROID_LOG_DEBUG, "HelloJni", "=====native say hello!\n");
}
static const JNINativeMethod methods[] = {
	{"sayhello", "()V", (void *)c_sayhello},
};

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	jclass cls;

	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
		return JNI_ERR; /* JNI version not supported */
	}
	cls = (*env)->FindClass(env, "com/jinlei/hellojni/Hello");
	if (cls == NULL) {
		return JNI_ERR;
	}

	/* 2. map java hello <-->c c_hello */
	if ((*env)->RegisterNatives(env, cls, methods, 1) < 0)
		return JNI_ERR;

	return JNI_VERSION_1_4;
}


