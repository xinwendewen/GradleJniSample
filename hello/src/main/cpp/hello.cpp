#include <jni.h>
#include <stdio.h>

class NativeClass {
    public:
        void SetIntMember(int value) {
           intMember_ = value;
        }
        const int ReadIntMember() const {
            return intMember_;
        }
    private:
        int intMember_;
};

extern "C"
JNIEXPORT jlong JNICALL
Java_JniSample_createNativeObject(JNIEnv *env) {
    NativeClass *p = new NativeClass();
    return reinterpret_cast<jlong>(p);
}

extern "C"
JNIEXPORT jint JNICALL
Java_JniSample_nativeGetIntValue(JNIEnv *env, jobject self, jlong pointer) {
    NativeClass *p = reinterpret_cast<NativeClass *>(pointer);
    return p->ReadIntMember();
}

extern "C"
JNIEXPORT void JNICALL
Java_JniSample_nativeSetIntValue(JNIEnv *env, jobject self, jlong pointer, jint value) {
    NativeClass *p = reinterpret_cast<NativeClass *>(pointer);
    p->SetIntMember(value);
}

extern "C"
JNIEXPORT float JNICALL
Java_JniSample_nativeReadFloatField(JNIEnv *env, jobject self, jlong pointer) {
    jclass cls = env->GetObjectClass(self);
    jfieldID fid = env->GetFieldID(cls, "floatValue", "F");
    jfloat value = env->GetFloatField(self, fid);
    return value;
}

extern "C"
JNIEXPORT float JNICALL
Java_JniSample_nativeSizeOfString(JNIEnv *env, jobject self, jlong pointer) {
    jclass cls = env->GetObjectClass(self);
    jfieldID fid = env->GetFieldID(cls, "string", "Ljava/lang/String;");
    jstring str = (jstring)env->GetObjectField(self, fid);
    return env->GetStringLength(str);
}

