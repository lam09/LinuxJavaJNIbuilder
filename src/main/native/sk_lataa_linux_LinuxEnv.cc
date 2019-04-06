#include "sk_lataa_linux_LinuxEnv.h"
#include <stdlib.h>
#ifdef WINDOWS
#include <string>
#endif

struct JavaString {

    JNIEnv *m_env;
    jstring &m_val;
    const char *m_ptr;

    JavaString(JNIEnv *env, jstring val):
        m_env(env),
        m_val(val),
        m_ptr(env->GetStringUTFChars(val, 0)) {}

    ~JavaString() {
        m_env->ReleaseStringUTFChars(m_val, m_ptr);
    }

    operator const char*() const {
        return m_ptr;
    }

};

JNIEXPORT jint JNICALL Java_sk_lataa_linux_LinuxEnv_unsetJVMEnvironmentVariable (JNIEnv *env, jobject obj, jstring name) {
    JavaString namep(env, name);
    return unsetenv(namep);
}

JNIEXPORT jint JNICALL Java_sk_lataa_linux_LinuxEnv_setJVMEnvironmentVariable (JNIEnv *env, jobject obj, jstring name, jstring value, jint overwrite) {
    JavaString namep(env, name);
    JavaString valuep(env, value);
    return setenv(namep, valuep, overwrite);
}

JNIEXPORT jstring JNICALL Java_sk_lataa_linux_LinuxEnv_getJVMEnvironmentVariable (JNIEnv *env, jobject obj, jstring name) {
    JavaString namep(env, name);
    const char* val = getenv(namep);
    return env->NewStringUTF(val);
}