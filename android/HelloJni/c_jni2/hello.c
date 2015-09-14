#include <jni.h>  /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>

#define Loge(...) __android_log_print(ANDROID_LOG_ERROR, "HelloJni", __VA_ARGS__);
JNIEXPORT jint Java_com_jinlei_hellojni_Hello_sayhello(JNIEnv *env, jobject cls,jint a, jint b)
{
    printf("I am in the c lib !\n");
    Loge("native: native say hello!: a = %d, b = %d\n", a, b);
    return 0;
}
JNIEXPORT jstring Java_com_jinlei_hellojni_Hello_printString(JNIEnv *env, jobject cls,jstring str)
{
    const jbyte *cstr;
    cstr = (*env)->GetStringUTFChars(env, str, NULL);
    if (cstr == NULL) {
        return NULL; /* OutOfMemoryError already thrown */
    }
    Loge("native: get string from java = %s\n",cstr);
    (*env)->ReleaseStringUTFChars(env, str, cstr);


    return (*env)->NewStringUTF(env, "return from c");

}

    JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
    JNIEnv *env;

    if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
        Loge("native: jni onload error!\n");
        return JNI_ERR; /* JNI version not supported */
    }
    Loge("native : jni onload success!\n");
    return JNI_VERSION_1_4;
}


