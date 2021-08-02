public class JniSample {
    static {
        System.loadLibrary("hello");
    }

    final long nativePointer;

    public JniSample() {
        nativePointer = createNativeObject();
    }

    private native long createNativeObject();

    void setNativeIntValue(int value) {
        nativeSetIntValue(nativePointer, value);
    }

    private native void nativeSetIntValue(long nativePointer, int value);

    int getNativeIntValue() {
        return nativeGetIntValue(nativePointer);
    }

    private native int nativeGetIntValue(long nativePointer);

    float floatValue = 2.0F;

    float getFloatByNative() {
        return nativeReadFloatField(nativePointer);
    }

    private native float nativeReadFloatField(long nativePointer);

    String string= "hello";

    int sizeOfString() {
        return nativeSizeOfString(nativePointer);
    }

    private native int nativeSizeOfString(long nativePointer);
}
