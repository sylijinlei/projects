
#include <jni.h>  /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>

jint c_sayhello(JNIEnv *env, jobject cls,jint a, jint b)
{
    printf("I am in the c lib !\n");
    __android_log_print(ANDROID_LOG_ERROR, "HelloJni", "=====native say hello!: a = %d, b = %d\n", a, b);
    return 0;
}
jstring c_printString(JNIEnv *env, jobject cls,jstring str)
{
    const jbyte *cstr;
    cstr = (*env)->GetStringUTFChars(env, str, NULL);
    if (cstr == NULL) {
        return NULL; /* OutOfMemoryError already thrown */
    }
    __android_log_print(ANDROID_LOG_ERROR, "HelloJni", "get string from java = %s\n",cstr);
    (*env)->ReleaseStringUTFChars(env, str, cstr);

    return (*env)->NewStringUTF(env, "return from c");

}
static const JNINativeMethod methods[] = {
    {"sayhello", "(II)I", (void *)c_sayhello},
    {"printString", "(Ljava/lang/String;)Ljava/lang/String;", (void *)c_printString},
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
    if ((*env)->RegisterNatives(env, cls, methods, sizeof(methods) / sizeof(JNINativeMethod)) < 0)
        return JNI_ERR;

    return JNI_VERSION_1_4;
}


