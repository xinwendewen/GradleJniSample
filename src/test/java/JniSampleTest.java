import org.junit.Assert;
import org.junit.Test;

public class JniSampleTest {
    JniSample jniSample = new JniSample();

    @Test
    public void create_counter() {
        Assert.assertTrue(jniSample.nativePointer != 0);
    }

    @Test
    public void set_get_int_value() {
        Assert.assertEquals(0, jniSample.getNativeIntValue());
        jniSample.setNativeIntValue(5);
        Assert.assertEquals(5, jniSample.getNativeIntValue());
    }

    @Test
    public void access_float_field_from_native() {
        Assert.assertEquals(0, Float.compare(jniSample.getFloatByNative(), 2.0F));
    }

    @Test
    public void access_string_field_from_native() {
        Assert.assertEquals(5, jniSample.sizeOfString());
    }
}