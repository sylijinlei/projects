#include <stdio.h>
#include <jni.h>
jint myhello(JNIEnv *env, jobject cls, jint i)
{
printf("hello = %d!\n", i);
return 333;
}

static const JNINativeMethod methods[] = {
	{"hello", "(I)I", (void *)myhello},

};

/* map java hello <---->  c_hello */
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	jclass cls;

	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
		return JNI_ERR; /* JNI version not supported */
	}
	cls = (*env)->FindClass(env, "JniTest");
	if (cls == NULL) {
		return JNI_ERR;
	}

	/* 2. map java hello <-->c c_hello */
	if ((*env)->RegisterNatives(env, cls, methods, 1) < 0)
		return JNI_ERR;

	return JNI_VERSION_1_4;
}
